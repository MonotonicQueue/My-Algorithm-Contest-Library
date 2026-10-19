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
const int mod = 1e9+7;
const int N = 300;
int n,k;
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
void init(){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main(){
	n = read(); k = read();
	init();
	for(int i=0;i<=n;i++){
		if(i & 1) ans = (ans-C(n,i)*fpow((fpow(k-1,i)*fpow(k,n-i)%mod-fpow(k-1,n)+mod)%mod,n)%mod+mod)%mod;
		else ans = (ans+C(n,i)*fpow((fpow(k-1,i)*fpow(k,n-i)%mod-fpow(k-1,n)+mod)%mod,n)%mod)%mod;
	}
	cout << ans;
    return 0;
}
