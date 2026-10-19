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
namespace MCMF{
	const int N = 5010;
	const int M = 1e5+10;
	const ll inf = 1e18;
	int n,m,s,t,tot=1;
	int head[N],to[M],nxt[M];
	ll edge[M],cost[M];
	inline void add_edge(int u,int v,int w,int c){
		to[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
		edge[tot] = w; cost[tot] = c;
		to[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
		edge[tot] = 0; cost[tot] = -c;
	}
	bool vis[N];
	int pre[N];
	ll d[N],incf[N];
	bool SPFA(){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) d[i] = inf;
		incf[s] = inf; d[s] = 0;
		queue<int> q;
		while(!q.empty()) q.pop();
		q.push(s);
		while(!q.empty()){
			int x = q.front(); q.pop(); vis[x] = false;
			for(int i=head[x];i;i=nxt[i]){
				int y = to[i];
				if(!edge[i]) continue;
				if(d[y] > d[x]+cost[i]){
					d[y] = d[x]+cost[i];
					incf[y] = min(incf[x],edge[i]);
					pre[y] = i;
					if(!vis[y]) q.push(y),vis[y] = true;
				}
			}
		}
		return d[t] != inf;
	}
	ll maxflow,ans;
	void update(){
		int x = t;
		maxflow += incf[t];
		ans += incf[t]*d[t];
		while(x != s){
			int i = pre[x];
			edge[i] -= incf[t];
			edge[i^1] += incf[t];
			x = to[i^1];
		}
	}
	ll MCMF(){
        while(SPFA()) update();
        return ans;
    }
}
