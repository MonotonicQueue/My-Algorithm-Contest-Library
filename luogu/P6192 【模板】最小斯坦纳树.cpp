#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair 
#define fi first
#define se second
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
const int N = 110;
const int M = 1010;
int n,m,k;
int head[N],to[M],nxt[M],edge[M],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
}
int f[N][1<<10],p[N];
queue<int> q; 
bool vis[N];
void SPFA(int S){
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(f[y][S] > f[x][S]+edge[i]){
				f[y][S] = f[x][S]+edge[i];
				if(!vis[y]) q.push(y),vis[y] = true;
			}
		} 
	}
}
int main(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read();
		add_edge(u,v,w); add_edge(v,u,w);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=k;i++){
		p[i] = read();
		f[p[i]][1<<(i-1)] = 0;
	}
	int state = (1<<k)-1;
	for(int S=0;S<=state;S++){
		for(int i=1;i<=n;i++){
			for(int T=S&(S-1);T;T=(T-1)&S){
				f[i][S] = min(f[i][S],f[i][T]+f[i][S^T]);
			}
			if(f[i][S] < 1e9) q.push(i),vis[i] = true;
		}
		SPFA(S);
	}
	int ans = 1e9;
	for(int i=1;i<=n;i++) ans = min(ans,f[i][state]);
	cout << ans;
	return 0;
}