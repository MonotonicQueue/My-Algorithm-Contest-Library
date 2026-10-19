#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(ch != '-' && !isdigit(ch)) ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m,k,c[N],Q;
bool s[N];
vector<pii> G[N];
int dep[N],sum[N],f[N],fa[N][20];
int col[N][45];
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=18;~i;i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i=18;~i;i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
void dfs(int x,int ft){
	dep[x] = dep[ft]+1;
	fa[x][0] = ft;
	for(int i=1;i<=18;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	
	for(auto _ : G[x]){
		int y = _.fi,w = _.se;
		if(y == ft) continue;
		sum[y] = sum[x]+w;
		for(int i=1;i<=m;i++) col[y][i] = col[x][i];
		col[y][c[y]]++;
		dfs(y,x);
	}
}
void dfs0(int x,int ft){
	f[x] = f[ft]+s[x];
	for(auto _ : G[x]){
		int y = _.fi,w = _.se;
		if(y == ft) continue;
		dfs0(y,x);
	}
}
struct node{
	int u,v,d;
};
vector<node> V; 
void solve(){
	n = read(); m = read(); k = read(); Q = read();
	{
		string S; cin >> S;
		for(int i=1;i<=n;i++)
			s[i] = (S[i-1]=='1');
	}
	for(int i=1;i<=n;i++) c[i] = read();
	for(int i=2;i<=n;i++){
		int u = read(),v = read(),w = read()%k;
		G[u].push_back(mk(v,w));
		G[v].push_back(mk(u,w));
	} col[1][c[1]] = 1;
	dfs(1,0);
//	for(int i=1;i<=n;i++,puts(""))
//		for(int j=1;j<=m;j++) cout << col[i][j] << " ";
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int d = lca(i,j);
			if((sum[i]+sum[j]-2*sum[d])%k != 0) continue;
			int cnt = 0;
			for(int k=1;k<=m;k++){
				cnt += ((col[i][k]+col[j][k]-col[d][k]-col[fa[d][0]][k])&1);
			}
//			cout << i << " " << j << " " << cnt << "\n";
			if(cnt == 1){
				V.push_back(node{i,j,d});
//				cout << i << " " << j << " " << d << "\n";
			}
		}
	{
		int ans = 0;
		for(auto _ : V){
			int i = _.u,j = _.v,d = _.d;
			if(s[i] && s[j]) ans++;
//			if((f[i]+f[j]-f[d]-f[fa[d][0]]) == (dep[i]+dep[j]-dep[d]-dep[fa[d][0]])){
//				ans++;
////			cout << i << " " << j << "\n";
//			}
				
		}
		cout << ans << "\n";
	}
	while(Q--){
		int u = read();
		s[u] ^= 1;
//		dfs0(1,0);
//		for(int i=1;i<=n;i++) cout << s[i] << " ";
//		cout << "\n";
		int ans = 0;
		for(auto _ : V){
			int i = _.u,j = _.v,d = _.d;
			if(s[i] && s[j]) ans++;
//			if((f[i]+f[j]-f[d]-f[fa[d][0]]) == (dep[i]+dep[j]-dep[d]-dep[fa[d][0]])){
//				ans++;
//			cout << i << " " << j << "\n";
//			}
//				
		}
		cout << ans << "\n";
	}
}
int main(){
	int T = 1;
	while(T--) solve(); 
	return 0;
}
