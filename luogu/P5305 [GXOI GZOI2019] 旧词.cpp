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
const int N = 5e4+10;
const int mod = 998244353;
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
int n,m,k,fa[N];
vector<int> G[N];
struct Ques{
    int x,z,id;
}q[N];
bool cmp(Ques x,Ques y){
    return x.x < y.x;
}
int siz[N],son[N],dep[N];
int top[N],dfn[N],cnt,raw[N];
void dfs1(int x){
    siz[x] = 1;
    for(int y : G[x]){
        dep[y] = dep[x]+1;
        dfs1(y);
        siz[x] += siz[y];
        if(siz[y] > siz[son[x]]) son[x] = y;
    }
}
void dfs2(int x,int topx){
    top[x] = topx;
    dfn[x] = ++cnt;
    raw[cnt] = x;
    if(!son[x]) return ;
    dfs2(son[x],topx);
    for(int y : G[x])
        if(y != son[x]) dfs2(y,y);
}
ll t[N<<2],tag[N<<2],sum[N<<2],a[N];
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
    if(l == r){
        sum[rt] = a[raw[l]];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    sum[rt] = (sum[ls]+sum[rs])%mod;
}
inline void push_up(int rt){
    t[rt] = (t[ls]+t[rs])%mod;
}
inline void change(int rt,int l,int r,ll d){
    t[rt] = (t[rt]+sum[rt]*d)%mod;
    tag[rt] = (tag[rt]+d)%mod;
}
void push_down(int rt,int l,int r){
    if(tag[rt]){
        int mid = (l+r) >> 1;
        change(ls,l,mid,tag[rt]);
        change(rs,mid+1,r,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr) return change(rt,l,r,d);
    int mid = (l+r) >> 1;
    push_down(rt,l,r);
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    push_down(rt,l,r);
    int mid = (l+r) >> 1; ll res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res%mod;
}
void update_range(int x){
    while(x){
        update(1,1,n,dfn[top[x]],dfn[x],1);
        x = fa[top[x]];
    }
}
ll query_range(int x){
    ll res = 0;
    while(x){
        res = (res+query(1,1,n,dfn[top[x]],dfn[x]))%mod;
        x = fa[top[x]];
    }
    return res;
}
ll ans[N];
int main(){
    n = read(); m = read(); k = read();
    for(int i=2;i<=n;i++){
        fa[i] = read();
        G[fa[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int x = read(),y = read();
        q[i] = Ques{x,y,i};
    }
    dep[1] = 1;
    sort(q+1,q+1+m,cmp);
    dfs1(1); 
    dfs2(1,1);
    for(int i=1;i<=n;i++) a[i] = (fpow(dep[i],k)-fpow(dep[i]-1,k)+mod)%mod;
    build(1,1,n);
    for(int i=1,j=1;i<=n;i++){
        update_range(i);
        while(j <= m && q[j].x <= i){
            ans[q[j].id] = query_range(q[j].z);
            j++;
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
    return 0;
}