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
const int N = 1e4;
int n;
ll fac[N+10],inv[N+10];
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
ll C(int x,int y){
    if(x <= 0) return y == 0;
    if(y > x || y < 0) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
    int T = read();
    fac[0] = inv[0] = 1;
    for(int i=1;i<=N;i++) fac[i] = fac[i-1]*i%mod;
    inv[N] = fpow(fac[N],mod-2);
    for(int i=N-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    while(T--){
        n = read();
        ll ans = 0;
        for(int i=1;i<=2*n+1;i++)
            for(int j=0;j<=n;j++)
                ans = (ans+i*C(min(i-1,n),i-j-1)%mod*C(n-i,2*j-i+1)%mod)%mod;
        cout << ans << "\n";
    }
    return 0;
}