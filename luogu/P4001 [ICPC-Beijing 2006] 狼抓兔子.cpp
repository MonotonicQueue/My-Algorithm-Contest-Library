#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
const int M = 6e6+10;
const int inf = 1e9;
int n,m,S,T;
int head[N],to[M],nxt[M],edge[M],tot=1;
int id(int x,int y){
	return (x-1)*m+y;
}
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
	to[++tot] = u; nxt[tot] = head[v];
	head[v] = tot; edge[tot] = w;
}
int dep[N],now[N];
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int> q;
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
int dinic(int x,int flow){
	if(x == T) return flow;
	int rest = flow;
	for(int i=now[x];i && rest;i=nxt[i]){
		now[x] = i;
		int y = to[i];
		if(dep[y] != dep[x]+1 || !edge[i]) continue;
		int k = dinic(y,min(rest,edge[i]));
		if(!k) dep[y] = 0;
		edge[i] -= k;
		edge[i^1] += k;
		rest -= k;
	}
	return flow-rest;
}
signed main(){
	n = read(); m = read();
	S = id(1,1); T = id(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++){
			int x = read();
			add_edge(id(i,j),id(i,j+1),x);
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++){
			int x = read();
			add_edge(id(i,j),id(i+1,j),x);
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++){
			int x = read();
			add_edge(id(i,j),id(i+1,j+1),x);
		}
	int mxflow = 0;
	while(bfs()) mxflow += dinic(S,1000000000);
	cout << mxflow;
    return 0;
}
