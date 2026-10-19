#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e3+10;
const int M = 1e4+10;
const ll inf = 1e18;
int n,s,t,k,t1,t2;
int head[N],to[M*2],nxt[M*2],pre[N],tot=1;
ll edge[M*2],cost[M*2];
bool id[M];
inline void add_edge(int u,int v,ll z,ll c){
	to[++tot] = v; nxt[tot] = head[u]; id[tot] = 1;
	head[u] = tot; edge[tot] = z; cost[tot] = c;
	to[++tot] = u; nxt[tot] = head[v];
	head[v] = tot; edge[tot] = 0; cost[tot] = -c;
} 
bool vis[N]; ll d[N],incf[N];
bool spfa(){
	memset(d,0xcf,sizeof(d));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s); vis[s] = true;
	incf[s] = inf; d[s] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(!edge[i]) continue;
			if(d[y] < d[x]+cost[i]){
				d[y] = d[x]+cost[i];
				incf[y] = min(incf[x],edge[i]);
				pre[y] = i;
				if(!vis[y]) vis[y] = true,q.push(y);
			}
		}
	}
	if(d[t] == 0xcfcfcfcfcfcfcfcf) return false;
	return true;
}
ll maxflow,maxcost;
void update(){
	int x = t;
	while(x != s){
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i^1] += incf[t];
		x = to[i^1];
	}
	maxflow += incf[t];
	maxcost += d[t]*incf[t];
}
char ans[N];
ll a[N],b[N],sum;
signed main(){
	n = read(); k = read();
	t1 = read(); t2 = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum += a[i];
	}
	for(int i=1;i<=n;i++){
		b[i] = read();
		b[i] -= a[i];
	}
	s = 0; t = n+1;
	for(int i=1;i<=k;i++)
		add_edge(s,i,inf,0);
	for(int i=1;i<=n;i++){
		if(i != n) add_edge(i,i+1,k-t1-t2,0);
		else add_edge(i,t,k-t1-t2,0);
		if(i+k <= n) add_edge(i,i+k,1,b[i]);
		else add_edge(i,t,1,b[i]);
	}
	s = n+2;
	add_edge(s,0,k-t1,0);
	while(spfa()) update();
	cout << sum+maxcost << "\n";
	for(int x=1;x<=n;x++){
		for(int i=head[x];i;i=nxt[i])
			if((to[i] == x+k || to[i] == t) && edge[i] && cost[i] == b[x]) ans[x] = 'S';
	}
	for(int i=1;i<=n;i++)
		if(ans[i] == 'S') cout << 'S';
		else cout << 'E';
	return 0;
}