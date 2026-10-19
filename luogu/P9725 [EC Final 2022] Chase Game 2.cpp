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
int n,p[N];
vector<int> G[N];
int cnt[N];
void dfs(int x,int fa){
    p[x] = fa;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
    }
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) G[i].clear(),cnt[i] = 0;
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n == 2) return puts("-1"),void();
    int rt = 0;
    for(int i=1;i<=n;i++)
        if(G[i].size() > 1) rt = i;
    dfs(rt,0);
    int sum = 0;
    for(int i=1;i<=n;i++)
        if(G[i].size() == 1) cnt[p[i]]++,sum++;
    sort(cnt+1,cnt+1+n,greater<int>());
    if(cnt[1] == n-1) return puts("-1"),void();
    if(cnt[1] > sum/2) cout << cnt[1] << "\n";
    else cout << (sum+1)/2 << "\n";
}
int main(){
	int T = read();
    while(T--) solve();
	return 0;
}