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
const int N = 2e5+10;
int n,m,Q;
int ans[N],vis[N];
vector<int> G[N];
vector<pii> q[N];
int main(){
	n = read(); m = read(); Q = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=Q;i++){
		int x = read(),y = read();
		ans[i] = G[x].size();
		if(G[x].size() < G[y].size()) swap(x,y);
		q[x].push_back(mk(y,i));
	}
	for(int i=1;i<=n;i++){
		sort(q[i].begin(),q[i].end());
		for(int y : G[i]) vis[y] = i;
		int lstans = 0,lst = 0;
		for(auto it : q[i]){
			int x = it.fi,id = it.se;
			if(x == lst){
				ans[id] -= lstans;
				continue;
			}
			lst = x;
			lstans = (vis[x] == i);
			for(int y : G[x]) lstans += (vis[y] == i);
			ans[id] -= lstans;
		}
	}
	for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
    return 0;
}
