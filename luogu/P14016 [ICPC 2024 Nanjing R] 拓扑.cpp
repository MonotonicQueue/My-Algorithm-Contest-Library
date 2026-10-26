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
void init(int n = 5e3){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,fa[N],siz[N];
vector<int> G[N];
ll f[N];
void dfs1(int x){
    siz[x] = 1; f[x] = 1;
    for(int y : G[x]){
        dfs1(y);
        siz[x] += siz[y];
        f[x] = f[x]*f[y]%mod*inv[siz[y]]%mod;
    }
    f[x] = f[x]*fac[siz[x]-1]%mod;
}
ll g[N][N],ans[N];
void dfs2(int x){
    {
        ll sum = 0;
        for(int i=0;i<x;i++) sum = (sum+g[x][i])%mod;
        ans[x] = sum*C(n-x,siz[x]-1)%mod*f[x]%mod;
    }
    for(int y : G[x]){
        ll tot = f[x];
        tot = tot*inv[siz[x]-1]%mod;
        tot = tot*fac[siz[y]]%mod*fac[siz[x]-1-siz[y]]%mod;
        tot = tot*fpow(f[y],mod-2)%mod;
        ll sum = 0;
        int other = siz[x]-siz[y]-1;
        for(int i=1;i<=n;i++){
            int r = n-(i-1)-siz[x];
            if(r < 0) break;
            sum = (sum+g[x][i-1])%mod;
            g[y][i] = tot*sum%mod*C(other+r,other)%mod;
        }
        dfs2(y);
    }
}
void solve(){
    n = read();
    for(int i=2;i<=n;i++) fa[i] = read(); 
    for(int i=2;i<=n;i++)
        G[fa[i]].push_back(i);
    dfs1(1);
    g[1][0] = 1;
    dfs2(1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    init();
    int T = 1;
    while(T--) solve();
	return 0;
} 
