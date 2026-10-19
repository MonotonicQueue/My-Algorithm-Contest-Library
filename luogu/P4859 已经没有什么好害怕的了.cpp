#include<bits/stdc++.h>
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
const int N = 2100;
const int mod = 1e9+9;
int n,k;
int a[N],b[N];
int cnt[N];
ll dp[N][N],f[N],g[N];
ll fac[N],inv[N];
ll fpow(ll x,int k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
inline void init(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(ll x,ll y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	sort(a+1,a+1+n); sort(b+1,b+1+n);
	if((n+k) & 1) return puts("0"),0;
	init();
	k = (n+k)>>1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt[i] += a[i] > b[j];
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = 1;
		for(int j=1;j<=min(i,cnt[i]);j++)
			dp[i][j] = (dp[i-1][j-1]*(cnt[i]-j+1)%mod+dp[i-1][j])%mod;
	}
	// for(int i=0;i<=n;i++) cout << dp[n][i] << "\n";
	for(int i=0;i<=n;i++) f[i] = dp[n][i]*fac[n-i]%mod;
	for(int i=n;i>=0;i--){
		g[i] = f[i];
		for(int j=i+1,k=-1;j<=n;j++)
			g[i] = (g[i]+k*C(j,i)*g[j]%mod+mod)%mod;
	}
	cout << g[k];
	return 0;
}