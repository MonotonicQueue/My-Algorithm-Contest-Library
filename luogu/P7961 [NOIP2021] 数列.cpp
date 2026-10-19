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
const int N = 35;
const int M = 110;
const int mod = 998244353;
int n,m,k;
ll a[M],f[2][N][N][N];
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
inline void init(){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
ll pw[M][N];
int g[N];
signed main(){
    // freopen("sequence.in","r",stdin);
    // freopen("sequence.out","w",stdout);
	n = read(); m = read(); k = read();
	for(int i=0;i<=m;i++) a[i] = read();
    for(int i=0;i<=m;i++){
        pw[i][0] = 1;
        for(int j=1;j<=n;j++) pw[i][j] = pw[i][j-1]*a[i]%mod;
    }
    init();
    f[1][0][0][0] = 1;
    for(int i=0;i<=m;i++){
        int c = i&1;
        memset(f[c],0,sizeof(f[c]));
        for(int j=0;j<=n;j++) for(int k=0;k<=n;k++)
        for(int h=0;h<=n;h++) for(int l=0;l+j<=n;l++)
            add(f[c][j+l][k+h%2][h/2+l],f[c^1][j][k][h]*C(n-j,l)%mod*pw[i][l]%mod);
    }
    for(int i=1;i<=n;i++) g[i] = g[i>>1]+(i & 1);
    ll ans = 0;
    for(int i=0;i<=k;i++)
        for(int j=0;j<=n;j++)
            if(i+g[j] <= k) add(ans,f[m&1][n][i][j]);
    cout << ans << "\n";
    return 0;
}