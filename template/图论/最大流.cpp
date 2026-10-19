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
namespace MF{
	const int N = 210;
	const int M = 10100;
	const ll inf = 1e18;
	int n,m,S,T,tot=1;
	int head[N],to[M],nxt[M];
	ll edge[M];
	inline void add_edge(int u,int v,ll z){
		to[++tot] = v; nxt[tot] = head[u];
		head[u] = tot; edge[tot] = z;
		to[++tot] = u; nxt[tot] = head[v];
		head[v] = tot; edge[tot] = 0;
	}
	int now[N],dep[N];
	bool bfs(){
		memset(dep,0,sizeof(dep));
		queue<int> q;
		while(!q.empty()) q.pop();
		dep[S] = 1; now[S] = head[S];
		q.push(S);
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i=head[x];i;i=nxt[i]){
				int y = to[i];
				if(!edge[i] || dep[y]) continue;
				dep[y] = dep[x]+1;
				now[y] = head[y];
				if(y == T) return true;
				q.push(y);
			}
		}
		return false;
	}
	ll dinic(int x,ll flow){
		if(x == T) return flow;
		ll rest = flow;
		for(int i=now[x];i && rest;i=nxt[i]){
			now[x] = i;
			int y = to[i];
			if(dep[y] != dep[x]+1 || !edge[i]) continue;
			ll k = dinic(y,min(rest,edge[i]));
			if(!k) dep[y] = 0;
			edge[i] -= k;
			edge[i^1] += k;
			rest -= k;
		}
		return flow-rest;
	}
	ll MF(){
		ll ans = 0;
		while(bfs()) ans += dinic(S,inf);
		return ans;
	}
}