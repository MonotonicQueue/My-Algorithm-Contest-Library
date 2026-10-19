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
const int N = 3100;
const int mod = 1e9+7;
int n,c,k;
ll dp[N][N],sum[N][N],cnt[N];
ll fac[N],inv[N],ans;
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
inline void init(){
	dp[0][0] = sum[0][0] = 1;
	for(int i=1;i<=n;i++) sum[0][i] = 1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			dp[i][j] = (sum[i-1][j-1]-(j-c-1 >= 0 ? sum[i-1][j-c-1] : 0)+mod)%mod;
		for(int j=1;j<=n;j++) sum[i][j] = (sum[i][j-1]+dp[i][j])%mod;
	}
	for(int i=1;i<=n;i++) cnt[__gcd(i,n)]++;
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline ll solve(int d){
	if(c >= d) return c+k >= n;
	ll s = 0,bad = 0; int lim1 = (c+k)*d/n,lim0 = d-lim1;
	for(int i=0;i<=lim1;i++) s = (s+C(d,i))%mod;
	for(int p=0;p<=c-1;p++)
		for(int z=max(lim0-1,0);z<=d-p-1;z++)
			bad = (bad+sum[z][d-p-1]-(d-c-1 >= 0 ? sum[z][d-c-1] : 0)+mod)%mod;
	return (s-bad+mod)%mod;
}
int main(){
	n = read(); c = read(); k = read();
	init();
	for(int d=1;d<=n;d++)
		if(n % d == 0) ans = (ans+cnt[d]*solve(d)%mod)%mod;
	cout << ans*fpow(n,mod-2)%mod;
	return 0;
}
