#include<bits/stdc++.h>
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
const int N = 5e5+10;
const int inf = 1e9;
int n;
int head[N],to[N],nxt[N],edge[N],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
}
int d[N],son[N],siz[N],dep[N];
void dfs1(int x){
	siz[x] = 1; 
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		d[y] = d[x] ^ edge[i];
		dep[y] = dep[x]+1;
		dfs1(y);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	}
}
int f[1<<22],ans[N];
void clear(int x){
	f[d[x]] = -inf;
	for(int i=head[x];i;i=nxt[i]) clear(to[i]);
}
void calc(int x,int fa){
	ans[fa] = max(ans[fa],dep[x]+f[d[x]]-dep[fa]*2);
	for(int i=0;i<22;i++)
		ans[fa] = max(ans[fa],dep[x]+f[d[x]^(1<<i)]-dep[fa]*2);
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		calc(y,fa);
	}
}
void update(int x){
	f[d[x]] = max(f[d[x]],dep[x]);
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		update(y);
	}
}
void dfs2(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == son[x]) continue;
		dfs2(y);
		clear(y);
	}
	if(son[x]) dfs2(son[x]);
	f[d[x]] = max(f[d[x]],dep[x]);
	for(int i=head[x];i;i=nxt[i]) ans[x] = max(ans[x],ans[to[i]]);

	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == son[x]) continue;
		calc(y,x); update(y);
	}
	
	ans[x] = max(ans[x],f[d[x]]-dep[x]);
	for(int i=0;i<22;i++)
		ans[x] = max(ans[x],f[d[x]^(1<<i)]-dep[x]);
}
int main(){
    n = read();
	for(int i=2;i<=n;i++){
		int fa = read();
		char ch; cin >> ch;
		add_edge(fa,i,1<<(ch-'a'));
	}
	dep[1] = 1;
	memset(f,0xcf,sizeof(f));
	dfs1(1); dfs2(1);
	// for(int i=1;i<=n;i++) cout << d[i] << " ";
	// cout << "\n";
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}