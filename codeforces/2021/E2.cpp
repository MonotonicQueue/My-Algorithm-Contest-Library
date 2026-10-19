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
const int N = 10010;
const int M = 5010;
const ll inf = 1e18;
int n,m,p,fa[N],cnt;
vector<int> G[N];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
struct Edge{int u,v,w;}e[M];
int s[N];
bool vis[N];
int siz[N];
ll val[N];
void clear(){
    cnt = n;
    for(int i=1;i<=2*n;i++) G[i].clear();
    for(int i=1;i<=2*n;i++) fa[i] = i,val[i] = vis[i] = 0;
}
void dfs0(int x){
    siz[x] = vis[x];
    for(int y : G[x]){
        dfs0(y);
        siz[x] += siz[y];
    }
}
vector<ll> f[N];
void dfs(int x){
    f[x].resize(siz[x]+1);
    f[x][0] = 0;
    for(int i=1;i<=siz[x];i++) f[x][i] = inf;
    siz[x] = vis[x];
    for(int y : G[x]){
        dfs(y);
        vector<ll> g(siz[x]+siz[y]+1,inf);
        g[0] = 0;
        for(int i=0;i<=siz[x];i++)
            for(int j=0;j<=siz[y];j++){
                if(i == 0 && j == 0) continue;
                ll w = 0;
                if(j == 0) w = 1ll*val[x]*siz[y];
                if(i == 0) w = 1ll*val[x]*siz[x];
                g[i+j] = min(g[i+j],f[x][i]+f[y][j]+w);
            }
        siz[x] += siz[y];
        for(int i=1;i<=siz[x];i++) f[x][i] = g[i];
    }
    f[x][1] = min(f[x][1],1ll*siz[x]*val[x]);
}
void solve(){
    n = read(); m = read(); p = read();
    clear();
    for(int i=1;i<=p;i++) s[i] = read(),vis[s[i]] = true;
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].w = read();
    }
    sort(e+1,e+1+m,[](Edge x,Edge y){return x.w < y.w;});
    for(int i=1;i<=m;i++){
        int x = e[i].u,y = e[i].v;
        x = get(x); y = get(y);
        if(x == y) continue;
        val[++cnt] = e[i].w;
        fa[x] = fa[y] = cnt;
        G[cnt].push_back(x); G[cnt].push_back(y);
    }
    dfs0(cnt);
    dfs(cnt);
    f[cnt].resize(n+1);
    for(int i=2;i<=n;i++) f[cnt][i] = min(f[cnt][i],f[cnt][i-1]);
    for(int i=1;i<=n;i++) cout << f[cnt][i] << " ";
    cout << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
