#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
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
int n,mod,root;
vector<int> G[N];
int a[25][2];
void init(){
	n = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
int t[N*25][2],cnt,rt[N];
ll sum[N*25],suf[25];
void insert(int x,int rrtt){
	for(int i=0;i<=20;i++) suf[i] = 0;
	int p = rrtt;
	for(int i=0;i<=20;i++){
		int c = (x >> i) & 1;
		if(!t[p][c]) t[p][c] = ++cnt;
		p = t[p][c];
		suf[i] = a[i][c];
	}
	for(int i=19;i>=0;i--) suf[i] = suf[i]*suf[i+1]%mod;
	p = rrtt;
	for(int i=0;i<=20;i++){
		int c = (x >> i) & 1;
		sum[p] = (sum[p]+suf[i])%mod;
		p = t[p][c];
	}
}
void del(int x,int i){
	swap(t[x][0],t[x][1]);
	if(t[x][1]) del(t[x][1],i+1);
	sum[x] = (sum[t[x][0]]*a[i][0]+sum[t[x][1]]*a[i][1])%mod;
}
int merge(int x,int y){
	if(!x || !y) return x+y;
	sum[x] = (sum[x]+sum[y])%mod;
	t[x][0] = merge(t[x][0],t[y][0]);
	t[x][1] = merge(t[x][1],t[y][1]);
	return x;
}
int dep[N];
ll s1[N],s2[N];
void dfs(int x,int fa){
	dep[x] = dep[fa]+1;
	rt[x] = ++cnt;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs(y,x);
		rt[x] = merge(rt[x],rt[y]);
	}
	insert(x+dep[x],rt[x]);
	s1[x] = sum[rt[x]];
	del(rt[x],0);
	s2[x] = sum[rt[x]];
}
ll s[N];
void dfs2(int x,int fa){
	for(int y : G[x]){
		if(y == fa) continue;
		s[y] = (s[x]+mod-s2[y]+s1[y])%mod;
		dfs2(y,x);
	}
}
void solve(){
	memset(sum,0,sizeof(sum));
	memset(t,0,sizeof(t));
	memset(rt,0,sizeof(rt));
	cnt = 0;
	root = read(); mod = read();
	for(int i=0;i<=20;i++) a[i][0] = read();
	for(int i=0;i<=20;i++) a[i][1] = read();
	dfs(root,0);
	s[root] = s1[root];
	dfs2(root,0);
	
	// for(int i=1;i<=n;i++) cout << s1[i] << " ";
	// cout << "\n";
	// for(int i=1;i<=n;i++) cout << s2[i] << " ";
	// cout << "\n";
	// for(int i=1;i<=n;i++) cout << s[i] << " ";
	// cout << "\n";
	ll ans = 0;
	for(int i=1;i<=n;i++)
		ans ^= s[i]*i;
	cout << ans << "\n";
}
int main(){
	init();
	int T = read();
	while(T--) solve();
	return 0;
}

/*
5
1 2
1 3
2 4
2 5
1
2 100
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/