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
const int N = 2e3+10;
const int mod = 998244353;
ll fac[N],inv[N],pw[N];
ll C[N][N],f[N],g[N];
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
int main(){
    int T = read();
    C[0][0] = 1;
    for(int i=1;i<=2000;i++){
    	C[i][0] = 1;
    	for(int j=1;j<=i;j++)
    		C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	}
    fac[0] = inv[0] = pw[0] = 1;
    for(int i=1;i<=2000;i++) fac[i] = fac[i-1]*i%mod;
    inv[2000] = fpow(fac[2000],mod-2);
    for(int i=1999;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(int i=1;i<=2000;i++) pw[i] = pw[i-1]*2%mod;
    g[0] = 1; g[1] = 0;
    for(int i=2;i<=1000;i++) g[i] = 4*i*(i-1)*(g[i-1]+2*(i-1)*g[i-2]%mod)%mod;
    while(T--){
        int n = read();
		for(int i=0;i<=n;i++){
			ll res = C[n][i]*C[n][i]%mod*fac[i]%mod*pw[i]%mod*g[n-i]%mod;
			cout << res << "\n"; 
		}
    }
	return 0;
}