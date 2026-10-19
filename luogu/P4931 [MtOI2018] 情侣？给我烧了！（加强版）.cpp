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
const int mod = 998244353;
ll fac[N],inv[N],pw[N];
ll g[N];
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
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
    fac[0] = inv[0] = pw[0] = 1;
    for(int i=1;i<=5000000;i++) fac[i] = fac[i-1]*i%mod;
    inv[5000000] = fpow(fac[5000000],mod-2);
    for(int i=4999999;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(int i=1;i<=5000000;i++) pw[i] = pw[i-1]*2%mod;
    g[0] = 1; g[1] = 0;
    for(int i=2;i<=5000000;i++) g[i] = 4ll*i*(i-1)%mod*(g[i-1]+2*(i-1)*g[i-2]%mod)%mod;
    while(T--){
        int n = read(),k = read();
        cout << C(n,k)*C(n,k)%mod*fac[k]%mod*pw[k]%mod*g[n-k]%mod << "\n";
    }
	return 0;
}
