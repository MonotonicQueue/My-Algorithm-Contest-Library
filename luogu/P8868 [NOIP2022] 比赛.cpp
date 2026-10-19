#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2.5e5+10;
int T,n,Q;
int a[N],b[N];
ull ans[N];
vector<pii> q[N];
struct Tag{
    ull taga,tagb;
    ull mula,mulb,mulab,tagp;
    bool work(){
        return taga || tagb || mula || mulb || mulab || tagp;
    }
}laz[N<<2];
struct Segment{
    ull suma,sumb,sumab,sump;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].suma = t[ls].suma+t[rs].suma;
    t[rt].sumb = t[ls].sumb+t[rs].sumb;
    t[rt].sumab = t[ls].sumab+t[rs].sumab;
    t[rt].sump = t[ls].sump+t[rs].sump;
}
void change(int rt,int l,int r,Tag d){
    if(laz[rt].taga && laz[rt].tagb){
        laz[rt].tagp += laz[rt].taga*laz[rt].tagb*d.mulab+laz[rt].taga*d.mula+laz[rt].tagb*d.mulb+d.tagp;
    }else if(laz[rt].taga){
        laz[rt].tagp += laz[rt].taga*d.mula+d.tagp;
        laz[rt].mulb += laz[rt].taga*d.mulab+d.mulb;
    }else if(laz[rt].tagb){
        laz[rt].tagp += laz[rt].tagb*d.mulb+d.tagp;
        laz[rt].mula += laz[rt].tagb*d.mulab+d.mula;
    }else{
        laz[rt].mula += d.mula;
        laz[rt].mulb += d.mulb;
        laz[rt].tagp += d.tagp;
        laz[rt].mulab += d.mulab;
    }
    if(d.taga) laz[rt].taga = d.taga;
    if(d.tagb) laz[rt].tagb = d.tagb;
    ull len = r-l+1;
    t[rt].sump += d.mulab*t[rt].sumab+d.mula*t[rt].suma+d.mulb*t[rt].sumb+d.tagp*len;
    if(d.taga && d.tagb){
        t[rt].sumab = len*d.taga*d.tagb;
        t[rt].suma = len*d.taga;
        t[rt].sumb = len*d.tagb;
    }else if(d.taga){
        t[rt].sumab = d.taga*t[rt].sumb;
        t[rt].suma = d.taga*len;
    }else if(d.tagb){
        t[rt].sumab = d.tagb*t[rt].suma;
        t[rt].sumb = d.tagb*len;
    }
}
void push_down(int rt,int l,int r){
    if(laz[rt].work()){
        int mid = (l+r) >> 1;
        change(ls,l,mid,laz[rt]);
        change(rs,mid+1,r,laz[rt]);
        laz[rt] = Tag{0,0,0,0,0,0};
    }
}
void update(int rt,int l,int r,int ql,int qr,Tag d){
    if(ql <= l && r <= qr) return change(rt,l,r,d);
    push_down(rt,l,r);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ull query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].sump;
    push_down(rt,l,r);
    int mid = (l+r) >> 1; ull res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
int stka[N],topa,stkb[N],topb;
signed main(){
    T = read(); n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    Q = read();
    for(int i=1;i<=Q;i++){
        int l = read(),r = read();
        q[r].push_back(mk(l,i));
    }
    for(int i=1;i<=n;i++){
        while(topa && a[i] > a[stka[topa]]) topa--;
        update(1,1,n,stka[topa]+1,i,Tag{(ull)a[i],0,0,0,0,0});
        while(topb && b[i] > b[stkb[topb]]) topb--;
        update(1,1,n,stkb[topb]+1,i,Tag{0,(ull)b[i],0,0,0,0});
        update(1,1,n,1,i,Tag{0,0,0,0,1,0});
        for(auto it : q[i])
            ans[it.se] = query(1,1,n,it.fi,i);
        stka[++topa] = i; stkb[++topb] = i;
    }
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
    return 0;
}
