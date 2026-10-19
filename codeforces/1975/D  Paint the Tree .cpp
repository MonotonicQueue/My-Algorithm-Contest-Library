#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
int n,a,b;
vector<int> G[N];
int dep[N],maxn,f[N];
void dfs(int x,int fa){
	maxn = max(maxn,dep[x]);
	f[x] = fa;
	for(int y : G[x]){
		if(y == fa) continue;
		dep[y] = dep[x]+1;
		dfs(y,x);
	}
}
int main(){
	int T = read();
    while(T--){
        n = read();
        a = read(); b = read();
        for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int x = read(),y = read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dep[a] = 0; maxn = 0;
		dfs(a,0);
		int ans = dep[b]+(n-1)*2-maxn;
		int sum = (dep[b]+1)/2;
		for(int i=1;i<=sum;i++) b = f[b];
		dep[b] = maxn = 0;
		dfs(b,0);
		ans = min(ans,sum+2*(n-1)-maxn);
		cout << ans << "\n";
    }
	return 0;
}

