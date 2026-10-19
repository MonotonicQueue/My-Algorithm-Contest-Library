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
const int N = 1010;
int n,m,p;
ll f[N][N],fac[N],inv[N],g[N];
ll pre[N],suf[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%p;
		x = x*x%p;
		k >>= 1;
	}
	return res;
}
ll calc(ll x){
	pre[0] = suf[2*n+2] = 1;
	for(int i=1;i<=2*n+1;i++) pre[i] = pre[i-1]*(x-i)%p;
	for(int i=2*n+1;i;i--) suf[i] = suf[i+1]*(x-i)%p;
	ll res = 0;
	for(int i=1;i<=2*n+1;i++){
		ll mul = pre[i-1]*suf[i+1]%p;
		mul = mul*inv[i-1]%p*inv[2*n+1-i]%p*(((2*n+1-i) & 1) ? p-1 : 1)%p;
		res = (res+mul*g[i]%p+p)%p;
	}
	return (res%p+p)%p;
}
int main(){
    m = read(); n = read(); p = read();
	fac[0] = inv[0] = 1;
	for(int i=1;i<=2*n+1;i++) fac[i] = fac[i-1]*i%p;
	inv[2*n+1] = fpow(fac[2*n+1],p-2);
	for(int i=2*n;i;i--) inv[i] = inv[i+1]*(i+1)%p;
	for(int i=0;i<=2*n+1;i++) f[0][i] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n+1;j++)
			f[i][j] = (f[i-1][j-1]*j%p+f[i][j-1])%p;
	}
	for(int i=1;i<=2*n+1;i++) g[i] = f[n][i]*fac[n]%p;
	cout << calc(m);
    return 0;
}