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
const int N = 105;
const int M = 1005;
const ll INF = 1e18;
int n,m,K;
ll B[N][M],S[N][M];
ll dis[N][N],f[N][N],d[N]; 
int cnt[N]; bool vis[N];
bool chk(ll mid){
	queue<int> q;
	for(int i=1;i<=n;i++){
		cnt[i] = 1; d[i] = 0;
		q.push(i); vis[i] = true;
	}
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int y=1;y<=n;y++){
			if(y == x) continue;
			if(d[y] >= d[x]+mid*dis[x][y]-f[x][y]){
				d[y] = d[x]+mid*dis[x][y]-f[x][y];
				if(!vis[y]){
    				   cnt[y]++;
    				if(cnt[y] > n+10) return true;
    				vis[y] = true,q.push(y);
				}
			}
		}
	}
	return false;
}
signed main(){
	n = read(); m = read(); K = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=K;j++)
			B[i][j] = read(),S[i][j] = read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = 1e9;		
	for(int i=1;i<=m;i++){
		int u = read(),v = read(); ll w = read();
		dis[u][v] = min(dis[u][v],w);
	}
	for(int i=1;i<=n;i++) dis[i][i] = 0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
		 		dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++,puts(""))
//		for(int j=1;j<=n;j++) cout << dis[i][j] << " ";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=K;k++)
				if(B[i][k] != -1 && S[j][k] != -1)
					f[i][j] = max(f[i][j],S[j][k]-B[i][k]);
//	for(int i=1;i<=n;i++,puts(""))
//		for(int j=1;j<=n;j++) cout << f[i][j] << " ";
	ll l = 0,r = 1000000000,ans = 0;
	while(l <= r){
		ll mid = (l+r)>>1;
		if(chk(mid)) l = mid+1,ans = mid;
		else 		 r = mid-1; 
	}
	cout << ans;
	return 0;
}
/*
3 2 1
1 1
-1 1000
-1 1000
2 3 1
3 1 1
*/