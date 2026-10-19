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
const int N = 110;
const int INF = 1<<30;
int n,m,cnt;
int S,T;
struct Gragh{
	static const int GN = 1e5+10;
	static const int GM = 5e6+10;
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
}G;
int id[N][N],sum;
signed main(){
	n = read(); m = read();
	S = 0; T = 1;
	cnt = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			id[i][j] = ++cnt;
			int x = read(); sum += x;
			G.add_edge(S,id[i][j],x);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x = read(); sum += x;
			G.add_edge(id[i][j],T,x);
		}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			int x = read(); sum += x;
			G.add_edge(S,cnt,x);
			G.add_edge(cnt,id[i][j],INF);
			G.add_edge(cnt,id[i+1][j],INF);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			int x = read(); sum += x;
			G.add_edge(cnt,T,x);
			G.add_edge(id[i][j],cnt,INF);
			G.add_edge(id[i+1][j],cnt,INF);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			cnt++;
			int x = read(); sum += x;
			G.add_edge(S,cnt,x);
			G.add_edge(cnt,id[i][j],INF);
			G.add_edge(cnt,id[i][j+1],INF);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			cnt++;
			int x = read(); sum += x;
			G.add_edge(cnt,T,x);
			G.add_edge(id[i][j],cnt,INF);
			G.add_edge(id[i][j+1],cnt,INF);
		}
	}
	printf("%lld",sum-G.work());
	return 0;
}