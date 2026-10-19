#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e6+10;
int n,mod,lg[N];
ll f[N],s[N]; 
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
ll fac[N],inv[N];
ll C(int x,int y){
	if(y == 0) return 1;
	if(x < y) return 0;
	if(x <= mod) return fac[x]*inv[y]%mod*inv[x-y]%mod;
	return C(x/mod,y/mod)*C(x%mod,y%mod)%mod;
}
int main(){
	n = read(); mod = read();
	fac[0] = inv[0] = 1;
	for(int i=1;i<=min(n,mod-1);i++) fac[i] = fac[i-1]*i%mod;
	inv[min(n,mod-1)] = fpow(fac[min(n,mod-1)],mod-2);
	for(int i=min(n,mod-1)-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) s[i] = 1;
	for(int i=n;i>=2;i--) s[i>>1] += s[i];
	for(int i=1;i<=2*n+1;i++) f[i] = 1;
	for(int i=n;i>=1;i--)
		f[i] = C(s[i]-1,s[2*i])*f[2*i]%mod*f[2*i+1]%mod;
	cout << f[1];
	return 0;
} 