#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 5e5+10;
int n,m,q;
int fa[N];
int get(int x){
	return fa[x] != x ? fa[x] = get(fa[x]) : x;
}
char ch[N];
vector<int> G[N];
int col[N],is[N],tot,bel[N];
void dfs(int x,int c){
	bel[x] = tot;
	if(col[x] != -1 && col[x] != c){
		is[tot] = 1;
		return ;
	}else if(col[x] == c) return ;
	col[x] = c;
	for(int y : G[x]) dfs(y,c^1);
}
bool v1[N],v2[N];
int main(){
	n = read(); m = read(); q = read();
	cin >> ch+1;
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		if(ch[u] != ch[v]) fa[get(u)] = get(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) col[i] = -1;
	for(int i=1;i<=n;i++) if(!bel[i]) ++tot,dfs(i,0);
	for(int i=1;i<=m;i++){
		for(int j : G[i])
			if(ch[i] == ch[j]){
				if(ch[i] == '(') v1[get(i)] = v1[get(j)] = 1;
				else v2[get(i)] = v2[get(j)] = 1;
			}
	}
	while(q--){
		int x = read(),y = read();
		if(ch[x] == ')' || ch[y] == '(' || bel[x] != bel[y] || (!is[bel[x]] && col[x] == col[y])) cout << "0";
		else{
			if(get(x) == get(y)) cout << "1";
			else if(v1[get(x)] && v2[get(y)]) cout << "1";
			else cout << "0";
		}
	}
	return 0;
}
