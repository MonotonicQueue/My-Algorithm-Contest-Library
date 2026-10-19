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
int n,m;
vector<int> G[N];
int col[N]; bool vis[N],flag;
void clear(){
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=n;i++) vis[i] = col[i] = 0;
    flag = 0;
}
void dfs(int x,int fa){
    vis[x] = true;
    col[x] = col[fa];
    for(int y : G[x]){
        if(y == fa) continue;
        if(vis[y] && !flag)
            col[x] = 1,flag = true;
    }
    for(int y : G[x]) if(!vis[y]) dfs(y,x);
}
void work(){
    dfs(1,0);
    if(!flag) return puts("-1"),void();
    for(int i=1;i<=n;i++)
        if(!vis[i]) return puts("-1"),void();
    for(int i=1;i<=n;i++) putchar(col[i] ? 'B' : 'W');
    putchar('\n');
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        clear();
        for(int i=1;i<=m;i++){
            int u = read(),v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        work();
    }
    return 0;
}
