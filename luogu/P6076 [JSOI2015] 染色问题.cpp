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
const int N = 410;
const ll mod = 1e9+7;
int n,m,c;
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
ll C(ll x,ll y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll f[N];
int main(){
    n = read(); m = read(); c = read();
    fac[0] = inv[0] = 1;
    for(int i=1;i<=400;i++) fac[i] = fac[i-1]*i%mod;
    inv[400] = fpow(fac[400],mod-2);
    for(int i=399;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(int i=1;i<=c;i++){
       f[i] = fpow(fpow(i+1,m)-1,n);
       for(int j=1;j<=m;j++) f[i] = (f[i]+((j & 1) ? (mod-1) : 1)*fpow(fpow(i+1,m-j)-1,n)%mod*C(m,j)%mod)%mod;
    }
    ll ans = f[c];
    for(int i=1;i<c;i++) ans = (ans+((i & 1) ? mod-1 : 1)*f[c-i]%mod*C(c,c-i)%mod)%mod;
    cout << ans;
	return 0;
}
