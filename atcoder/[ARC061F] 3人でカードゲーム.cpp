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
const int N = 1e6+10;
const int mod = 1e9+7;
int n,n1,n2,n3;
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
    if(y < 0 || y > x) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll f[N],ans;
signed main(){
    init();
    n1 = read(); n2 = read(); n3 = read();
    n = n1+n2+n3;
    f[0] = 1;
    for(int i=1;i<=n2+n3;i++) f[i] = (f[i-1]*2-C(i-1,i-n3-1)-C(i-1,n2)+2*mod)%mod;
    for(int i=0;i<=n2+n3;i++) ans = (ans+fpow(3,n2+n3-i)*C(n1-1+i,i)%mod*f[i]%mod)%mod;
    cout << ans;
    return 0;
}
