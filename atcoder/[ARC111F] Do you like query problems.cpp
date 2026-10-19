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
const int mod = 998244353;
ll n,m,q,ans;
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
signed main(){
    n = read(); m = read(); q = read();
    for(ll i=1;i<=n;i++){
        ll p = 2*m*i%mod*(n-i+1)%mod*fpow(n*(n+1)%mod*(2*m+1)%mod,mod-2)%mod;
        p = (q-(1-fpow(1-p,q)+mod)*fpow(p,mod-2)%mod+mod)%mod;
        ans = (ans+i*(n-i+1)%mod*(m-1)%mod*fpow(n*(n+1)%mod*(2*m+1)%mod,mod-2)%mod*p%mod)%mod;
    }
    cout << ans*fpow(n*(n+1)/2%mod*(2*m+1)%mod,q)%mod;
    return 0;
}