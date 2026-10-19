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
const int N = 1e6+10;
const ll inf = 1e18;
int n,m,h,a[N];
vector<pii> G[N];
ll dis[N][2];
void clear(){
    for(int i=1;i<=2*n;i++) G[i].clear(),dis[i][0] = dis[i][1] = inf;
}
bool vis[N];
void dijkstra(int st,int op){
    priority_queue<pair<ll,int>> q;
    for(int i=1;i<=2*n;i++) vis[i] = false;
    dis[st][op] = 0;
    q.push(mk(0,st));
    while(!q.empty()){
        int x = q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto it : G[x]){
            int y = it.fi;
            if(dis[y][op] > dis[x][op]+it.se){
                dis[y][op] = dis[x][op]+it.se;
                q.push(mk(-dis[y][op],y));
            }
        }
    }
}
void solve(){
    n = read(); m = read(); h = read();
    
    clear();
    for(int i=1;i<=h;i++){
        a[i] = read();
        G[a[i]].push_back(mk(a[i]+n,0));
    }
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),w = read();
        G[u].push_back(mk(v,w)); G[v].push_back(mk(u,w));
        w /= 2; u += n; v += n;
        G[u].push_back(mk(v,w)); G[v].push_back(mk(u,w));
    }
    dijkstra(1,0); dijkstra(n,1);
    ll ans = inf;
    for(int i=1;i<=n;i++)
        ans = min(ans,max(min(dis[i][0],dis[i+n][0]),min(dis[i][1],dis[i+n][1])));
    if(ans == inf) ans = -1;
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
4 3 2
2 3
1 2 10
2 3 18
3 4 16
*/