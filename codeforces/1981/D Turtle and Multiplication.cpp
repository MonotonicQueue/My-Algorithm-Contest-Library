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
const int N = 2e6+10;
const int M = 2e3+10;
int n,m;
int pr[N],cnt;
bool vis[N];
inline void init(int limit = 1e6){
	for(int i=2;i<=limit;i++){
		if(!vis[i]){
			vis[i] = true;
			pr[++cnt] = i;
		}
		for(int j=1;j<=cnt&&pr[j]*i<=limit;j++){
			vis[i*pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}
bool mp[M][M];
int now[M];
vector<int> ans;
void dfs(int x){
	for(int i=now[x];i<=m;i++){
		now[x] = i;
		if(mp[x][i]){
			mp[x][i] = mp[i][x] = 0;
			dfs(i);
		}
	}
	ans.emplace_back(x);
}
int main(){
	int T = read();
	init();
	while(T--){
		n = read();
		m = 1;
		while(m*(m+1)/2-((m&1) ? 0 : m/2-1) < n-1) m++;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++) mp[i][j] = 1;
		if(m % 2 == 0){
			for(int i=2;i<=m;i+=2)
				mp[i][i+1] = mp[i+1][i] = 0;
		}
		for(int i=1;i<=m;i++) now[i] = 1;
		ans.clear();
		dfs(1);
		for(int i=0;i<n;i++) cout << pr[ans[i]] << " ";
		cout << "\n";
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) mp[i][j] = 0; 
	}
	return 0;
}
