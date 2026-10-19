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
const int N = 4100;
const int M = 1e5+10;
const int inf = 1e9;
int n,m,s,t;
int head[N],to[M*2],nxt[M*2],tot=1,pre[N];
ll cost[M*2],edge[M*2];
inline void add_edge(int u,int v,ll w,ll c){
	to[++tot] = v; edge[tot] = w; cost[tot] = c;
	nxt[tot] = head[u]; head[u] = tot;
	to[++tot] = u; edge[tot] = 0; cost[tot] = -c;
	nxt[tot] = head[v]; head[v] = tot;
}
ll d[N],incf[N];
bool vis[N];
bool spfa(){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s); d[s] = 0; vis[s] = true;
	incf[s] = inf;
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(!edge[i]) continue;
			if(d[y] > d[x]+cost[i]){
				d[y] = d[x]+cost[i];
				incf[y] = min(incf[x],edge[i]);
				pre[y] = i;
				if(!vis[y]){
					vis[y] = true;
					q.push(y);
				}
			}
		}
	}
	if(d[t] == 0x3f3f3f3f3f3f3f3f) return false;
	return true;
}
ll maxflow,ans;
void update(){
	int x = t;
	while(x != s){
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i^1] += incf[t];
		x = to[i^1];
	}
	maxflow += incf[t];
	ans += incf[t]*d[t]; 
}
int main(){
	n = read();
	s = 0; t = 2*n+1;
	for(int i=1;i<=n;i++){
		int x = read();
		add_edge(s,i+n,x,0);
		add_edge(i,t,x,0);
	}
	for(int i=1;i<n;i++) add_edge(i,i+1,inf,0);
	ll x = read(),y;
	for(int i=1;i<=n;i++)
		add_edge(s,i,inf,x);
	x = read(); y = read();
	for(int i=1;i+x<=n;i++)
		add_edge(i+n,i+x,inf,y);
	x = read(); y = read();
	for(int i=1;i+x<=n;i++)
		add_edge(i+n,i+x,inf,y);
	while(spfa()) update();
	cout << ans;
	return 0;
}