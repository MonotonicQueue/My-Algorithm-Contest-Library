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
int n,s[N];
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
ll C(int x,int y){
    if(y > x || y < 0) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
    int T = read();
    fac[0] = inv[0] = 1;
    for(int i=1;i<=200000;i++) fac[i] = fac[i-1]*i%mod;
    inv[200000] = fpow(fac[200000],mod-2);
    for(int i=199999;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    while(T--){
        n = read(); int k = read();
        for(int i=1;i<=n;i++) s[i] = read();
        int cnt = 0;
        for(int i=1;i<=n;i++) cnt += s[i];
        ll ans = 0;
        for(int i=(k+1)/2;i<=cnt;i++){
            ans = (ans+C(cnt,i)*C(n-cnt,k-i)%mod)%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
