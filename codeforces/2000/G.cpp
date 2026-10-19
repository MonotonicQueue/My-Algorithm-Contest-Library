#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned long long
#define pii pair<ll,ll>
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
const int inf = 1e18;
int n,m;
ll t0,t1,t2;
struct Edge{
    ll v,l1,l2;
}e[N]; int tot;
vector<int> G[N];
ll dis[N];
bool vis[N];
bool chk(int st){
    for(int i=1;i<=n;i++) dis[i] = inf,vis[i] = false;
    dis[1] = st;
    priority_queue<pii> q;
    q.push(mk(-st,1));
    while(!q.empty()){
        int x = q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(int i : G[x]){
            int y = e[i].v,l1 = e[i].l1,l2 = e[i].l2;
            if(dis[x]+l1 <= t1 || dis[x] >= t2){
                if(dis[x]+l1 < dis[y]){
                    dis[y] = dis[x]+l1;
                    q.push(mk(-dis[y],y));
                }
            }else{
                int d = min(t2+l1,dis[x]+l2);
                if(d < dis[y]){
                    dis[y] = d;
                    q.push(mk(-dis[y],y));
                }
            }
        }
    }
    return dis[n] <= t0;
}
signed main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) G[i].clear();
        t0 = read(); t1 = read(); t2 = read();
        tot = 0;
        for(int i=1;i<=m;i++){
            int u = read(),v = read(),l1 = read(),l2 = read();
            e[++tot] = {v,l1,l2};
            G[u].push_back(tot);
            e[++tot] = {u,l1,l2};
            G[v].push_back(tot);
        }
        int l = 0,r = t0,res = -1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(chk(mid)) l = mid+1,res = mid;
            else r = mid-1;
        }
        cout << res << "\n";
    }
    return 0;
}
/*
1
4 4
100 40 60
1 2 30 100
2 4 30 100
1 3 20 50
3 4 20 50
*/