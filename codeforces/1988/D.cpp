// LUOGU_RID: 166318086
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
const int N = 3e5+10;
int n;
vector<int> G[N];
ll a[N],f[N][20];
void dfs(int x,int fa){
	for(int i=0;i<=19;i++) f[x][i] = (19-i)*a[x];
	for(int y : G[x]){
		if(y == fa) continue;
		dfs(y,x);
		for(int i=0;i<=19;i++){
			ll t = 0;
			for(int j=0;j<=19;j++) 
				if(i != j) t = max(t,f[y][j]);
			f[x][i] += t;
		}
	}
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) for(int j=0;j<=19;j++) f[i][j] = 0;
		for(int i=1;i<=n;i++) G[i].clear();
		ll sum = 0;
		for(int i=1;i<=n;i++) a[i] = read(),sum += a[i];
		for(int i=1;i<n;i++){
			int u = read(),v = read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		ll s = 0;
		for(int i=0;i<=19;i++) s = max(s,f[1][i]);
		cout << sum*20-s << "\n";
	}
	return 0;
}