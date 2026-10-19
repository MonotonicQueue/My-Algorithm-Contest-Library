#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 50010;
int n;
vector<int> G[N];
int son[N],sson[N],fa[N],dep[N];
ll w[N],siz[N],f[N];
void dfs0(int x,int ft){
	siz[x] = w[x]; dep[x] = dep[ft]+1;
	fa[x] = ft;
	for(int y : G[x]){
		if(y == fa[x]) continue;
		dfs0(y,x);
		siz[x] += siz[y];
		f[x] += f[y]+siz[y];
		if(siz[y] > siz[son[x]]) sson[x] = son[x],son[x] = y;
		else if(siz[y] > siz[sson[x]]) sson[x] = y;
	}
}
ll ans = 1e18;
int T;
ll dfs2(int x,ll sum,ll now){
	if(son[x] != T && 2*siz[son[x]] > sum) return dfs2(son[x],sum,now+sum-2*siz[son[x]]);
	if(2*siz[sson[x]] > sum) return dfs2(sson[x],sum,now+sum-2*siz[sson[x]]);
	return now;
}
void dfs1(int x,int ft){
	for(int y : G[x]){
		if(y == ft) continue;
		int u = x;
		while(u){
			siz[u] -= siz[y];
			f[u] -= (dep[y]-dep[u])*siz[y]+f[y];
			u = fa[u];
		}
		T = y;
		ans = min(ans,dfs2(1,siz[1],f[1])+dfs2(y,siz[y],f[y]));
		u = x;
		while(u){
			siz[u] += siz[y];
			f[u] += (dep[y]-dep[u])*siz[y]+f[y];
			u = fa[u];
		}
		dfs1(y,x);
	}
}
int main(){
	n = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) w[i] = read();
	dfs0(1,0);
	dfs1(1,0);
	cout << ans;
    return 0;
}
