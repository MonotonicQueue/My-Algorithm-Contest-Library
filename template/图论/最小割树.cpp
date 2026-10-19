#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 510;
const int M = 2e4+10;
const ll inf = 1e18;
int n,m;
vector<pii> G[N];
namespace GHT{
int S,T,tot=1;
int head[N],to[M],nxt[M];
ll edge[M];
inline void add_edge(int u,int v,int z){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot; edge[tot] = z;
    to[++tot] = u; nxt[tot] = head[v];
    head[v] = tot; edge[tot] = 0;
}
void rebuild(int s,int t){
    S = s,T = t;
    for(int i=2;i<=tot;i+=2){
        edge[i] += edge[i^1];
        edge[i^1] = 0;
    }
}
int now[N],dep[N];
bool bfs(){
    memset(dep,0,sizeof(dep));
    queue<int> q;
    while(!q.empty()) q.pop();
    dep[S] = 1; now[S] = head[S];
    q.push(S);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=head[x];i;i=nxt[i]){
            int y = to[i];
            if(!edge[i] || dep[y]) continue;
            dep[y] = dep[x]+1;
            now[y] = head[y];
            if(y == T) return true;
            q.push(y);
        }
    }
    return false;
}
ll dinic(int x,ll flow){
    if(x == T) return flow;
    ll rest = flow;
    for(int i=now[x];i && rest;i=nxt[i]){
        now[x] = i;
        int y = to[i];
        if(dep[y] != dep[x]+1 || !edge[i]) continue;
        ll k = dinic(y,min(rest,edge[i]));
        if(!k) dep[y] = 0;
        edge[i] -= k;
        edge[i^1] += k;
        rest -= k;
    }
    return flow-rest;
}
ll MF(){
    ll ans = 0;
    while(bfs()) ans += dinic(S,inf);
    return ans;
}
bool flag[N],vis[N];
void dfs(int x){
    vis[x] = true;
    for(int i=head[x];i;i=nxt[i]){
        int y = to[i];
        if(!vis[y] && edge[i])
            dfs(y);
    }
}
void solve(vector<int> v){
    if(v.size() == 1) return ;
    int s = v[0],t = v[1];
    rebuild(s,t);
    int val = MF();
    G[s].emplace_back(t,val);
    G[t].emplace_back(s,val);
    for(int i=0;i<=n;i++) vis[i] = false;
    dfs(s);
    vector<int> vl,vr;
    for(int x : v)
        if(vis[x]) vl.push_back(x);
        else vr.push_back(x);
    solve(vl); solve(vr);
}
}
int fa[N][12],mn[N][12],dep[N];
void dfs(int x,int ft){
    dep[x] = dep[ft]+1;
    for(int i=1;i<=10;i++)
        fa[x][i] = fa[fa[x][i-1]][i-1],
        mn[x][i] = min(mn[x][i-1],mn[fa[x][i-1]][i-1]);
    for(auto [y,w] : G[x]){
        if(y == ft) continue;
        fa[y][0] = x;
        mn[y][0] = w;
        dfs(y,x);
    }
}
int get(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    int res = 1e9;
    for(int i=10;~i;i--)
        if(dep[fa[x][i]] >= dep[y])
            res = min(res,mn[x][i]),x = fa[x][i];
    if(x == y) return res;
    for(int i=10;~i;i--)
        if(fa[x][i] != fa[y][i])
            res = min(res,min(mn[x][i],mn[y][i])),
            x = fa[x][i],y = fa[y][i];
    return min(res,min(mn[x][0],mn[y][0]));
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),w = read();
        GHT::add_edge(u,v,w);
        GHT::add_edge(v,u,w);
    }
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    GHT::solve(v);
    dfs(1,0);
    int Q = read();
    while(Q--){
        int x = read(),y = read();
        cout << get(x,y) << "\n";
    }
	return 0;
}