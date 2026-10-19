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
const int N = 5100;
int n,cnt;
vector<pii> G[N];
int lst[N],pre[N],f[1919810],ans;
bool vis[N][2];
void dfs(int x){
	vis[x][0] = true;
	for(auto it : G[x]){
		int y = it.fi,id = it.se;
		if(!vis[y][0]){
			lst[y] = id; pre[y] = x;
			dfs(y);
		}else{
			int mx = -1;
			int u = x,v = y;
			while(vis[v][1]) mx = max(mx,f[lst[v]]),v = pre[v];
			mx++; f[id] = mx;
			ans = max(ans,mx);
			while(u != v) f[lst[u]] = mx,u = pre[u];
			pre[y] = x; lst[y] = id;
		}
	}
	vis[x][1] = true;
}
signed main(){
	n = read();
	for(int i=1;i<n;i++){
		int k = read();
		while(k--){
			int u = read();
			G[i].push_back(mk(u,++cnt));
		}
	}
	dfs(1);
	cout << ans+1;
    return 0;
}
