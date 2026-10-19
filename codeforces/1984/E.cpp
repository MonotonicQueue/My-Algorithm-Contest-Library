#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n;
vector<int> G[N];
inline void clear(){
    for(int i=1;i<=n;i++) G[i].clear();
}
int f[N][2],g[N][2];
void dfs1(int x,int fa){
    f[x][1] = 1; f[x][0] = 0;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs1(y,x);
        f[x][0] += max(f[y][0],f[y][1]);
        f[x][1] += f[y][0];
    }
}
void dfs2(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        g[y][0] = f[y][0]+max(g[x][0]-max(f[y][0],f[y][1]),g[x][1]-f[y][0]);
        g[y][1] = f[y][1]+g[x][0]-max(f[y][0],f[y][1]);
        dfs2(y,x);
    }
}
int main(){
	int T = read();
    while(T--){
        n = read();
        clear();
        for(int i=1;i<n;i++){
            int u = read(),v = read();
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs1(1,0);
        g[1][0] = f[1][0]; g[1][1] = f[1][1];
        dfs2(1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
            if(G[i].size() == 1) ans = max(ans,g[i][0]+1);
        cout << ans << "\n";
    }
	return 0;
}

