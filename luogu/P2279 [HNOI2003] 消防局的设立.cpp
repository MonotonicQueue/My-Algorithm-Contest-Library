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
const int N = 1010;
int n,fa[N],dep[N];
vector<int> G[N];
bool vis[N];
priority_queue<pii> q;
void dfs(int x){
	q.push(mk(dep[x],x));
	for(int y : G[x]){
		if(y == fa[x]) continue;
		dep[y] = dep[x]+1;
		dfs(y);
	}
}
void dfs0(int x,int d){
	vis[x] = true;
	if(d == 2) return ;
	for(int y : G[x]){
		dfs0(y,d+1);
	}
}
int main(){
	n = read();
	for(int i=2;i<=n;i++){
		fa[i] = read();
		G[fa[i]].push_back(i);
		G[i].push_back(fa[i]);
	}
	dep[1] = 1; dfs(1);
	int ans = 0;
	while(!q.empty()){
		int x = q.top().se; q.pop();
		if(fa[x]){
			x = fa[x];
			if(fa[x]) x = fa[x];
		}
		ans++;
		dfs0(x,0);
		while(!q.empty() && vis[q.top().se]) q.pop();
	}
	cout << ans;
    return 0;
}
