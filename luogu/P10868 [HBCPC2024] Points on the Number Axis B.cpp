#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
const int mod = 998244353;
int n;
ll a[N],sum;
ll fac[N],inv[N];
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
void init(int n = 1e6){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll f[N];
int main(){
	init();
    n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	f[0] = 1;
	ll inv2 = fpow(2,mod-2);
	for(int i=1;i<=n;i++) f[i] = f[i-1]*(i+mod-inv2)%mod;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		int x = i-1,y = n-i;
		ll k = f[x]*f[y]%mod*C(x+y,y)%mod;
		ans = (ans+k*a[i])%mod;
	}
	cout << ans*inv[n-1]%mod << "\n";
	return 0;
}