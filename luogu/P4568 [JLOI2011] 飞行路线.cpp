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
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e6+10;
int n,m,k;
int S,T;
int head[N],to[N],nxt[N],edge[N],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v;
	edge[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
}
bool vis[N];
int d[N];
priority_queue<pair<int,int> > q;
void dijkstra(){
	memset(d,0x3f,sizeof(d));
	d[S] = 0;
	q.push(mk(0,S));
	while(!q.empty()){
		int x = q.top().se; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(d[x]+edge[i] < d[y]){
				d[y] = d[x]+edge[i];
				q.push(mk(-d[y],y));
			}
		}
	}
}
int main(){
	n = read(); m = read(); k = read();
	S = read(); T = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read();
		for(int j=0;j<=k;j++)
			add_edge(u+n*j,v+n*j,w),
			add_edge(v+n*j,u+n*j,w);
		for(int j=0;j<k;j++)
			add_edge(u+n*j,v+n*(j+1),0),
			add_edge(v+n*j,u+n*(j+1),0);
	}
	dijkstra();
	int ans = 1e9;
	for(int i=0;i<=k;i++) ans = min(ans,d[T+n*i]);
	cout << ans;
	return 0; 
}