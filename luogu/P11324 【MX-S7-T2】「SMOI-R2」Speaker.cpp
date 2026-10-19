#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
int n,q,fa[N][20];
ll c[N],f[N],mx[N][20],dis[N],dep[N];
vector<pii> G[N];
void dfs1(int x,int ft){
    fa[x][0] = ft;
    f[x] = c[x];
    dep[x] = dep[ft]+1;
    for(auto [y,w] : G[x]){
        if(y == ft) continue;
        dis[y] = dis[x]+w;
        dfs1(y,x);
        f[x] = max(f[x],f[y]-2*w);
    }
}
void dfs2(int x,int ft){
    mx[x][0] = f[ft];
    for(int i=1;i<=19;i++){
        fa[x][i] = fa[fa[x][i-1]][i-1];
        mx[x][i] = max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
    }
    for(auto [y,w] : G[x]){
        if(y == ft) continue;
        f[y] = max(f[y],f[x]-2*w);
        dfs2(y,x);
    }
}
pair<int,ll> get(int u,int v){
    ll res = max(f[u],f[v]);
    if(dep[u] < dep[v]) swap(u,v);
    for(int i=19;~i;i--)
        if(dep[fa[u][i]] >= dep[v]) res = max(res,mx[u][i]),u = fa[u][i];
    if(u == v) return mk(u,res);
    for(int i=19;~i;i--)
        if(fa[u][i] != fa[v][i]) res = max(res,max(mx[u][i],mx[v][i])),u = fa[u][i],v = fa[v][i];
    res = max(res,mx[u][0]);
    return mk(fa[u][0],res);
}
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=n;i++) c[i] = read();
    for(int i=2;i<=n;i++){
        int u = read(),v = read(),w = read();
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs1(1,0); dfs2(1,0);
    while(q--){
        int u = read(),v = read();
        auto [d,w] = get(u,v);
        cout << w+c[u]+c[v]-(dis[u]+dis[v]-2*dis[d]) << "\n";
    }
}
int main(){
    // freopen("speaker.in","r",stdin);
    // freopen("speaker.out","w",stdout);
    int T = 1;
    while(T--) solve();
	return 0;
}
