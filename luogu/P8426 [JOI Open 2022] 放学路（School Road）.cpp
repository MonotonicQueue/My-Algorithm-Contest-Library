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
const int N = 1e5+10;
int n,m;
vector<pii> G[N];
map<int,ll> g[N];
void add(int u,int v,ll w){
    if(g[u].count(v)){
        if(g[u][v] != w) g[u][v] = g[v][u] = -1;
    }else g[u][v] = g[v][u] = w;
}
ll dis[N];
bool vis[N];
ll getdis(){
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto [y,w] : G[x])
            if(dis[y] > dis[x]+w){
                dis[y] = dis[x]+w;
                q.push(y);
            }
    }
    return dis[n];
}
void work(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(g[i].size() <= 2) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == 1 || x == n) continue;
        if(g[x].size() == 2){
            int u = g[x].begin()->fi,v = g[x].rbegin()->fi;
            add(u,v,g[x].begin()->se+g[x].rbegin()->se);
        }
        for(auto [y,_] : g[x]){
            g[y].erase(x);
            if(g[y].size() == 2) q.push(y); 
        }
        g[x].clear();
    }
    if(g[1].size() == 1 && g[1].begin()->fi == n 
    && g[1].begin()->se != -1) puts("0");
    else puts("1");
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),w = read();
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
        add(u,v,w);
    }
    add(1,n,getdis());
    work();
	return 0;
}