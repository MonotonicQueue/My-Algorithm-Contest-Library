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
const int inf = 1e9;
int n,m,q,fa[N],cnt,val[N];
vector<int> G[N];
inline void clear(){
    for(int i=1;i<=2*n;i++) G[i].clear();
    for(int i=1;i<=2*n;i++) fa[i] = i;
    for(int i=1;i<=n;i++) val[i] = 0;
}
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int ft[N][20],dep[N];
int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=19;~i;i--)
        if(dep[ft[x][i]] >= dep[y]) x = ft[x][i];
    if(x == y) return x;
    for(int i=19;~i;i--)
        if(ft[x][i] != ft[y][i]) x = ft[x][i],y = ft[y][i];
    return ft[x][0];
}
int dfn[N],tot;
void dfs(int x){
    // cout << x << "\n";
    dfn[x] = ++tot;
    for(int i=1;i<=18;i++) ft[x][i] = ft[ft[x][i-1]][i-1];
    for(int y : G[x]){
        ft[y][0] = x;
        dep[y] = dep[x]+1;
        dfs(y);
    }
}
pii mx[N<<2],mn[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    mx[rt] = max(mx[ls],mx[rs]);
    mn[rt] = min(mn[ls],mn[rs]);
}
void build(int rt,int l,int r){
    if(l == r){
        mx[rt] = mn[rt] = mk(dfn[l],l);
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
pii query_mn(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return mn[rt];
    int mid = (l+r) >> 1; pii res = mk(inf,inf);
    if(ql <= mid) res = min(res,query_mn(ls,l,mid,ql,qr));
    if(qr >  mid) res = min(res,query_mn(rs,mid+1,r,ql,qr));
    return res;
}
pii query_mx(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return mx[rt];
    int mid = (l+r) >> 1; pii res = mk(0,0);
    if(ql <= mid) res = max(res,query_mx(ls,l,mid,ql,qr));
    if(qr >  mid) res = max(res,query_mx(rs,mid+1,r,ql,qr));
    return res;
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read(); q = read();
        clear();
        cnt = n;
        for(int i=1;i<=m;i++){
            int u = read(),v = read();
            u = get(u); v = get(v);
            // cout << u << " " << v << "\n";
            if(u == v) continue;
            fa[u] = fa[v] = ++cnt;
            val[cnt] = i;
            G[cnt].push_back(u);
            G[cnt].push_back(v);
        }
        dep[cnt] = 1; ft[cnt][0] = 0; tot = 0;
        dfs(cnt);
        build(1,1,n);
        while(q--){
            int l = read(),r = read();
            int x = query_mn(1,1,n,l,r).se,y = query_mx(1,1,n,l,r).se;
            printf("%d ",val[lca(x,y)]);
        }
        printf("\n");
    }

    return 0;
}