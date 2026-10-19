#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 110;
int n,m;
bool a[N][N],vis[N];
int match[N];
bool dfs(int x){
    for(int y=1;y<=n;y++){
        if(!a[x][y]) continue;
        if(vis[y]) continue;
        vis[y] = true;
        if(!match[y] || dfs(match[y])){
            match[y] = x;
            return true;
        }
    }    
    return false;
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j] = 0;
    for(int i=1;i<=n;i++) match[i] = 0;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        a[u][v] = 1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) a[i][j] |= a[i][k] & a[k][j];
    int ans = n;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        ans -= dfs(i);
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
