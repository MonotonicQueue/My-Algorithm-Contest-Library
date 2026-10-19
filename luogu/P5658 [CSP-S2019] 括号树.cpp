#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+10;
int n,fa[N];
char v[N];
vector<int>son[N];
ll h[N],w[N],ans;
void dfs(int x){
	w[x] = w[fa[x]];
	if(v[x] == '(') w[x] = x;
	else if(w[x]){
		h[x] = 1+h[fa[w[x]]];
		w[x] = w[fa[w[x]]];
	}
	for(int i=0;i<son[x].size();i++)
		dfs(son[x][i]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> v[i];
	for(int i=2;i<=n;i++){
		int fat; cin >> fat;
		fa[i] = fat;
		son[fat].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		h[i]+=h[fa[i]],ans ^= h[i]*i;
	cout << ans;
	return 0;
}