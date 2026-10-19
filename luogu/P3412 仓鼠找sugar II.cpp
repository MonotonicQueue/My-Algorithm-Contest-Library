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
const int N = 1e5+10;
const int mod = 998244353;
int n;
vector<int> G[N];
ll f[N],g[N],siz[N];
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
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
void dfs1(int x,int fa){
    siz[x] = 1;
    ll sum = 0;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs1(y,x);
        siz[x] += siz[y];
        add(sum,f[y]);
    }
    add(f[x],(sum+G[x].size())%mod);
    if(x == 1) f[x] = 0;
}
void dfs2(int x,int fa){
    ll sum = g[x];
    for(int y : G[x]){
        if(y == fa) continue;
        add(sum,f[y]);
    }
    for(int y : G[x]){
        if(y == fa) continue;
        add(g[y],((sum-f[y]+mod)%mod+G[x].size())%mod);
        dfs2(y,x);
    }
}
signed main(){
    n = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0); dfs2(1,0);
    ll ans = 0;
    for(int i=1;i<=n;i++)
        add(ans,(f[i]+g[i])*siz[i]%mod*(n-siz[i])%mod);
    cout << ans*fpow(1ll*n*n%mod,mod-2)%mod;
    return 0;
}
