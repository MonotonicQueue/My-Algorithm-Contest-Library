#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int inf = 1e9;
int n,deg[N];
vector<int> G[N];
int f[N];
void dp(int x,int fa){
	if(deg[x] <= 2) f[x] = x;
	else f[x] = inf;
	for(int y : G[x]){
		if(y == fa) continue;
		dp(y,x);
		f[x] = min(f[x],f[y]);
	}
}
void dfs(int x,int fa,int type){
	if(type == 0){
		cout << x << " ";
		int dg = deg[x]-(fa > 0);
		if(dg == 2){
			int u = 0,v = 0;
			for(int y : G[x]){
				if(y == fa) continue;
				if(!u) u = y;
				else v = y;
			}
			if(f[u] < f[v]){
				dfs(u,x,1);
				dfs(v,x,0);
			}else{
				dfs(v,x,1);
				dfs(u,x,0);
			}
		}else if(dg == 1){
			int u = 0;
			for(int y : G[x]){
				if(y == fa) continue;
				if(!u) u = y;
			}
			if(u < f[u]) dfs(u,x,0);
			else dfs(u,x,1);
		}
	}else{
		int dg = deg[x]-(fa > 0);
		if(dg == 2){
			int u = 0,v = 0;
			for(int y : G[x]){
				if(y == fa) continue;
				if(!u) u = y;
				else v = y;
			}
			if(f[u] < f[v]){
				dfs(u,x,1);
				cout << x << " ";
				dfs(v,x,1);
			}else{
				dfs(v,x,1);
				cout << x << " ";
				dfs(u,x,1);
			}
		}else if(dg == 1){
			int u = 0;
			for(int y : G[x]){
				if(y == fa) continue;
				if(!u) u = y;
			}
			if(f[x] == x){
				cout << x << " ";
				dfs(u,x,1);
			}else{
				dfs(u,x,1);
				cout << x << " ";
			}
		}else cout << x << " ";
	}
}
int main(){
	n = read();
	int rt = 0;
	for(int i=1;i<=n;i++){
		deg[i] = read();
		for(int j=1;j<=deg[i];j++){
			int x = read();
			G[i].push_back(x);
		}
		if(deg[i] <= 2 && !rt) rt = i;
	}
	dp(rt,0);
	dfs(rt,0,0);
	return 0;
}
