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
const int N = 1e5+10;
int n;
vector<int> G[N];
int ft[N][20],fa[N],dep[N];
void dfs0(int x,int fat){
	dep[x] = dep[fat]+1;
    ft[x][0] = fat;
    for(int i=1;i<=18;i++) ft[x][i] = ft[ft[x][i-1]][i-1];
    for(int y : G[x]){
        if(y == fat) continue;
        dfs0(y,x);
    }
}
inline int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=18;~i;i--)
        if(dep[ft[x][i]] >= dep[y]) x = ft[x][i];
    if(x == y) return x;
    for(int i=18;~i;i--)
        if(ft[x][i] != ft[y][i])
            x = ft[x][i],y = ft[y][i];
    return ft[x][0];
}
inline int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int siz[N],maxn,root,S;
bool vis[N];
void getroot(int x,int fat){
    siz[x] = 1;
    int maxpart = 0;
    for(int y : G[x]){
        if(vis[y] || y == fat) continue;
        getroot(y,x);
        siz[x] += siz[y];
        maxpart = max(maxpart,siz[y]);
    }
    maxpart = max(maxpart,S-siz[x]);
    if(maxpart < maxn) maxn = maxpart,root = x;
}
void dfs(int x,int fat){
    fa[x] = fat;
    vis[x] = true;
    for(int y : G[x]){
        if(vis[y]) continue;
        S = maxn = siz[y];
        getroot(y,x);
        dfs(root,x);
    }
}
int col[N];
struct Prique{
	priority_queue<int> q,v;
    inline void chk(){
        while(!v.empty() && q.top() == v.top()) q.pop(),v.pop();
    }
    inline int top(){
        chk();
        return q.empty() ? -1 : q.top();
    }
    inline void erase(int x){
        v.emplace(x);
        chk();
    }
    inline void push(int x){
        q.emplace(x);
    }
    inline bool empty(){
        chk();
        return q.empty();
    }
}p[N],q[N],ans;
void calc(int x){
    for(int y=x;fa[y];y=fa[y]){
        if(!p[fa[y]].empty()){
            int mx = p[fa[y]].top();
            p[fa[y]].erase(mx);
            if(!p[fa[y]].empty()) ans.erase(mx+p[fa[y]].top());
            p[fa[y]].push(mx);
        }
        if(!q[y].empty()) p[fa[y]].erase(q[y].top());
        if(col[x]) q[y].erase(dis(x,fa[y]));
        else q[y].push(dis(x,fa[y]));
        if(!q[y].empty()) p[fa[y]].push(q[y].top());
        if(!p[fa[y]].empty()){
            int mx = p[fa[y]].top();
            p[fa[y]].erase(mx);
            if(!p[fa[y]].empty()) ans.push(mx+p[fa[y]].top());
            p[fa[y]].push(mx);
        }
    }
}
int main(){
    n = read(); 
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    S = maxn = n;
    getroot(1,0);
	dfs0(root,0);
	dfs(root,0);
//    for(int i=1;i<=n;i++) cout << fa[i] << "\n";
    for(int i=1;i<=n;i++) calc(i);
    int Q = read();
    int sum = n;
    while(Q--){
        char op; cin >> op;
        if(op == 'C'){
            int x = read();
            col[x] ^= 1;
            sum += col[x] ? -1 : 1;
            calc(x);
        }else{
            if(sum >= 2) cout << ans.top() << "\n";
            else if(sum == 1) cout << "0\n";
            else cout << "-1\n";
        }
    }
	return 0;
}
