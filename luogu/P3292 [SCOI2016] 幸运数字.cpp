#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e4+10;
int n,Q;
int head[N],to[N*2],nxt[N*2],tot;
ll G[N],p[N][65];
inline void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int dep[N],fa[N][20],t,pos[N][65];
void insert(int id){
	ll x = G[id];int y = id;
	for(int i=60;i>=0;i--)
		if((x>>i) & 1){
			if(!p[id][i]){p[id][i] = x; pos[id][i] = y;return;}
			if(dep[y] > dep[pos[id][i]]){
				swap(x,p[id][i]);
				swap(y,pos[id][i]); 
			}
			x ^= p[id][i];
		}
}
void dfs(int x,int father){
	dep[x] = dep[father]+1;
	fa[x][0] = father;
	for(int i=1;i<=t;i++)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=0;i<=60;i++)
		p[x][i] = p[father][i],pos[x][i] = pos[father][i];
	insert(x);
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == father) continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=t;i>=0;i--)
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if(x == y) return x;
	for(int i=t;i>=0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
ll c[N];
signed main(){
	n = read(); Q = read();
	for(int i=1;i<=n;i++) G[i] = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		add(u,v); add(v,u);
	}
	t = log(n)/log(2);
	dfs(1,0);
	while(Q--){
		int x = read(),y = read();
		int d = lca(x,y);
		//cout << d <<"\n";
		for(int i=0;i<=60;i++)
			if(dep[pos[x][i]] >= dep[d]) c[i] = p[x][i];
			else c[i] = 0;
		for(int i=0;i<=60;i++){
			if(dep[pos[y][i]] < dep[d] || !p[y][i]) continue;
			ll z = p[y][i];
			for(int j=i;j>=0;j--)
				if(((z>>j) & 1)){
					if(!c[j]){c[j] = z; break;}
					z ^= c[j];
				}
		}
		ll ans = 0;
		for(int i=60;i>=0;i--)
			ans = max(ans,ans^c[i]);
		printf("%lld\n",ans);
	}
	return 0;
} 
