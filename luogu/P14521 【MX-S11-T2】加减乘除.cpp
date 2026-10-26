#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e6+10;
const ll inf = 1e18+114514;
int n,Q,ans[N];
int fa[N];
vector<int> G[N];
ll c[N],L[N],R[N],el[N],er[N],a[N];
void dfs(int x){
	c[x] = c[fa[x]]+a[x];
	for(int y : G[x]){
		if(y == fa[x]) continue;
		L[y] = max(L[x],el[y]-c[x]);
        R[y] = min(R[x],er[y]-c[x]);
		if(L[y] <= R[y]) dfs(y);
	}
}
ll b[N];
void solve(){
	n = read(); Q = read();
	for(int i=2;i<=n;i++){
		fa[i] = read();
		el[i] = read();
		er[i] = read();
		G[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		char op; cin >> op;
		a[i] = read();
		if(op == '-') a[i] = -a[i];
	}
	for(int i=2;i<=n;i++) L[i] = inf,R[i] = -inf;
	L[1] = -inf,R[1] = inf;

	dfs(1);
	
	int m = 0;
	for(int i=1;i<=n;i++){
		if(L[i] <= R[i]){
			b[++m] = L[i];
			b[++m] = R[i]+1;
		}
	}
	sort(b+1,b+1+m);
	m = unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=n;i++){
		if(L[i] > R[i]) continue;
		int x = lower_bound(b+1,b+m+1,L[i])-b;
        ans[x]++;
        x = lower_bound(b+1,b+m+1,R[i]+1)-b;
        ans[x]--;
	}
	for(int i=1;i<=m;i++) ans[i] += ans[i-1];
	while(Q--){
		ll x = read();
		int p = upper_bound(b+1,b+m+1,x)-b-1;
        cout << ans[p] << '\n';
	}
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}
