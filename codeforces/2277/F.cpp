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
const int N = 5e5+10;
const int mod = 998244353;
int n,p[N],fa[N],ft[N];
ll a[N],sum[N],val[N];
vector<int> G[N],E[N];
void dfs(int x,int fa){
    // flag[x][x] = 1;
    ft[x] = fa;
    sum[x] = a[x];
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        sum[x] += sum[y];
        // for(int i=1;i<=n;i++) flag[x][i] |= flag[y][i];
    }
    sum[x] %= mod;
}
void dfs2(int x){
    for(int y : E[x]){
        (val[y] += val[x]) %= mod;
        dfs2(y);
    }
}
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)] = get(y);
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
        E[i].clear();
        val[i] = 0;
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) p[i] = read();
    // for(int rt=1;rt<=n;rt++){
    //     for(int i=1;i<=n;i++)
    //         for(int j=1;j<=n;j++) flag[i][j] = false;
    //     dfs(rt,0);
    //     ll ans = 0;
    //     for(int i=1;i<=n;i++){
    //         bool flag1 = false;
    //         for(int j=1;j<i;j++)
    //             if(flag[p[j]][p[i]]) flag1 = true;
    //         if(!flag1) ans += sum[p[i]];
    //     }
    //     cout << ans%mod << " ";
    // } n^3
    dfs(1,0);
    for(int i=1;i<=n;i++) fa[i] = 0;
    for(int i=n;i;i--){
        int x = p[i];
        fa[x] = x;
        for(int y : G[x]){
            if(!fa[y]) continue;
            if(y == ft[x]){
                y = get(y);
                (val[y] += sum[x]) %= mod;
            }else{
                ll t = (sum[1]+mod-sum[y])%mod;
                y = get(y);
                (val[y] += t) %= mod;
            }
            merge(y,x);
            E[x].push_back(y);
        }
    }
    dfs2(p[1]);
    for(int i=1;i<=n;i++) cout << (val[i]+sum[1])%mod << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}