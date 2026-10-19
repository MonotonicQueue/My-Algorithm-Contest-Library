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
const int N = 1e6+10;
int n,m,k;
int head[N],nxt[N],to[N],edge[N],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v;
	edge[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
}
priority_queue<pair<int,int> > q;
int t[N];
bool vis[N]; 
void dijkstra(){
	q.push(mk(0,1));
	memset(t,0x3f,sizeof(t));
	t[1] = 0;
	while(!q.empty()){
		int x = q.top().se; q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(t[x]+edge[i] < t[y]){
				t[y] = t[x]+edge[i];
				q.push(mk(-t[y],y));
			}
		}
	}
}
int main(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read();
		for(int j=0;j<=k;j++)
			add_edge(u+j*n,v+j*n,w),
			add_edge(v+j*n,u+j*n,w);
		for(int j=0;j<k;j++)
			add_edge(u+j*n,v+(j+1)*n,w/2),
			add_edge(v+j*n,u+(j+1)*n,w/2);
	}
	dijkstra();
	int ans = 1e9;
	for(int i=0;i<=k;i++) ans = min(ans,t[n+i*n]);
	cout << ans;
	return 0; 
}