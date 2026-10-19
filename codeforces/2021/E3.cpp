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
const int N = 4e5+10;
const ll inf = 1e18;
int n,m,p,fa[N],cnt;
int son[N][2];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
struct Edge{int u,v,w;}e[N];
int s[N],siz[N];
bool vis[N];
ll val[N];
priority_queue<ll,vector<ll>,greater<ll>> q[N];
void clear(){
    cnt = n;
    for(int i=1;i<=2*n;i++) fa[i] = i,val[i] = vis[i] = 0;
    for(int i=1;i<=2*n;i++) son[i][0] = son[i][1] = 0;
}
void dfs(int x){
    while(!q[x].empty()) q[x].pop();
    siz[x] = vis[x];
    if(x <= n){
        q[x].push(0);
        return ;
    }
    dfs(son[x][0]); siz[x] += siz[son[x][0]];
    dfs(son[x][1]); siz[x] += siz[son[x][1]];
    ll w = q[son[x][0]].top(); q[son[x][0]].pop();
    q[son[x][0]].push(w-(val[x]-val[son[x][0]])*siz[son[x][0]]);
    w = q[son[x][1]].top(); q[son[x][1]].pop();
    q[son[x][1]].push(w-(val[x]-val[son[x][1]])*siz[son[x][1]]);
    swap(q[son[x][0]],q[x]);
    if(q[x].size() < q[son[x][1]].size()) swap(q[x],q[son[x][1]]);
    while(!q[son[x][1]].empty()) q[x].push(q[son[x][1]].top()),q[son[x][1]].pop();
}
void solve(){
    n = read(); m = read(); p = read();
    clear();
    for(int i=1;i<=p;i++) s[i] = read(),vis[s[i]] = true;
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].w = read();
    }
    sort(e+1,e+1+m,[](Edge x,Edge y){return x.w < y.w;});
    for(int i=1;i<=m;i++){
        int x = e[i].u,y = e[i].v;
        x = get(x); y = get(y);
        if(x == y) continue;
        val[++cnt] = e[i].w;
        fa[x] = fa[y] = cnt;
        son[cnt][0] = x;
        son[cnt][1] = y;
    }
    dfs(cnt);
    ll ans = siz[cnt]*val[cnt];
    for(int i=1;i<=n;i++){
        if(!q[cnt].empty()) ans += q[cnt].top(),q[cnt].pop();
        cout << ans << " ";
    }
    cout << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
