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
const int N = 1e5+10;
const int M = 2e5+10;
int n,m;
vector<int> G[N];
int now[N];
vector<int> ans;
void dfs(int x){
	// cout << x << "\n";
	for(int i=now[x];i<G[x].size();i=now[x]){
		now[x] = i+1;
		dfs(G[x][i]);
	}
	ans.emplace_back(x);
}
int in[N],out[N];
int S,T;
bool chk(){
	for(int i=1;i<=n;i++){
		if(in[i] == out[i]) continue;
		if(in[i]-out[i] == 1){
			if(T) return false;
			T = i;
		}else if(out[i]-in[i] == 1){
			if(S) return false;
			S = i;
		}else return false;
	}
	if(!S && !T) return true;
	if(S && T) return true;
	return false;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		in[v]++; out[u]++;
		G[u].emplace_back(v);
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	if(!chk()) puts("No");
	else{
		if(!S) S = 1;
		dfs(S);
		reverse(ans.begin(),ans.end());
		for(int i : ans) cout << i << " ";
	}
	return 0;
}