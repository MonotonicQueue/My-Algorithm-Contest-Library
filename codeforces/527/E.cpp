#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int M = 1e6+10;
int n,m,now[N];
int head[N],to[M],nxt[M],tot=1,deg[M];
inline void add_edge(int u,int v){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot;
}
vector<int> V;
bool vis[M];
vector<int> res;
void dfs(int x){
    for(int i=now[x];i;i=now[x]){
        now[x] = nxt[i];
        if(vis[i/2]) continue;
        vis[i/2] = true;
        dfs(to[i]);
        res.push_back(i);
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        add_edge(u,v); add_edge(v,u);
        deg[u]++; deg[v]++;
    }
    for(int i=1;i<=n;i++)
        if(deg[i] & 1) V.push_back(i);
    while(!V.empty()){
        int u = V.back(); V.pop_back();
        int v = V.back(); V.pop_back();
        add_edge(u,v); add_edge(v,u);
        deg[u]++; deg[v]++; ++m;
    }
    if(m & 1) add_edge(1,1),add_edge(1,1),m++;
    for(int i=1;i<=n;i++) now[i] = head[i];
    dfs(1);
    cout << m << "\n";
    for(int i=0;i<m;i++){
        int u = to[res[i]^1],v = to[res[i]];
        if(i & 1) cout << v << " " << u << "\n";
        else cout << u << " " << v << "\n";
    }
    return 0;
}