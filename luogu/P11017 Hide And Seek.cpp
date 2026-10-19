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
const int N = 2e5+10;
int n;
vector<int> G[N];
int dis[N][2],cnt[N];
int now;
void dfs(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        dis[y][now] = dis[x][now]+1;
        dfs(y,x);
    }
}
void solve(){
    n = read();
    int p = read(),q = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
        cnt[i] = 0;
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dis[p][0] = 0; now = 0; dfs(p,0);
    dis[q][1] = 0; now = 1; dfs(q,0);
    for(int i=1;i<=n;i++)
        if(G[i].size() > 1) for(int y : G[i]) cnt[y]++;
    auto chk = [&]() -> bool{
        for(int i=1;i<=n;i++)
            if(cnt[i] >= 3 && dis[i][0]-dis[i][1] >= 2) return true;
        return false;
    };
    puts(chk() ? "Drifty" : "hgcnxn");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}