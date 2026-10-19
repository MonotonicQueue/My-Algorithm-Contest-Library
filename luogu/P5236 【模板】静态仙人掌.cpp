#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 2e5+10;
int n,m,q,t;
struct Gragh{
	int head[N],to[N<<1],nxt[N<<1],tot;
	ll edge[N<<1];
	inline void add_edge(int u,int v,ll w){
		to[++tot] = v;
		edge[tot] = w;
		nxt[tot] = head[u];
		head[u] = tot;
	}
}G1,G2;
int dfn[N],low[N],num,cnt;
ll val[N],sum[N];
int Fa[N];
void calc(int u,int v,int Val){
	cnt++;
	ll preval = Val;
	int i = v;
	while(i != Fa[u]){
		sum[i] = preval;
		preval += val[i];
		i = Fa[i];
	}
	sum[cnt] = sum[u];
	i = v;
	sum[u] = 0;
	while(i != Fa[u]){
		ll w = min(sum[i],sum[cnt]-sum[i]);
		G2.add_edge(cnt,i,w);
		G2.add_edge(i,cnt,w);
		i = Fa[i];
	}
}
void tarjan(int x,int fr){
//	cout << x  <<" " << fr<<"\n";
	dfn[x] = low[x] = ++num;
	for(int i=G1.head[x];i;i=G1.nxt[i]){
		int y = G1.to[i];
		if(!dfn[y]){
			Fa[y] = x;
			val[y] = G1.edge[i];
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
		}else if(y != fr) low[x] = min(low[x],dfn[y]);
		if(dfn[x] < low[y]){
			G2.add_edge(x,y,G1.edge[i]);
			G2.add_edge(y,x,G1.edge[i]);
		}
	}
	for(int i=G1.head[x];i;i=G1.nxt[i]){
		int y = G1.to[i];
		if(Fa[y] == x || dfn[y] <= dfn[x]) continue;
		calc(x,y,G1.edge[i]);
	}
}
int fa[N][20],dep[N];
ll dis[N];

void dfs(int x,int fr){
//	cout << x <<"\n";
	fa[x][0] = fr;
	for(int i=1;i<=t;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	dep[x] = dep[fr]+1;
	for(int i=G2.head[x];i;i=G2.nxt[i]){
		int y = G2.to[i];
		if(y == fr) continue;
		dis[y] = dis[x]+G2.edge[i];
		dfs(y,x);
	}
}
int find(int x,int d){
	for(int i=t;i>=0;i--)
		if(d & (1ll<<i)) x = fa[x][i];
	return x;
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=t;i>=0;i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i=t;i>=0;i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n = read(); m = read(); q = read();
	t = log(n)/log(2);
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		ll w = read();
		G1.add_edge(u,v,w); G1.add_edge(v,u,w);
	}
	cnt = n;
	tarjan(1,0);
//	for(int i=1;i<=n;i++) cout <<dfn[i] <<" " << low[i] <<"\n";
	dfs(1,0);
	while(q--){
		int x = read(),y = read();
		int d = lca(x,y);
//		cout << d << "\n";
		if(d <= n){
			printf("%lld\n",dis[x]+dis[y]-2*dis[d]);
		}else{
			int X = find(x,dep[x]-dep[d]-1),Y = find(y,dep[y]-dep[d]-1);
//			cout << X << " " << Y << "\n";
			ll ans = dis[x]-dis[X]+dis[y]-dis[Y];
			if(sum[X] < sum[Y]) swap(X,Y);
			ans += min(sum[X]-sum[Y],sum[d]-sum[X]+sum[Y]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
9 10 2
1 2 1
1 4 1
3 4 1
2 3 1
3 7 1
7 8 2
7 9 2
1 5 3
1 6 4
5 6 1
1 9
5 6
*/