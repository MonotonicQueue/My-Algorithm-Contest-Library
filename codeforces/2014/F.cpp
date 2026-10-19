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
int n,c,a[N];
vector<int> G[N];
void clear(){
    for(int i=1;i<=n;i++) G[i].clear();
}
ll f[N][2];
void dfs(int x,int fa){
    f[x][0] = 0; f[x][1] = a[x];
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += max(f[y][0],f[y][1]-2*c);
    }
}
void solve(){
    n = read(); c = read();
    for(int i=1;i<=n;i++) a[i] = read();
    clear();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    cout << max(f[1][0],f[1][1]) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
