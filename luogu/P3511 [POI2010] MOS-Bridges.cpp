#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int INF = 1e9;
const int N = 1e3+10;
const int M = 2e3+10;
int n,m,deg[N];
struct node{
	int u,v,l,p;
}E[M];
int len[N],s[101000],top;
vector<pii > v[N];
void dfs(int x,int lst){
	while(len[x] < v[x].size()){
		len[x]++;
		dfs(v[x][len[x]-1].fi,v[x][len[x]-1].se);
	}
	s[++top] = lst;
}
struct Gragh{
	static const int GN = 3005;
	static const int GM = 1e5+10;
	int S,T;
	int head[GN],nxt[GM],to[GM],edge[GM],tot=1;
	inline void init(){
		tot = 1;
		memset(head,0,sizeof(head));
	}
	inline void add_edge(int u,int v,int w){
		to[++tot] = v; nxt[tot] = head[u];
		head[u] = tot; edge[tot] = w;
		to[++tot] = u; nxt[tot] = head[v];
		head[v] = tot; edge[tot] = 0;
	}
	int dep[GN],now[GN];
	bool bfs(){
		memset(dep,0,sizeof(dep));
		dep[S] = 1; now[S] = head[S];
		queue<int> q; q.push(S);
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i=head[x];i;i=nxt[i]){
				int y = to[i];
				if(dep[y] || !edge[i]) continue;
				dep[y] = dep[x]+1;
				now[y] = head[y];
				if(y == T) return true;
				q.push(y); 
			}
		}
		return false;
	}
	int dinic(int x,int flow){
		if(x == T) return flow;
		int rest = flow;
		for(int i=now[x];i && rest;i=nxt[i]){
			int y = to[i]; now[x] = i; 
			if(dep[y] != dep[x]+1 || !edge[i]) continue;
			int k = dinic(y,min(rest,edge[i]));
			if(!k) dep[y] = 0;
			rest -= k;
			edge[i] -= k;
			edge[i^1] += k;
		}
		return flow-rest;
	}
	int work(){
		int res = 0;
		while(bfs()){
			res += dinic(S,INF);
		}
		return res;
	}
	inline void build(){
		for(int x=1;x<=m;x++){
			for(int i=head[x];i;i=nxt[i]){
				int y = to[i]-m;
				if(edge[i]) continue;
//				cout << y << " " << (E[x].u == y ? E[x].v : E[x].u) << "\n";
				v[y].push_back(mk(E[x].u == y ? E[x].v : E[x].u,x));
			}
		}
	} 
}G;

bool chk(int x){
	G.init();
	for(int i=1;i<=m;i++) G.add_edge(G.S,i,1);
	for(int i=1;i<=n;i++) G.add_edge(i+m,G.T,deg[i]/2);
	for(int i=1;i<=m;i++){
		if(E[i].l <= x) G.add_edge(i,m+E[i].u,1);
		if(E[i].p <= x) G.add_edge(i,m+E[i].v,1);
	}
	return G.work() == m;
}
int main(){
	n = read(); m = read();
	G.S = 0; G.T = n+m+1;
	int l = 1,r = 1;
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),
			q = read(),p = read();
		E[i] = node{u,v,q,p};
		deg[u]++; deg[v]++;
		l = max(l,min(q,p));
		r = max(r,max(q,p));
	}
	for(int i=1;i<=n;i++) if(deg[i] & 1) return puts("NIE"),0;
	int ans = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		if(chk(mid)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	printf("%d\n",ans);
	chk(ans); G.build();
	dfs(1,0); top--;
	while(top) printf("%d ",s[top--]);
	return 0;
}