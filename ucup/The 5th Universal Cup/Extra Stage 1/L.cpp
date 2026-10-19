#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
const ll inf = 1e18;
int n,m,a[N];
ll dis[N];
int t[N*30][2],cnt,ed[N*30];
void insert(int x,int id){
    int p = 1;
    for(int i=29;~i;i--){
        int c = (x >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c];
    }
    ed[p] = id;
}
bool vis[N],vis2[N*30];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
inline void add(int x,ll val){
    if(!x) return ;
    if(val+a[x] < dis[x]){
        dis[x] = val+a[x];
        q.push(mk(dis[x]+a[x],x));
    }
}
void dfs(int x,ll val){
    if(!x || vis2[x]) return ;
    vis2[x] = true;
    if(ed[x]) add(ed[x],val);
    dfs(t[x][0],val); 
    dfs(t[x][1],val);
}
void work(int x,ll val){
    int p = 1;
    for(int i=29;~i;i--){
        int c = (x >> i) & 1,d = (m >> i) & 1;
        if(d) dfs(t[p][c],val);
        p = t[p][c^d];
        if(ed[p]) add(ed[p],val);
    }
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=cnt;i++){
        t[i][0] = t[i][1] = 0;
        ed[i] = vis2[i] = 0;
    }
    cnt = 1;
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) insert(a[i],i);
    for(int i=1;i<=n;i++) dis[i] = inf,vis[i] = 0;
    dis[1] = 0;
    q.push(mk(dis[1]+a[1],1));
    while(!q.empty()){
        auto [d,x] = q.top(); q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        work(a[x],d);
    }
    if(dis[n] < inf) cout << dis[n] << "\n";
    else puts("-1");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}