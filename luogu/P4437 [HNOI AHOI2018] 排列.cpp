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
const int N = 5e5+10;
int n,fa[N],Fa[N];
vector<int> G[N];
bool vis[N],flag;
void dfs(int x){
    if(vis[x]) flag = true;
    if(flag) return ;
    vis[x] = true;
    for(int y : G[x]) dfs(y);
}
int get(int x){
    return Fa[x] == x ? x : Fa[x] = get(Fa[x]);
}
ll f[N],g[N];
priority_queue<pair<long double,int> >q;
int main(){
    n = read();
    for(int i=1;i<=n;i++) fa[i] = read();
    for(int i=1;i<=n;i++) Fa[i] = i;
    g[0] = 1;
    for(int i=1;i<=n;i++) f[i] = read(),g[i] = 1;
    for(int i=1;i<=n;i++) G[fa[i]].push_back(i);
    dfs(0);
    if(flag || !G[0].size()){
        printf("-1");
        return 0;
    }
    for(int i=1;i<=n;i++) q.push(mk(-(long double)f[i]*1.0/g[i],i)),vis[i] = false;
    ll ans = 0;
    while(!q.empty()){
        int x = q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        int t = get(fa[x]);
        // cout << x << " " << t << "\n";
        ans += g[t]*f[x];
        f[t] += f[x];
        g[t] += g[x];
        Fa[x] = t;
        if(t) q.push(mk(-(long double)f[t]*1.0/g[t],t));
    }
    cout << ans;
	return 0;
}
