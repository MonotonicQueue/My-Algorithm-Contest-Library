#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int mod = 998244353;
ll inv[N];
void init(int n=2e5){
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = inv[mod%i]*(mod-mod/i)%mod;
}
int n;
vector<int> G[N];
int mndis[N];
void dfs0(int x,int fa){
    if(G[x].size() == 1 && x != 1) mndis[x] = 1;
    else mndis[x] = 1e9;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs0(y,x);
        mndis[x] = min(mndis[x],mndis[y]+1);
    }
}
ll f[N];
void dfs1(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        f[y] = f[x]*(mndis[y]-1)%mod*inv[mndis[y]]%mod;
        dfs1(y,x);
    }
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=2;i<=n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1,0);
    f[1] = 1;
    dfs1(1,0);
    for(int i=1;i<=n;i++) cout << f[i] << " ";
    cout << "\n";
}
int main(){
    init();
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}