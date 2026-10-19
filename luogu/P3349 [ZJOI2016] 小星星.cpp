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
const int N = 20;
int n,m;
bool vis[N][N];
vector<int> G[N];
ull ans,f[N][N];
int pos[N],cnt;
void dfs(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
    }
    for(int i=1;i<=cnt;i++){
        int p = pos[i];
        f[x][p] = 1;
        for(int y : G[x]){
            if(y == fa) continue;
            ull mul = 0;
            for(int j=1;j<=cnt;j++){
                int q = pos[j];
                if(vis[p][q]) mul += f[y][q]; 
            }
            f[x][p] *= mul;
        }
    }
}
inline void solve(int state){
    cnt = 0;
    for(int i=0;i<n;i++)
        if((state >> i) & 1) pos[++cnt] = i+1;
    dfs(1,0);
    for(int i=1;i<=cnt;i++) ans += (((n-cnt) & 1) ? -1 : 1)*f[1][pos[i]];
}
int main(){
    n = read(); m = read();
    while(m--){
        int u = read(),v = read();
        vis[u][v] = vis[v][u] = true;
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=0;i<(1<<n);i++) solve(i);
    cout << ans;
	return 0;
}
