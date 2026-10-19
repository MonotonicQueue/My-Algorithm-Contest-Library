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
const int N = 3e5+10;
int n,siz[N],mxson[N],now[N];
vector<int> G[N];
ll t[N],f[N];
void add(int x,int y){
	while(x <= n){
		t[x] += y;
		x += x&(-x);
	}
}
ll ask(int x){
	ll res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
ll query(int l,int r){
	if(l <= 0 || r > n || l > r) return 0;
	return ask(r)-ask(l-1);
}
inline void clear(){
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) t[i] = f[i] = 0;
}
int root;
void getrt(int x,int fa){
	int mxpart = 0;
	siz[x] = 1;
	for(int y : G[x]){
		if(y == fa) continue;
		getrt(y,x);
		siz[x] += siz[y];
		mxpart = max(mxpart,siz[y]);
	}
	mxpart = max(mxpart,n-siz[x]);
	if(mxpart*2 <= n) root = x;
}

void dfs0(int x,int fa){
	siz[x] = 1;
	mxson[x] = 0;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs0(y,x);
		siz[x] += siz[y];
		mxson[x] = max(mxson[x],siz[y]);
	}
	now[x] = siz[x];
}
void dfs1(int x,int fa){
	f[x] += query(n-2*siz[x],n-2*mxson[x]);
	add(siz[x],1);
	for(int y : G[x]){
		if(y == fa) continue;
		dfs1(y,x);
	}
	f[x] -= query(n-2*siz[x],n-2*mxson[x]);
}
void dfs2(int x,int fa){
	f[x] += query(n-2*siz[x],n-2*mxson[x]);
	for(int y : G[x]){
		if(y == fa) continue;
		add(now[x],-1);
		add(now[x]=n-siz[y],1);
		dfs2(y,x);
	}
	add(now[x],-1);
	add(siz[x],1);
}
void dfs3(int x,int fa,int mxs,int sz){
	int sum = n-siz[x];
	int mxsn = max(mxs,sz-siz[x]);
	if(mxsn*2 <= sum) f[root]++;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs3(y,x,mxs,sz);
	}
}
void solve(){
	root = 0;
	getrt(1,0);
	dfs0(root,0);
	dfs1(root,0);
	dfs2(root,0);
	f[root] = 0;
	int mx = 0,smx = 0,pos = 0;
	for(int y : G[root]){
		if(siz[y] > mx) smx = mx,mx = siz[y],pos = y;
		else if(siz[y] > smx) smx = siz[y];
	}
	for(int y : G[root]){
		if(y == pos) dfs3(y,root,smx,siz[y]);
		else dfs3(y,root,mx,siz[y]);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) ans += i*f[i];
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--){
		n = read();
		clear();
		for(int i=2;i<=n;i++){
			int u = read(),v = read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		solve();
	}
    return 0;
}

