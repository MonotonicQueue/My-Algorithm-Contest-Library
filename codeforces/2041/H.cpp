#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 1e6+10;
const int mod = 998244353;
int n,k;
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
ll f[N],sum[N];
int main(){
    init();
    n = read()-1; k = read();
    f[0] = sum[0] = 1;
    for(int i=1;i<=n;i++){
        f[i] = sum[i-1];
        if(i-k >= 0) f[i] = (f[i]-sum[i-k]+mod)%mod;
        sum[i] = (sum[i-1]+f[i])%mod;
    }
    ll ans = 1;
    for(int i=1;i<=n;i++) ans = (ans+2*C(n,i)*f[i])%mod;
    cout << ans;
	return 0;
}

