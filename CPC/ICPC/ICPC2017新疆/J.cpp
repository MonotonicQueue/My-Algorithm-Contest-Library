#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 100100;
int n,Q;
vector<int> G[N];
ll a[N],f[N],g[N];
int fa[N][20],dep[N];
int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=18;~i;i--)
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i=18;~i;i--)
        if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
    return fa[x][0];
}
void dfs0(int x,int ft){
    dep[x] = dep[ft]+1;
    fa[x][0] = ft;
    for(int i=1;i<=18;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    for(int y : G[x]){
        if(y == ft) continue;
        dfs0(y,x);
    }
}
void dfs1(int x,int ft){
    for(int y : G[x]){
        if(y == ft) continue;
        dfs1(y,x);
        a[x] += a[y];
    }
}
void dfs2(int x,int ft){
    for(int y : G[x]){
        if(y == ft) continue;
        f[y] = f[x]+a[y]*(y-x);
        dfs2(y,x);
    }
}
void solve(){
    n = read(); Q = read();
    for(int i=1;i<=n;i++){
        a[i] = f[i] = 0;
        G[i].clear();
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1,0);
    while(Q--){
        int u = read(),v = read();
        a[u]++; a[v]++;
        int d = lca(u,v);
        f[1] += d;
        a[d] -= 2;
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout << f[i] << " ";
    cout << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}