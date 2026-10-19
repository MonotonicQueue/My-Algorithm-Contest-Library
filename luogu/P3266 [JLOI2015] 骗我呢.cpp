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
const int N = 5e6+10;
const int mod = 1e9+7;
int n,m;
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
    if(x < 0 || y < 0 || x < y) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void slip(int &x,int &y,int k){
    swap(x,y);
    x -= k; y += k;
}
int main(){
    n = read(); m = read();
    fac[0] = inv[0] = 1;
    for(int i=1;i<=5000000;i++) fac[i] = fac[i-1]*i%mod;
    inv[5000000] = fpow(fac[5000000],mod-2);
    for(int i=4999999;i>=1;i--) inv[i] = inv[i+1]*(i+1)%mod;
    int x = n+m+1,y = n;
    ll ans = C(x+y,x);
    while(x >= 0 && y >= 0){
        slip(x,y,1);
        ans = (ans-C(x+y,x)+mod)%mod;
        slip(x,y,-m-2);
        ans = (ans+C(x+y,x)+mod)%mod;
    }
    x = n+m+1; y = n;
    while(x >= 0 && y >= 0){
        slip(x,y,-m-2);
        ans = (ans-C(x+y,x)+mod)%mod;
        slip(x,y,1);
        ans = (ans+C(x+y,x)+mod)%mod;
    }
    cout << ans;
	return 0;
}
