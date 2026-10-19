#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 410;
const int mod = 998244353;
int n,d[N][N];
ll f[N],g[N],fac[N],inv[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
ll C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
bool chk(int m){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)	
			if(d[i][j] != d[j][i] || d[i][j] > m) return false;
	for(int i=1;i<=n;i++) if(d[i][i]) return false;
	return true;
}
int fa[N],siz[N];
int get(int x){
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
inline void merge(int x,int y){
	x = get(x); y = get(y);
	if(x == y) return ;
	fa[x] = y;
	siz[y] += siz[x];
}
ll solve(int m){
	if(!chk(m)) return 0;
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) f[i] = g[i] = 0;
	for(int i=1;i<=n;i++){
		g[i] = fpow(m+1,i*(i-1)/2);
		f[i] = g[i];
		for(int j=1;j<i;j++) f[i] = (f[i]-C(i-1,j-1)*f[j]%mod*g[i-j]%mod*fpow(m,j*(i-j))%mod+mod)%mod;
	}
	for(int i=1;i<=n;i++) fa[i] = i,siz[i] = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(d[i][j] == 0) merge(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(d[i][j] != d[fa[i]][j]) return 0;
	ll ans = 1;
	// for(int i=1;i<=n;i++) cout << fa[i] << " " << siz[i] << "\n";
	for(int i=1;i<=n;i++)
		if(fa[i] == i) ans = ans*f[siz[i]]%mod;
	for(int i=1;i<=n;i++){
		if(fa[i] != i) continue;
		for(int j=i+1;j<=n;j++){
			if(d[i][j] == 0 || fa[j] != j) continue;
			int mx = 2e9;
			for(int k=1;k<=n;k++)
				if(k != i && k != j && fa[k] == k) mx = min(mx,d[i][k]+d[k][j]);
			// cout << i << " " << j << " " << d[i][j] << " " << mx << "\n";
			if(d[i][j] > mx) return 0;
			if(d[i][j] == mx) ans = ans*fpow(m-d[i][j]+1,siz[i]*siz[j])%mod;
			else ans = ans*(fpow(m-d[i][j]+1,siz[i]*siz[j])-fpow(m-d[i][j],siz[i]*siz[j])+mod)%mod;
			// cout << ans << "\n";
		}
	}
	return ans;
}
int main(){
	int T = 1;
	while(T--){
		n = read(); int m = read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) d[i][j] = read();
		// cout << (solve(m)-solve(m-1)+mod)%mod << "\n";
		cout << solve(m) << "\n";
	}
	return 0;
}
/*
4 5
0 2 0 0
2 0 2 2
0 2 0 0
0 2 0 0
*/