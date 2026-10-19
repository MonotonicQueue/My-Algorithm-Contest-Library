#include<bits/stdc++.h>
#define ll long long 
using namespace std;
namespace MCMF{
    const int N = 3e6+10;
    const int M = 3e6+10;
    const ll inf = 1e18;
    int tot=1,n,S,T;
    int head[N],to[M],nxt[M];
    ll edge[M],cost[M];
    inline void add_edge(int u,int v,int w,int c){
        to[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
        edge[tot] = w; cost[tot] = c;
        to[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
        edge[tot] = 0; cost[tot] = -c;
    }
    bool vis[N];
    int pre[N];
    ll d[N],incf[N];
    bool SPFA(){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) d[i] = -inf;
        incf[S] = inf; d[S] = 0;
        queue<int> q;
        while(!q.empty()) q.pop();
        q.push(S);
        while(!q.empty()){
            int x = q.front(); q.pop(); vis[x] = false;
            for(int i=head[x];i;i=nxt[i]){
                int y = to[i];
                if(!edge[i]) continue;
                if(d[y] < d[x]+cost[i]){
                    d[y] = d[x]+cost[i];
                    // cout << x << " " << y << " " << d[x] << " " << d[y] << "\n";
                    incf[y] = min(incf[x],edge[i]);
                    pre[y] = i;
                    if(!vis[y]) q.push(y),vis[y] = true;
                }
            }
        }
        return d[T] != -inf;
    }
    ll maxflow,ans;
    void update(){
        int x = T;
        maxflow += incf[T];
        ans += incf[T]*d[T];
        while(x != S){
            int i = pre[x];
            edge[i] -= incf[T];
            edge[i^1] += incf[T];
            x = to[i^1];
        }
    }
    ll MCMF(){
        while(SPFA()) update();
        return ans;
    }
}