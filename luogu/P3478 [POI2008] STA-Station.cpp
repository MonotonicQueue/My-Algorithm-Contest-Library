#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n;
vector<int> G[N];
ll f[N],g[N],dep[N],siz[N];
void dfs1(int x,int fa){
	dep[x] = dep[fa]+1;
	f[x] = dep[x];
	siz[x] = 1;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs1(y,x);
		f[x] += f[y];
		siz[x] += siz[y];
	}
}
void dfs2(int x,int fa){
	for(int y : G[x]){
		if(y == fa) continue;
		g[y] = g[x]+n-2*siz[y];
		dfs2(y,x);
	}
}
int main(){
	n = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);
	g[1] = f[1];
	dfs2(1,0);
	int ans = 1;
	for(int i=2;i<=n;i++)
		if(g[i] > g[ans]) ans = i;
	cout << ans;
    return 0;
}
