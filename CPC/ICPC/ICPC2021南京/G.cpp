#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 160;
const ll inf = 1e18;
int n,a[N];
vector<int> G[N];
ll f[N][N][N][2][2];
int fa[N][N],siz[N][N];
void dfs0(int rt,int x,int ft){
	fa[rt][x] = ft; siz[rt][x] = 1;
	for(int y : G[x]){
		if(y == ft) continue;
		dfs0(rt,y,x);
		siz[rt][x] += siz[rt][y];
	}
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n+1;i++) G[i].clear();
	for(int i=1;i<=n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n+1;i++) dfs0(i,i,0);
	for(int i=1;i<=n+1;i++){
		
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
