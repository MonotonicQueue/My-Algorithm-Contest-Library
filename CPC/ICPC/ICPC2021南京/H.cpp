#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 1e5+10;
int n,t[N];
vector<int> G[N]; 
ll a[N],f[N][2];
void dfs(int x,int fa){
	f[x][0] = f[x][1] = 0;
	ll mx0 = 0,sum = 0;
	ll mx1 = 0,id1 = 0,mx2 = 0,id2 = 0;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs(y,x);
		f[x][0] += f[y][1];
		mx0 = max(mx0,a[y]);
		sum += f[y][1];
		
		if(a[y] > mx1 && t[y] == 3) mx1 = a[y],id1 = y;
		if(a[y]+f[y][0]-f[y][1] > mx2) mx2 = a[y]+f[y][0]-f[y][1],id2 = y;
	}
	f[x][1] = sum+mx0;
	if(id1 != id2) f[x][1] = max(f[x][1],mx1+mx2+sum);
	else for(int y : G[x]){
		if(y == fa || y == id1) continue;
		f[x][1] = max(f[x][1],mx1+a[y]+f[y][0]-f[y][1]+sum);
		if(t[y] == 3) f[x][1] = max(f[x][1],a[y]+mx2+sum);
	}
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) t[i] = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout << f[1][1]+a[1] << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
