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
const int N = 2e5+10;
const int inf = 1e9+1;
int n,Q;
struct node{
    int h,a,b;
}a[N];
vector<pii> q[N],v[N];
int ans[N];
struct Segment{
    int val,mx,tag;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].val = max(t[ls].val,t[rs].val);
    t[rt].mx = max(t[ls].mx,t[rs].mx);
}
void build(int rt,int l,int r){
    t[rt].mx = t[rt].tag = t[rt].val = -inf;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
inline void change(int rt,int tag){
    t[rt].tag = max(t[rt].tag,tag);
    t[rt].mx = max(t[rt].mx,t[rt].val+tag);
}
void push_down(int rt){
    if(t[rt].tag != -inf){
        change(ls,t[rt].tag);
        change(rs,t[rt].tag);
        t[rt].tag = -inf;
    }
}
void update1(int rt,int l,int r,int pos,int d){
    if(l == r){
        t[rt].val = d;
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(pos <= mid) update1(ls,l,mid,pos,d);
    else update1(rs,mid+1,r,pos,d);
    push_up(rt);
}
void update2(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        change(rt,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update2(ls,l,mid,ql,qr,d);
    if(qr >  mid) update2(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].mx;
    push_down(rt);
    int mid = (l+r) >> 1,res = -1;
    if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
    if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
    return res;
}
void solve(){
    build(1,1,n);
    for(int i=1;i<=n;i++){
        for(auto it : v[i]){
            if(it.se == 1) update1(1,1,n,it.fi,a[it.fi].h);
            else update1(1,1,n,it.fi,-inf);
        }
        if(i-a[i].a >= 1) update2(1,1,n,max(i-a[i].b,1),i-a[i].a,-a[i].h);
        for(auto it : q[i]){
            ans[it.se] = max(ans[it.se],query(1,1,n,it.fi,i));
        }
    }
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i].h = read();
        a[i].a = read(); a[i].b = read();
        if(i+a[i].a <= n) v[i+a[i].a].push_back(mk(i,1));
        if(i+a[i].b+1 <= n) v[i+a[i].b+1].push_back(mk(i,-1));
    }
    memset(ans,-1,sizeof(ans));
    Q = read();
    for(int i=1;i<=Q;i++){
        int l = read(),r = read();
        q[r].push_back(mk(l,i));
    }
    solve();
    for(int i=1;i<=n;i++) a[i].h = -a[i].h;
    solve();
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
    return 0;
}
/*
5
10 2 4
1 1 1
2 1 3
1 1 1
100 1 1
5
1 2
2 3
1 3
1 4
1 5
*/