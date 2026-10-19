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
const int N = 110;
const int mod = 998244353;
ll fac[1000100],inv[1000100];
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
int n,m,d;
ll f[N][N][N];
int main(){
	init();
    n = read(); m = read(); d = read();
	f[0][1][1] = 1;
	for(int i=0;i<d;i++) for(int j=1;j<=n;j++)
	for(int k=0;k<=j;k++) for(int x=0;x<=min(m*k,n-j);x++)
		f[i+1][j+x][x] = (f[i+1][j+x][x]+C(m*k,x)*f[i][j][k]%mod)%mod;
	ll ans = 0;
	for(int i=0;i<=n;i++) ans = (ans+f[d][n][i])%mod;
	cout << ans;	
	return 0;
}