#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e3+10;
const int M = 1e5+10;
const int INF = 1e9;
int n,m,k,S,T;
struct node{
	int u,v,w,c;
}a[M];
int head[N],nxt[M],to[M],edge[M],cost[M],tot=1;
inline void add_edge(int u,int v,int w,int c){
	to[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
	edge[tot] = w; cost[tot] = c;
	to[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
	edge[tot] = 0; cost[tot] = -c;
}
bool vis[N];
int pre[N],incf[N],dis[N];
bool spfa(){
	memset(vis,0,sizeof(vis));
	for(int i=S;i<=T;i++) dis[i] = INF;
	queue<int> q; q.push(S);
	incf[S] = INF; dis[S] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(!edge[i]) continue;
			if(dis[y] > dis[x]+cost[i]){
				dis[y] = dis[x]+cost[i];
				pre[y] = i;
				incf[y] = min(edge[i],incf[x]);
				if(!vis[y]) vis[y] = true,q.push(y);
			}
		}
	}
	return dis[T] != INF;
}
int ans,maxflow;
void update(){
	maxflow += incf[T];
	ans += incf[T]*dis[T];
	int x = T;
	while(x != S){
		int i = pre[x];
		edge[i] -= incf[T];
		edge[i^1] += incf[T];
		x = to[i^1];
	}
}
int main(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read(),c = read();
		a[i] = node{u,v,w,c};
		add_edge(u,v,w,0);
	}
	S = 1; T = n;
	while(spfa()) update();
	printf("%d ",maxflow);
	for(int i=1;i<=m;i++)
		add_edge(a[i].u,a[i].v,INF,a[i].c);
	S = 0;
	add_edge(S,1,k,0);
	while(spfa()) update();
	printf("%d",ans);
	return 0;
}