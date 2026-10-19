#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 410;
const int mod = 998244353;
int n,a[N],b[N];
int suma,sumb;
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
ll f[N][N][N],fac[N],inv[N],pw[N][N];
inline void init(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=sumb;i++) fac[i] = fac[i-1]*i%mod;
	inv[sumb] = fpow(fac[sumb],mod-2);
	for(int i=sumb-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		pw[i][0] = 1;
		for(int j=1;j<=b[i];j++) pw[i][j] = pw[i][j-1]*a[i]%mod;
	}
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read(); b[i] = read()-1;
		suma += a[i]; sumb += b[i];
	}
	init();
	f[0][0][0] = -1;
	for(int i=1;i<=n;i++) for(int j=0;j<=suma;j++)
	for(int k=0;k<=sumb;k++){
		f[i][j][k] = f[i-1][j][k];
		if(j >= a[i]) for(int l=0;l<=min(b[i],k);l++)
			f[i][j][k] = (f[i][j][k]-f[i-1][j-a[i]][k-l]*pw[i][l]%mod*inv[l]%mod+mod)%mod;
	}
	ll ans = 0;
	for(int i=0;i<=suma;i++) for(int j=0;j<=sumb;j++)
		ans = (ans+f[n][i][j]*fpow(fpow(i,mod-2),j+1)%mod*fac[j]%mod*suma%mod)%mod;
	cout << ans;
    return 0;
}