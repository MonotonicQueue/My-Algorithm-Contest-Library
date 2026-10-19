#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 110;
const int K = 510;
int n,k,mod;
ll f[N][K],g[N][K],h[N][K][K],s[N][K][K];
void init(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++) f[i][j] = g[i][j] = 0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int p=0;p<=k;p++) h[i][j][p] = s[i][j][p] = 0;
}
void solve(){
    n = read(); k = read(); mod = read();
    init();
    for(int i=0;i<=k;i++) f[1][i] = g[1][i] = s[1][i][0] = 1;
    for(int i=0;i<=k;i++) 
        for(int j=0;j<=i;j++) h[1][i][j] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int p=j/2+1;p<=j;p++)
                f[i][j] = (f[i][j]+2ll*f[i-1][p]*g[i-1][j-p]%mod)%mod,
                s[i][j][p] = (s[i][j][p]+2ll*f[i-1][p]*g[i-1][j-p]%mod)%mod;
            for(int p=0;p<=j;p++)
                g[i][j] = (g[i][j]+g[i-1][p]*g[i-1][j-p]%mod)%mod;
        }
        for(int j=1;j<=k;j++)
            f[i][j] = (f[i][j]+f[i][j-1])%mod,
            g[i][j] = (g[i][j]+g[i][j-1])%mod;
        for(int j=1;j<=k;j++)
            for(int p=0;p<=j;p++) s[i][j][p] = (s[i][j][p]+s[i][j-1][p])%mod;
        for(int j=0;j<=k;j++)
            for(int p=1;p<=j;p++) s[i][j][p] = (s[i][j][p]+s[i][j][p-1])%mod;
    }
    for(int j=0;j<=k;j++)
        for(int p=j/2+1;p<=j;p++) h[2][j][p] = 2;
    for(int j=1;j<=k;j++)
        for(int p=0;p<=j;p++) h[2][j][p] = (h[2][j][p]+h[2][j-1][p])%mod;
    for(int j=1;j<=k;j++)
        for(int p=1;p<=j;p++) h[2][j][p] = (h[2][j][p]+h[2][j][p-1])%mod;
    for(int i=3;i<=n;i++){
        for(int j=0;j<=k;j++)
            for(int p=j/2+1;p<=j;p++)
                h[i][j][p] = (h[i][j][p]+2*(h[i-1][p][p]-h[i-1][p][j-p]+mod)*g[i-1][j-p]%mod+
                2*(p == j ? 0 : s[i-1][p][j-p-1]*f[i-1][j-p]%mod))%mod;
        for(int j=1;j<=k;j++)
            for(int p=0;p<=j;p++) h[i][j][p] = (h[i][j][p]+h[i][j-1][p])%mod;
        for(int j=0;j<=k;j++)
            for(int p=1;p<=j;p++) h[i][j][p] = (h[i][j][p]+h[i][j][p-1])%mod;
    }
    cout << h[n][k][k] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
