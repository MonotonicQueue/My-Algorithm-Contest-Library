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
const int N = 1100;
const int M = 1e5+10;
const ll inf = 1e9;
int n;
int S,T,tot=1;
int head[N],to[M],nxt[M];
ll edge[M],a[N];
inline void add_edge(int u,int v,int z){
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
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    S = 0; T = n+61;
    for(int i=0;i<=T;i++) head[i] = 0;
    tot = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<60;j++) if((a[i] >> j) & 1) add_edge(i,n+j+1,inf);
    }
    for(int i=1;i<=n;i++) add_edge(S,i,1);
    for(int i=0;i<=59;i++) add_edge(i+n+1,T,1);
    int ans = n;
    while(bfs()) ans -= dinic(S,inf);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
