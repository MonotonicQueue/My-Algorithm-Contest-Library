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
const int N = 5e3+10;
const int M = 1e5+10;
int n,m,k;
int fa[N],val[N],id[N];
bool vis[M];
inline void init(){
    for(int i=1;i<=n;i++) fa[i] = i;
}
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
inline void merge(int u,int v){
    u = get(u); v = get(v);
    if(u == v) return ;
    fa[u] = v;
}
struct Edge{
    int u,v,w,id;
    bool operator < (const Edge &o)const{
        return w == o.w ? u < o.u : w < o.w;
    }
}e[M];
vector<Edge> G[N];
bool check(){
    init();
    int deg = 0;
    for(int i=1;i<=m;i++)
        if(e[i].u != 1) merge(e[i].u,e[i].v);
        else deg++;
    if(deg < k) return false;
    int cnt = 0;
    for(int i=2;i<=n;i++)
        if(fa[i] == i) cnt++;
    if(cnt > k) return false;
    for(int i=1;i<=m;i++)
        if(e[i].u == 1) merge(e[i].u,e[i].v);
    cnt = 0;
    for(int i=1;i<=n;i++)
        if(fa[i] == i) cnt++;
    return cnt == 1;
}
bool chk(int mid){
    for(int i=1;i<=m;i++)
        if(e[i].u == 1) e[i].w += mid;
    sort(e+1,e+1+m);
    init();
    int cnt = 0,ecnt = 0;
    for(int i=1;i<=m;i++){
        int u = get(e[i].u),v = get(e[i].v);
        if(u == v) continue;
        cnt += e[i].u == 1;
        ecnt++;
        merge(u,v);
        if(ecnt == n-1) break;
    }
    for(int i=1;i<=m;i++)
        if(e[i].u == 1) e[i].w -= mid;
    return cnt >= k;
}
void dfs(int x,int ft){
    fa[x] = fa[ft];
    for(auto it : G[x])
        if(it.v != ft) dfs(it.v,x);
}
int main(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].w = read(); e[i].id = i;
        if(e[i].u > e[i].v) swap(e[i].u,e[i].v);
    }
    if(!check()){
        cout << "-1";
        return 0;
    }
    int l = -1e5,r = 1e5,res = -114514;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) l = mid+1,res = mid;
        else r = mid-1;
    }
    for(int i=1;i<=m;i++)
        if(e[i].u == 1) e[i].w += res;
    sort(e+1,e+1+m);
    // for(int i=1;i<=m;i++)
    //     cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
    init();
    int cnt = 0,ecnt = 0;
    for(int i=1;i<=m;i++){
        int u = get(e[i].u),v = get(e[i].v);
        if(u == v) continue;
        cnt += e[i].u == 1;
        ecnt++;
        vis[e[i].id] = true;
        G[e[i].u].push_back(Edge{0,e[i].v,e[i].w,e[i].id});
        G[e[i].v].push_back(Edge{0,e[i].u,e[i].w,e[i].id});
        merge(u,v);
        if(ecnt == n-1) break;
    }
    // cout << cnt << "\n";
    init();
    for(auto it : G[1]){
        int v = it.v;
        val[v] = it.w; id[v] = it.id;
        fa[1] = v;
        dfs(v,1);
    }
    for(int i=1;i<=m && cnt > k;i++){
        if(vis[e[i].id] || e[i].u == 1) continue;
        int u = get(e[i].u),v = get(e[i].v);
        if(u == v) continue;
        if(e[i].w == val[u]){
            fa[u] = v; cnt--;
            vis[e[i].id] = true;
            vis[id[u]] = false;
        }else if(e[i].w == val[v]){
            fa[v] = u; cnt--;
            vis[e[i].id] = true;
            vis[id[v]] = false;
        }
    }
    if(cnt == k){
        printf("%d\n",n-1);
        for(int i=1;i<=m;i++)
            if(vis[i]) printf("%d ",i);
    }else puts("-1");
    return 0;
}