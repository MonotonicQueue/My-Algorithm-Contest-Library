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
const int N = 5010;
int n,s,a[N];
ll p[N],w[N];
vector<int> G[N];
int stk[N],top;
bool vis[N],iscir[N];
ll f[N][N],g[N][N];
void solve(){
    n = read(); s = read();
    for(int i=1;i<=n;i++) w[i] = read();
    for(int i=1;i<=n;i++) p[i] = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) G[a[i]].push_back(i);
    vector<int> cir;
    bool find_cir = false;
    auto getcir = [&](auto dfs0,int x)->void{
        if(vis[x]){
            int z;
            do{
                z = stk[top--];
                iscir[z] = true;
                cir.emplace_back(z);
            }while(z != x);
            find_cir = true;
            return ;
        }
        stk[++top] = x;
        vis[x] = true;
        for(int y : G[x]){
            dfs0(dfs0,y);
            if(find_cir) return ;
        }
        top--;
    };
    getcir(getcir,s);
    auto DP1 = [&](auto dfs,int x)->void{
        for(int y : G[x]){
            if(iscir[y]) continue;
            dfs(dfs,y);
        }
        f[x][0] = 0;
        for(int i=1;i<=n+5;i++){
            f[x][i] = (i & 1)*w[x]-i*p[x];
            for(int y : G[x]) if(!iscir[y]) f[x][i] += g[y][i];
            g[x][i] = max(f[x][i],g[x][i-1]);
        }
    };
    if(!iscir[s]){
        DP1(DP1,s);
        cout << max(f[s][2],f[s][1])+p[s] << "\n";
        return ;
    }
    for(int x : cir) DP1(DP1,x);
    reverse(cir.begin(),cir.end());
    if(cir.size() == 2){
        int x = cir[0],y = cir[1];
        ll ans = max(f[x][1]+f[y][0],f[x][2]+f[y][0]);
        ans = max(ans,f[x][1]+f[y][1]);
        cout << ans+p[s] << "\n";
        
        return ;
    }
    memset(g,0,sizeof(g));
    ll ans = -1e18;
    int m = cir.size();
    for(int i=0;i<=n+5;i++){
        for(int j=1;j<=m;j++){
            int x = cir[j-1];
            g[i][j] = g[i][j-1]+f[x][i];
        }
    }
    for(int i=1;i<=n+4;i++){
        ll mx = 0;
        for(int j=1;j<=m;j++){
            mx = max(mx,g[i+1][j]-g[i][j]);
            ans = max(ans,mx+g[i][j]+g[i-1][m]-g[i-1][j]);
        }
    }
    cout << ans+p[s] << "\n";
}
int main(){
	int T = 1;
    while(T--) solve();
	return 0;
}