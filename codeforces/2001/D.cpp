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
const int N = 3e5+10;
int n,a[N],b[N];
struct Segment{
    int mx,mn,sum,tag;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
Segment merge(Segment x,Segment y){
    Segment res = {0,0,0,0};
    if(x.sum < y.sum) res = y;
    else if(x.sum > y.sum) res = x;
    else{
        res.sum = x.sum;
        if(a[x.mn] <= a[y.mn]) res.mn = x.mn;
        else res.mn = y.mn;
        if(a[x.mx] < a[y.mx]) res.mx = y.mx;
        else res.mx = x.mx;
    }
    res.tag = 0;
    return res;
}
void build(int rt,int l,int r){
    t[rt].tag = 0;
    if(l == r){
        t[rt].sum = b[l];
        t[rt].mn = t[rt].mx = l;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[rt] = merge(t[ls],t[rs]);
}
void change(int rt,int d){
    t[rt].sum += d;
    t[rt].tag += d;
}
void push_down(int rt){
    if(t[rt].tag){
        change(ls,t[rt].tag);
        change(rs,t[rt].tag);
        t[rt].tag = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        change(rt,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    t[rt] = merge(t[ls],t[rs]);
}
Segment query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    push_down(rt);
    int mid = (l+r) >> 1;
    if(qr <= mid) return query(ls,l,mid,ql,qr);
    if(ql >  mid) return query(rs,mid+1,r,ql,qr);
    return merge(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
void del(int rt,int l,int r,int pos){
    if(l == r){
        t[rt].sum = -114514;
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(pos <= mid) del(ls,l,mid,pos);
    else del(rs,mid+1,r,pos);
    t[rt] = merge(t[ls],t[rs]);
}
int cnt[N],lst[N],ans[N],tot;
vector<int> pos[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) cnt[i] = lst[i] = 0,pos[i].clear();
    int s = 0;
    for(int i=n;i;i--){
        cnt[a[i]]++; pos[a[i]].push_back(i);
        if(cnt[a[i]] == 1) s++,lst[a[i]] = i;
        b[i] = s;
    }
    build(1,1,n);
    tot = 0;
    for(int i=1,x=1;i<=s;i++){
        Segment res = query(1,1,n,x,n);
        if(i & 1){
            ans[++tot] = a[res.mx];
            x = res.mx;
            update(1,1,n,x,lst[a[res.mx]],-1);
            
        }else{
            ans[++tot] = a[res.mn];
            x = res.mn;
            update(1,1,n,x,lst[a[res.mn]],-1);
        }
        for(int y : pos[a[x]]) del(1,1,n,y);
    }
    cout << tot << "\n";
    for(int i=1;i<=tot;i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
7
1 2 1 3 2 4 6
*/