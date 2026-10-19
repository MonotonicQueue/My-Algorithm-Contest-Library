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
int n,Q;
struct Data{
	int op,u,v;
};
vector<Data> q;
vector<int> G[N];
int dep[N],fa[N],st[N],tot,siz[N];
void dfs(int x,int ft){
	fa[x] = ft;
	dep[x] = dep[ft]+1;
	st[x] = ++tot;
	siz[x] = 1;
	for(int y : G[x]){
		if(y == ft) continue;
		dfs(y,x);
		siz[x] += siz[y];
	}
}
int bel[N],t[N];
inline void add(int x,int y){
	if(!x) return ;
	while(x <= n){
		t[x] += y;
		x += x&(-x);
	}
}
inline int ask(int x){
	int res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
inline int query(int x){
	return ask(st[x]+siz[x]-1)-ask(st[x]-1);
}
inline void init(){
	for(int i=1;i<=n;i++) bel[i] = i;
	for(int i=1;i<=n;i++){
		add(st[i],1);
		add(st[fa[i]],-1);
	}
}
int get(int x){
	return bel[x] == x ? x : bel[x] = get(bel[x]);
}
int main(){
	n = read(); Q = read();
	while(Q--){
		char op; cin >> op;
		int u = read(),v = read();
		q.push_back(Data{op == 'Q',u,v});
		if(op == 'A')
			G[u].push_back(v),
			G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!st[i]) dfs(i,0);
	init();
	for(auto [op,u,v] : q){
		if(dep[u] > dep[v]) swap(u,v);
		int z = get(u);
		if(!op){
			bel[v] = u;
			int s = query(v);
			add(st[u],s);
			add(st[fa[z]],-s);
		}else{
			int s1 = query(z),s2 = query(v);
			cout << 1ll*(s1-s2)*s2 << "\n";
		}
	}
	return 0;
}