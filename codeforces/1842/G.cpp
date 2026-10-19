#include<bits/stdc++.h>
#define int ll
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
const int N = 5e3+10;
const int mod = 1e9+7;
int n;
ll a[N],f[N][N],m,v;
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
    n = read(); m = read(); v = read();
    for(int i=1;i<=n;i++) a[i] = read();
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(n,m);j++){
            f[i][j] = (f[i][j]+f[i-1][j]*(a[i]+j*v%mod)%mod)%mod;
            f[i][j+1] = (f[i][j+1]+f[i-1][j]*(m-j)%mod*i%mod*v%mod)%mod;
        }
    }
    ll ans = 0;
    for(int i=0;i<=min(n,m);i++) ans = (ans+f[n][i]*fpow(fpow(n,mod-2),i)%mod)%mod;
    cout << ans; 
    return 0;
}
