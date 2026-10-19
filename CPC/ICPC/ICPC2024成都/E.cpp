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
int n,a[N],dep[N];
int fa[N][20];
vector<int> G[N];
ll f[N],h[N],sss;
ll sm[N][20],s[N];
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
void dfs1(int x){
    dep[x] = dep[fa[x][0]]+1;
    for(int i=1;i<=19;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    f[x] = 1;
    for(int y : G[x]){
        dfs1(y);
        f[x] = f[x]*(f[y]+1)%mod;
    }
}
void dfs2(int x){
    s[x] = (s[x]+h[x])%mod;
    vector<ll> pre(G[x].size()),suf(G[x].size());
    for(int i=0;i<int(G[x].size());i++){
        int y = G[x][i];
        pre[i] = (i == 0 ? 1 : pre[i-1])*(f[y]+1)%mod;
    }
    for(int i=int(G[x].size()-1);~i;i--){
        int y = G[x][i];
        suf[i] = (i == int(G[x].size()-1) ? 1 : suf[i+1])*(f[y]+1)%mod;
    }
    for(int i=0;i<int(G[x].size());i++){
        int y = G[x][i];
        h[y] = (i == 0 ? 1 : pre[i-1])*(i == int(G[x].size()-1) ? 1 : suf[i+1])%mod*(h[x]+1)%mod;
    }
    for(int y : G[x]) s[y] = s[x],dfs2(y);
}
void clear(){
    sss = 0;
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=n;i++) f[i] = h[i] = s[i] = 0;
}
int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=19;~i;i--)
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i=19;~i;i--)
        if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
    return fa[x][0];
}
void solve(){
    n = read(); int Q = read();
    clear();
    for(int i=2;i<=n;i++) fa[i][0] = read();
    for(int i=2;i<=n;i++)
        G[fa[i][0]].push_back(i);
    dfs1(1);
    dfs2(1);
    for(int x=1;x<=n;x++){
        sm[x][0] = f[fa[x][0]];
        for(int i=1;i<=19;i++) sm[x][i] = (sm[x][i-1]+sm[fa[x][i-1]][i-1])%mod;
    }
    ll sum = 0;
    for(int i=1;i<=n;i++) sum = (sum+f[i])%mod;
    auto get = [&](int x,int d){
        ll res = f[x];
        for(int i=19;~i;i--)
            if(dep[fa[x][i]] >= dep[d]) res = (res+sm[x][i])%mod,x = fa[x][i];
        return res;
    };
    while(Q--){
        int u = read(),v = read();
        int d = lca(u,v);
        ll ans = (sum+s[d])%mod;
        ans = (ans-(get(u,d)+get(v,d)-f[d]))%mod;
        ans = (ans-(get(d,1)-f[d])+mod)%mod;
        ans = (ans+mod)%mod;
        cout << (sum-ans+mod)%mod << "\n";
    }
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 


