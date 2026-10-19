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
int main(){
    int n = read();
    vector<vector<int>> G(n+1);
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> mxd(n+1),son(n+1);
    auto dfs = [&](auto self,int x,int fa)->void{
        mxd[x] = 0;
        for(int y : G[x]){
            if(y == fa) continue;
            self(self,y,x);
            if(mxd[y] >= mxd[son[x]])
                son[x] = y,mxd[x] = mxd[y]+1;
        }
    };
    dfs(dfs,1,0);
    vector<int> f(n+1),p(n+1),ans(n+1);
    int tot = 0;
    auto DP = [&](auto self,int x,int fa)->void{
        f[p[x] = ++tot] = 1;
        if(!son[x]) return ans[x] = 0,void();
        self(self,son[x],x);
        ans[x] = ans[son[x]]+1;
        for(int y : G[x]){
            if(y == fa || y == son[x]) continue;
            self(self,y,x);
            int cur = mxd[y];
            for(int i=0;i<=cur;i++)
                f[p[x]+i+1] += f[p[y]+i];
            for(int i=1;i<=cur+1;i++)
                if(f[p[x]+i] > f[p[x]+ans[x]] ||
                 (f[p[x]+i] == f[p[x]+ans[x]] && i < ans[x])) ans[x] = i;
        }
        if(f[p[x]] >= f[p[x]+ans[x]]) ans[x] = 0;
    };
    DP(DP,1,0);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}