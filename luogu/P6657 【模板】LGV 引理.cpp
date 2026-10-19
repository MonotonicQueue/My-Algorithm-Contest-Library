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
const int N = 2e6+10;
const int M = 110;
const int mod = 998244353;
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
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void init(int n = 2e6){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
int a[M],b[M];
ll g[M][M];
ll det(){
    ll res = 1;
    for(int i=1;i<=m;i++){
        if(!g[i][i]){
            for(int j=i+1;j<=m;j++)
                if(g[j][i]){
                    swap(g[i],g[j]);
                    res = mod-res;
                    break;
                }
        }
        for(int j=i+1;j<=m;j++){
            ll t = fpow(g[i][i],mod-2)*g[j][i]%mod;
            for(int k=i;k<=m;k++) g[j][k] = (g[j][k]+(mod-1)*t%mod*g[i][k]%mod)%mod;
        }
    }
    for(int i=1;i<=m;i++) res = res*g[i][i]%mod;
    return res;
}
inline void solve(){
    n = read(); m = read();
    for(int i=1;i<=m;i++) a[i] = read(),b[i] = read();
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(b[j] >= a[i]) g[i][j] = C(n-1+b[j]-a[i],n-1);
    cout << det() << "\n";
}
int main(){
    init();
    int T = read();
    while(T--) solve();
    return 0;
}