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
const int N = 1e5+10;
int n,m;
vector<int> G[N];
int dep[N],fa[N][20],dfn[N],Dfn,raw[N];
void dfs(int x,int ft){
    dfn[x] = ++Dfn; raw[Dfn] = x;
    fa[x][0] = ft;  dep[x] = dep[ft]+1;
    for(int i=1;i<=18;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    for(int y : G[x])
        if(y != ft) dfs(y,x);
}
int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=18;~i;i--)
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i=18;~i;i--)
        if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
    return fa[x][0];
}
int root[N],cnt;
struct Segment{
    int ls,rs;
    int val,s,t,vis;
}t[N<<6];
#define lc t[rt].ls
#define rc t[rt].rs
inline void push_up(int rt){
    t[rt].val = t[lc].val+t[rc].val-dep[lca(t[lc].t,t[rc].s)];
    t[rt].s = t[lc].s ? t[lc].s : t[rc].s;
    t[rt].t = t[rc].t ? t[rc].t : t[lc].t;
}
int query(int rt){
    return t[rt].val-dep[lca(t[rt].s,t[rt].t)];
}
void update(int &rt,int l,int r,int pos,int d){
    if(!rt) rt = ++cnt;
    if(l == r){
        t[rt].vis += d;
        t[rt].val = t[rt].vis ? dep[raw[l]] : 0;
        t[rt].s = t[rt].t = t[rt].vis ? raw[l] : 0;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) update(lc,l,mid,pos,d);
    else           update(rc,mid+1,r,pos,d);
    push_up(rt);
}
int merge(int u,int v,int l,int r){
    if(!u || !v) return u+v;
    if(l == r){
        t[u].vis += t[v].vis;
        t[u].val = t[u].vis ? dep[raw[l]] : 0;
        t[u].s = t[u].t = t[u].vis ? raw[l] : 0;
        return u;
    }
    int mid = (l+r)>>1;
    t[u].ls = merge(t[u].ls,t[v].ls,l,mid);
    t[u].rs = merge(t[u].rs,t[v].rs,mid+1,r);
    push_up(u);
    return u;
}
ll ans;
void solve(int x){
    for(int y : G[x])
        if(y != fa[x][0]) solve(y);
    for(int y : G[x])
        if(y != fa[x][0]) root[x] = merge(root[x],root[y],1,n);
    ans += query(root[x]);
}
int main(){
    n = read(); m = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        int s = read(),t = read();
        int d = fa[lca(s,t)][0];
        update(root[s],1,n,dfn[s],1); update(root[s],1,n,dfn[t],1);
        update(root[t],1,n,dfn[s],1); update(root[t],1,n,dfn[t],1);
        if(d) update(root[d],1,n,dfn[s],-2),update(root[d],1,n,dfn[t],-2);
    }
    solve(1);
    cout << ans/2;
	return 0;
}
