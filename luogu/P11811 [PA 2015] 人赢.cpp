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
const int N = 2e5+10;
int n,m,d;
vector<int> G[N];
int deg[N],siz[N],fa[N];
bool vis[N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
	x = get(x); y = get(y);
	if(x == y) return ;
	fa[x] = y; siz[y] += siz[x];
}
int main(){
	n = read(); m = read(); d = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		deg[u]++; deg[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(deg[i] < d) q.push(i);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int y : G[x]){
			deg[y]--;
			if(deg[y] == d-1) q.push(y);
		}
	}
	for(int i=1;i<=n;i++) vis[i] = deg[i] >= d;
	for(int i=1;i<=n;i++) if(vis[i]) fa[i] = i,siz[i] = 1;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			for(int y : G[i]){
				if(vis[y]) merge(i,y);
			}
		}
	}
	int mx = 0,pos = 0;
	for(int i=1;i<=n;i++)
		if(siz[i] > mx) mx = siz[i],pos = i;
	if(pos == 0) cout << "NIE\n";
	else{
		cout << mx << "\n";
		for(int i=1;i<=n;i++)
			if(get(i) == pos) cout << i << " ";
	}
	return 0;
}