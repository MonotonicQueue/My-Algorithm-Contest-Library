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
const int N = 5e5+10;
int n,dep[N],mxdep[N];
vector<int> G[N];
void dfs(int x,int fa){
    dep[x] = dep[fa]+1;
    mxdep[x] = dep[x];
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        mxdep[x] = max(mxdep[x],mxdep[y]);
    }
}
int cnt1[N],cnt2[N];
signed main(){
	int T = read();
	while(T--){
		n = read();
        for(int i=0;i<=n+1;i++){
            G[i].clear();
            cnt1[i] = cnt2[i] = 0;
        }
        for(int i=1;i<n;i++){
            int u = read(),v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++) cnt1[dep[i]]++;
        for(int i=1;i<=n;i++) cnt2[mxdep[i]]++;
        for(int i=n;i;i--) cnt1[i] += cnt1[i+1];
        for(int i=1;i<=n;i++) cnt2[i] += cnt2[i-1];
        int ans = 1e9;
        for(int i=1;i<=n;i++)
            ans = min(ans,cnt2[i-1]+cnt1[i+1]);
        cout << ans << "\n";
	}
    return 0;
}