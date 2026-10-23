#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 5010;
const int mod = 998244353;
int n,m;
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
ll fac[N],inv[N],pw[N];
inline void init(int n = 5000){
    fac[0] = inv[0] = pw[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;~i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*2%mod;
}
ll C(int x,int y){
    if(x < y) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int a[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int k = 0;
        for(int j=i+1;j<=n;j++){
            if(a[j] >= 2*a[i]) break;
            if(a[i] == a[j] || m-2-(n-j) < 0) continue;
            while(k < n && a[i]+a[k+1] < a[j]) ++k;
            ans = (ans+C(n-1-i,m-2-(n-j))*pw[k])%mod;
        }
    }
    ans = (fpow(2,n)-ans+mod)%mod;
    cout << ans << "\n";
}
int main(){
    init();
    read();
    int T = read();
    while(T--) solve();
    return 0;
}
