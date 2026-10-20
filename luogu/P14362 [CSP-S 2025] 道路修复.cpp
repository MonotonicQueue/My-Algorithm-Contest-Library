#include<bits/stdc++.h>
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
const int N = 1e4+20;
const int M = 1e6+10;
int n,m,k;
ll c[N],a[15][N];
struct Edge{
	int u,v,w;
}e[M],E[M];
bool operator<(const Edge &x,const Edge &y){
	return x.w < y.w;
}
int fa[N];
inline void init(int n){
	for(int i=1;i<=n;i++) fa[i] = i;
}
int get(int x){
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
	x = get(x); y = get(y);
	if(x == y) return ;
	fa[x] = y;
}
ll work(int S){
	int cnt = n-1,ct = n;
	ll ans = 0;
	for(int i=1;i<n;i++) e[i] = E[i];
	for(int i=1;i<=k;i++){
		if((S >> (i-1)) & 1){
			ans += c[i];
			ct++;
			for(int j=1;j<=n;j++){
				if(a[i][j] >= E[n-1].w) continue;
				++cnt;
				e[cnt].u = ct;
				e[cnt].v = j;
				e[cnt].w = a[i][j];
			}
		}
	}
	sort(e+1,e+1+cnt);
	init(ct);
	int now = 0;
	for(int i=1;i<=cnt;i++){
		int u = e[i].u,v = e[i].v;
		if(get(u) == get(v)) continue;
		now++; 
		merge(u,v);
		ans += e[i].w;
		if(now == ct-1) break;
	}
//	cout << ct<< " " << now <<"\n";
//	cout << ans << "\n";
	return ans;
} 
void solve(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	for(int i=1;i<=k;i++){
		c[i] = read();
		for(int j=1;j<=n;j++) a[i][j] = read();
	}
	sort(e+1,e+1+m);
	ll ans = 0;
	int now = 0;
	init(n);
	for(int i=1;i<=m;i++){
		int u = e[i].u,v = e[i].v;
		if(get(u) == get(v)) continue;
		E[++now] = e[i];
		merge(u,v);
		ans += e[i].w;
		if(now == n-1) break;
	}
	for(int S=1;S<(1<<k);S++){
		ans = min(ans,work(S));
	}
	cout << ans << "\n";
} 
int main(){
	int T = 1;
	while(T--) solve(); 
	return 0;
}
