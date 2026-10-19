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
const int N = 2e5+10;
const int mod = 1e9+7;
int n;
vector<int> G[N];
ll f[N],g[N],siz[N];
void dfs1(int x,int fa){
    siz[x] = 1;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs1(y,x);
        f[x] = (f[x]+siz[x]*siz[y]+f[y])%mod;
        g[x] = (g[x]+g[y]+f[y])%mod;
        siz[x] += siz[y];
    }
}
ll h[N],hh[N];
void dfs2(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        h[y] = g[y]; hh[y] = f[y];
        ll c = ((hh[x]-f[y]-siz[y]*(n-siz[y]))%mod+mod)%mod;
        hh[y] = (f[y]+c+siz[y]*(n-siz[y]))%mod;
        ll s = ((h[x]-g[y]-f[y])%mod+mod)%mod;
        h[y] = (h[y]+s+c)%mod;
        dfs2(y,x);
    }
}
int main(){
    n = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs1(1,0); h[1] = g[1]; hh[1] = f[1];
    // cout << g[1] << "\n";
    dfs2(1,0);
    ll ans =0 ;
    for(int i=1;i<=n;i++) ans = (ans+h[i])%mod;
    cout << ans;
    return 0;
}