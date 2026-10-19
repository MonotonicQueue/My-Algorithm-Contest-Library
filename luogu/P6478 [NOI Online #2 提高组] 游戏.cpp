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
const int N = 5100;
const int mod = 998244353;
int n,m;
char s[N];
vector<int> G[N];
ll f[N][N],tf[N],g[N];
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
int siz[N][2];
ll fac[N],ifac[N];
ll C(int x,int y){
    if(y < 0 || x < y) return 0;
    return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void dfs(int x,int fa){
    f[x][0] = 1;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        for(int i=0;i<=(siz[x][0]+siz[y][0]+siz[x][1]+siz[y][1])/2;i++) tf[i] = 0;
        for(int i=0;i<=(siz[x][0]+siz[x][1])/2;i++)
            for(int j=0;j<=(siz[y][0]+siz[y][1])/2;j++)
                tf[i+j] = (tf[i+j]+f[x][i]*f[y][j]%mod)%mod;
        for(int i=0;i<=(siz[x][0]+siz[y][0]+siz[x][1]+siz[y][1])/2;i++) f[x][i] = tf[i];
        siz[x][0] += siz[y][0];
        siz[x][1] += siz[y][1];
    }
    int c = s[x]-'0';
    siz[x][c] += 1;
    for(int i=(siz[x][0]+siz[x][1])/2;i>0;i--)
        if(siz[x][c^1]-i+1 > 0)
            f[x][i] = (f[x][i]+f[x][i-1]*(siz[x][c^1]-i+1)%mod)%mod;
}
int main(){
    n = read(); m = n/2;
    auto init = [&](){
        fac[0] = ifac[0] = 1;
        for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
        ifac[n] = fpow(fac[n],mod-2);
        for(int i=n-1;i;i--) ifac[i] = ifac[i+1]*(i+1)%mod;
    };
    init();
    scanf("%s",s+1);
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<=m;i++) g[i] = f[1][i]*fac[m-i]%mod;
    for(int i=0;i<=m;i++){
        ll res = 0;
        for(int j=i;j<=m;j++)
            res = (res+(((j-i) & 1) ? mod-1 : 1)*C(j,i)%mod*g[j]%mod)%mod;
        cout << res << "\n";
    }
    return 0;
}
