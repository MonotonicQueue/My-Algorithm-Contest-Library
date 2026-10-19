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
const int N = 1e5+10;
const int mod = 1e9+7;
const ll inf = 2e9;
int n,q,a[N];
int fa[N],sz[N];
vector<pii> v[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
ll sum[N],pw2[N],inv[N],pre[N];
ll f[N],g[N];
void merge(int x,int y){
    x = get(x); y = get(y);
    fa[y] = x;
    if((sz[x] >= 30 && f[x] >= 0) || f[x]+(f[y]<<sz[x]) >= inf) f[x] = inf;
    else f[x] += f[y] << sz[x];
    g[x] = (g[x]+g[y]*pw2[sz[x]]%mod)%mod;
    sz[x] += sz[y];
}
ll calc(int l,int r){
    return (sum[r]-sum[l-1]+mod)%mod*inv[l]%mod;
}
ll ans[N];
signed main(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) fa[i] = i,sz[i] = 1;
    for(int i=1;i<=q;i++){
        int l = read(),r = read();
        v[r].push_back(mk(l,i));
    }
    pw2[0] = inv[0] = 1;
    for(int i=1;i<=n;i++){
        pw2[i] = pw2[i-1]*2%mod;
        inv[i] = inv[i-1]*(mod+1)/2%mod;
        sum[i] = (sum[i-1]+pw2[i]*a[i]%mod)%mod;
    }
    for(int i=1;i<=n;i++){
        f[i] = g[i] = a[i];
        while(get(i) > 1 && f[get(i)] >= 0) merge(get(get(i)-1),get(i));
        pre[get(i)] = pre[get(get(i)-1)]+g[get(i)];
        for(auto it : v[i]){
            int l = it.fi;
            ans[it.se] = (pre[get(i)]-pre[get(l)]+mod)*2%mod+calc(l,get(l)+sz[get(l)]-1);
            ans[it.se] = (ans[it.se]%mod+mod)%mod;
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
    return 0;
}
