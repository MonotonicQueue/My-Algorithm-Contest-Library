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
const int inf = 1e9;
int n,col[N];
int f[N][2][2];
vector<int> G[N];
void dfs(int x,int fa){
    f[x][0][0] = f[x][1][0] = 0;
    f[x][0][1] = f[x][1][1] = inf;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        int g[2][2] = {inf,inf,inf,inf};
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
                    g[i][j^k] = min(g[i][j^k],f[x][i][j]+f[y][i][k]);
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++) f[x][i][j] = g[i][j];
    }
    int g[2][2] = {inf,inf,inf,inf};
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++){
            int c = col[x]^j;
            if(i == c) g[i][j] = min(g[i][j],f[x][i][j]);
            else g[i][j^1] = min(g[i][j^1],f[x][i][j]+1);
        }
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++) g[i][j] = min(g[i][j],g[i^1][j]+1);
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++) f[x][i][j] = g[i][j];
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) col[i] = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    cout << min(f[1][1][0],f[1][1][1]);
    return 0;
}