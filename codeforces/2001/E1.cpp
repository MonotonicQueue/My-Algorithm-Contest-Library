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
const int N = 510;
int n,k,mod;
ll f[N][N],g[N][N];
void init(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++) f[i][j] = g[i][j] = 0;
}
void solve(){
    n = read(); k = read(); mod = read();
    init();
    for(int i=0;i<=k;i++) f[1][i] = g[1][i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int p=j/2+1;p<=j;p++)
                f[i][j] = (f[i][j]+2ll*f[i-1][p]*g[i-1][j-p]%mod)%mod;
            for(int p=0;p<=j;p++)
                g[i][j] = (g[i][j]+g[i-1][p]*g[i-1][j-p]%mod)%mod;
        }
        for(int j=1;j<=k;j++)
            f[i][j] = (f[i][j]+f[i][j-1])%mod,
            g[i][j] = (g[i][j]+g[i][j-1])%mod;
    }
    cout << f[n][k] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
