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
const int N = 1e3+10;
const int M = 1e6+10;
const ll inf = 1e15;
int n,m,p[N],S,T;
int head[M],to[M],nxt[M],tot=1;
ll edge[M],cost[M];
inline void add_edge(int u,int v,ll w,ll c){
    to[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
    edge[tot] = w; cost[tot] = c;
    to[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
    edge[tot] = 0; cost[tot] = -c;
}
bool vis[M];
int pre[M];
ll incf[M],dis[M];
bool spfa(){
    for(int i=S;i<=T;i++) vis[i] = pre[i] = 0,dis[i] = inf;
    queue<int> q; q.push(S);
    vis[S] = true; dis[S] = 0; incf[S] = 1e18;
    while(!q.empty()){
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i=head[x];i;i=nxt[i]){
            int y = to[i];
            if(!edge[i]) continue;
            if(dis[x]+cost[i] < dis[y]){
                dis[y] = dis[x]+cost[i];
                incf[y] = min(incf[x],edge[i]);
                pre[y] = i;
                if(!vis[y]) vis[y] = true,q.push(y);
            }
        }
    }
    // cout << dis[T] << "\n";
    return dis[T] != inf;
}
ll ans;
void update(){
    ans += incf[T]*dis[T];
    int x = T;
    while(x != S){
        int i = pre[x];
        edge[i] -= incf[T];
        edge[i^1] += incf[T];
        x = to[i^1];
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) p[i] = read();
    S = 0; T = n+2;
    for(int i=1;i<=n+1;i++){
        ll x = p[i-1]-p[i];
        if(x >= 0) add_edge(S,i, x,0);
        else       add_edge(i,T,-x,0);
    }
    for(int i=1;i<=m;i++){
        int s = read(),t = read(),c = read();
        add_edge(t+1,s,inf,c);
    }
    for(int i=1;i<=n;i++) add_edge(i,i+1,inf,0);
    while(spfa()) update();
    cout << ans;
	return 0;
}
