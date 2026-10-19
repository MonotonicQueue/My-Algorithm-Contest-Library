#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1100;
const int mod = 1e9+7;
ll fpow(ll x,ll k){
	if(x == 0) return k == 0;
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
int n,m,K;
ll fac[N],inv[N];
void init(int n=1000){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
	if(x < y) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int U[N],R[N];
ll f[N],g[N];
ll sum[N],pre[N],suf[N];
ll lagrange(int u,int r){
	int m = n+10;
	for(int i=1;i<=m;i++) sum[i] = fpow(u-i,r-1)*fpow(i,n-r)%mod;
	for(int i=1;i<=m;i++) sum[i] = (sum[i-1]+sum[i])%mod;
	if(u <= m) return sum[u];
	pre[0] = suf[m+1] = 1;
	for(int i=1;i<=m;i++) pre[i] = pre[i-1]*(u-i)%mod;
	for(int i=m;i>=1;i--) suf[i] = suf[i+1]*(u-i)%mod;
	ll res = 0;
	for(int i=1;i<=m;i++){
		ll mul = pre[i-1]*suf[i+1]%mod;
		mul = mul*inv[i-1]%mod;
		mul = mul*(((m-i) & 1) ? mod-1 : 1)%mod*inv[m-i]%mod;
		res = (res+mul*sum[i]%mod)%mod;
	}
	return (res%mod+mod)%mod;
}
signed main(){
	init();
	n = read(); m = read(); K = read();
	for(int i=1;i<=m;i++) U[i] = read();
	for(int i=1;i<=m;i++) R[i] = read();
	for(int k=1;k<n;k++){
		g[k] = C(n-1,k);
		for(int i=1;i<=m;i++)
			g[k] = g[k]*C(n-1-k,R[i]-1)%mod*lagrange(U[i],R[i])%mod;
	}
	ll ans = 0;
	for(int k=K;k<=n;k++){
		ans = (ans+(((k-K) & 1) ? mod-1 : 1)*C(k,K)%mod*g[k]%mod)%mod;
	}
	cout << ans;
    return 0;
}
