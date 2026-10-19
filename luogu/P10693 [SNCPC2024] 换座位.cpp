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
int n,a[N],ans;
vector<int> G[N],E[N];
int mxdep[N],in[N],mx;
bool vis[N];
void dfs(int x,int dep){
	vis[x] = true;
	mx = max(mx,dep);
	for(int y : G[x])
		dfs(y,dep+1);
}
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!in[i] && !vis[i]) q.push(i);
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = true;
		for(int y : E[x]){
			in[y]--;
			if(!in[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) ans++;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		G[a[i]].push_back(i);
		E[i].push_back(a[i]);
		in[a[i]]++;
	}
	for(int i=n+1;i<=2*n;i++){
		mx = 0;
		dfs(i,0);
		ans += mx;
	}
	topsort();
	cout << ans << "\n";
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}