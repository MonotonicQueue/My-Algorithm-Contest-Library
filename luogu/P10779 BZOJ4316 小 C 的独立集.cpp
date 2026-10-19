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
const int N = 5e5+10;
int n,m,dfn[N],low[N],tot,fa[N];
ll a[N],f[N][2],g[N][2];
vector<int> G[N];
void tarjan(int x,int ft){
	fa[x] = ft;
	low[x] = dfn[x] = ++tot;
	f[x][1] = a[x]; f[x][0] = 0;
	for(int y : G[x]){
		if(y == ft) continue;
		if(!dfn[y]){
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
		}else low[x] = min(low[x],dfn[y]);
		if(low[y] > dfn[x]){
			f[x][1] += f[y][0];
			f[x][0] += max(f[y][1],f[y][0]);
		}
	}
	auto work = [&](int x,int rt){
		ll f0 = f[x][0],f1 = f[x][1];
		for(int y=fa[x];y!=rt;y=fa[y]){
			ll g0 = max(f0,f1)+f[y][0],g1 = f0+f[y][1];
			f0 = g0, f1 = g1;
		}
		f[rt][0] += max(f0,f1);
		f0 = f[x][0]; f1 = -1e18;
		for(int y=fa[x];y!=rt;y=fa[y]){
			ll g0 = max(f0,f1)+f[y][0],g1 = f0+f[y][1];
			f0 = g0, f1 = g1;
		}
		f[rt][1] += f0;
	};
	for(int y : G[x])
		if(low[y] == dfn[x] && fa[y] != x)
			work(y,x);
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = 1;
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
		if(!dfn[i]){
			tarjan(i,0);
			ans += max(f[i][0],f[i][1]);
		}
	cout << ans;
	return 0;
}
/*
5 5
1 1 1 1 1
1 2
2 3
3 4
4 5
1 5
*/