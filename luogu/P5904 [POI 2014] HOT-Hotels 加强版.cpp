#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n;
vector<int> G[N];
int mxd[N],son[N];
void dfs(int x,int fa){
    mxd[x] = 0;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        mxd[x] = max(mxd[x],mxd[y]+1);
        if(mxd[y] >= mxd[son[x]])
            son[x] = y;
    }
}
ll tmp1[N<<2],tmp2[N<<2],*id1=tmp1,*id2=tmp2;
ll *f[N],*g[N],ans;
/*
f_{x,i} 距离 x 为 i 的点的个数
g_{x,i} dep_y/z-dep_{lca(y,z)}=i+dis_{x,lca}
*/
void DP(int x,int fa){
    if(son[x]){
        f[son[x]] = f[x]+1;
        g[son[x]] = g[x]-1;
        DP(son[x],x);
        ans += g[x][0];
    }
    f[x][0] = 1;
    for(int y : G[x]){
        if(y == fa || y == son[x]) continue;
        f[y] = id1; id1 += mxd[y]+1;
        id2 += mxd[y]+1; g[y] = id2; id2 += mxd[y]+1;
        DP(y,x);
        int cur = mxd[y];
        for(int i=0;i<=cur;i++){
            if(i) ans += f[x][i-1]*g[y][i];
            ans += g[x][i+1]*f[y][i];
        }
        for(int i=0;i<=cur;i++) g[x][i+1] += f[x][i+1]*f[y][i];
        for(int i=0;i<=cur;i++) f[x][i+1] += f[y][i];
        for(int i=1;i<=cur;i++) g[x][i-1] += g[y][i];
    }
}
int main(){
    n = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    f[1] = id1; id1 += mxd[1]+1;
    id2 += mxd[1]+1; g[1] = id2; id2 += mxd[1]+1;
    DP(1,0);
    cout << ans << "\n";
    return 0;
}