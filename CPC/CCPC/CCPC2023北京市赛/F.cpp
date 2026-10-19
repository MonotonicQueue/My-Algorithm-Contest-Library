#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pil pair<int,ll>
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
const int N = 3e5+10;
int n,m,in[N],out[N];
set<pil> G[N],E[N];
vector<pil> inn[N];
bool flag[N],er[N];
ll ans = 1e18,dis[N];
vector<int> v;
bool vis[N];
void dijkstra(int st){
    for(int x : v) dis[x] = 1e18,vis[x] = false;
    dis[st] = 0;
    priority_queue<pair<ll,int>>q;
    q.push(mk(0,st));
    while(!q.empty()){
        auto [w,x] = q.top(); q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto [v,ww] : E[x]){
            if(dis[v] > dis[x]+ww){
                dis[v] = dis[x]+ww;
                q.push(mk(-dis[v],v));
            }
            if(v == st) ans = min(ans,dis[x]+ww);
        }
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        
        ll w = read();
        if(u != v){
            G[u].insert(mk(v,w));  
            if(!in[v]) in[v] = 1;
            else in[v] = -1;
        }else ans = min(ans,w);
    }
    for(int i=1;i<=n;i++)
        if(!in[i] || G[i].size() == 0) er[i] = 1;
    for(int i=1;i<=n;i++){
        if(er[i]) continue;
        for(auto [x,w] : G[i])
            if(!er[x]) E[i].insert(mk(x,w)),inn[x].push_back(mk(i,w));
        G[i] = E[i]; E[i].clear();
    }
    for(int i=1;i<=n;i++){
        in[i] = 0;
        if(inn[i].size() == 1u) in[i] = inn[i][0].fi;
        else if(inn[i].size() > 1u) in[i] = -1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i] > 0 && G[i].size() == 1u && in[i] != i) q.push(i);
    while(!q.empty()){
        int i = q.front(); q.pop();
        if(!in[i] || G[i].size() == 0u || in[i] == i || in[i] == -1) continue;
        // cout << i << "\n";
        auto [v,w2] = *G[i].begin();
        auto it = G[in[i]].lower_bound(mk(i,0));
        auto [u,w1] = *it;
        u = in[i];
        // cout << u << " "  << v << " " << w1+w2 << "\n";
        G[u].erase(it);
        G[u].insert(mk(v,w1+w2));
        if(!in[v] || in[v] == i) in[v] = u;
        else in[v] = -1;
        G[i].clear(); in[i] = 0;
        if(in[u] > 0 && G[u].size() == 1u && in[u] != u) q.push(u);
        if(in[v] > 0 && G[v].size() == 1u && in[v] != v) q.push(v);
    }
    for(int i=1;i<=n;i++)
        if(in[i] != 0 && G[i].size()) flag[i] = true;
    for(int i=1;i<=n;i++)
        if(flag[i]) for(auto [v,w] : G[i])
        if(flag[v]){
            if(i != v) E[i].insert(mk(v,w));
            else ans = min(ans,w);
        }
    for(int i=1;i<=n;i++){
        if(!flag[i]) continue;
        v.push_back(i);
    }
    for(int x : v) dijkstra(x);
    if(ans == 1e18) cout << "-1";
    else cout << ans;
	return 0;
}
/*
6 6
1 2 1
2 3 1
3 4 1
4 1 1
4 6 1
5 3 1
*/