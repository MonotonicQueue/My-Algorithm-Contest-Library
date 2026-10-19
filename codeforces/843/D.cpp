#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e5+10;
const ll inf = 1e18;
int n,m,q;
int head[N],to[N],nxt[N],edge[N],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
}
ll dis[N];
void dijkstra(){
	priority_queue<pair<ll,int> >q;
	for(int i=2;i<=n;i++) dis[i] = inf;
	q.push(mk(0,1));
	while(!q.empty()){
		int x = q.top().se; q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(dis[y] > dis[x]+edge[i])
				dis[y] = dis[x]+edge[i],q.push(mk(-dis[y],y));
		}
	}
}
int f[N];
queue<int> s[N];
void bfs(int c){
	for(int i=2;i<=n;i++) f[i] = 1e9;
	f[1] = 0;
	s[0].push(1);
	int mx = 0;
	for(int i=0;i<=mx;i++)
		while(!s[i].empty()){
			int x = s[i].front(); s[i].pop();
			if(f[x] < i) continue;
			for(int j=head[x];j;j=nxt[j]){
				int y = to[j],w = dis[x]-dis[y]+edge[j];
				if(f[y] > f[x]+w){
					f[y] = f[x]+w;
					if(f[y] <= min(c,n-1)) s[f[y]].push(y),mx = max(mx,f[y]);
				}
			}
		}
}
int main(){
	n = read(); m = read(); q = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read();
		add_edge(u,v,w);
	}
	dijkstra();
	while(q--){
		int op = read();
		if(op == 1){
			int x = read();
			if(dis[x] == inf) cout << "-1\n";
			else cout << dis[x] << "\n";
		}else{
			int c = read();
			for(int i=1;i<=c;i++){
				int x = read();
				edge[x]++;
			}
			bfs(c);
			for(int i=1;i<=n;i++) dis[i] = min(dis[i]+f[i],inf);
		}
	}
	return 0;
}
