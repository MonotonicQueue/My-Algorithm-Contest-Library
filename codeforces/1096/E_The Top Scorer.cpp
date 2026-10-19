#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
const int M = 10100;
const int mod = 998244353;
int n,s,r;
ll fac[M],inv[M];
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
ll C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	n = read(); s = read(); r = read();
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n+s;i++) fac[i] = fac[i-1]*i%mod;
	inv[n+s] = fpow(fac[n+s],mod-2);
	for(int i=n+s-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
	ll ans = fpow(n,mod-2)*fpow(C(n+s-1-r,n-1),mod-2)%mod;
	ll res = 0;
	for(int i=1;i<=n && s >= i*r;i++){
		res = (res+((i & 1) ? 1 : mod-1)*C(n,i)%mod*C(s-i*r+n-1,n-1)%mod)%mod;
	}
	cout << res*ans%mod;
	return 0;
}

