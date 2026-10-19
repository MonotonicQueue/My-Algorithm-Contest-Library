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
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 1e5+10;
const int M = 1e7+10;
const int inf = 1e9;
int n,m,tot=1,S,T;
int p[45],sum,a[45][110];
int head[N],nxt[M],to[M],edge[M],cost[M];
inline void add_edge(int u,int v,int w,int c){
	to[++tot] = v; nxt[tot] = head[u]; head[u] = tot; edge[tot] = w; cost[tot] = c;
	to[++tot] = u; nxt[tot] = head[v]; head[v] = tot; edge[tot] = 0; cost[tot] = -c;
}
int d[N],incf[N],pre[N];
bool vis[N];
bool spfa(){
	queue<int>q;
	for(int i=S;i<=T;i++) d[i] = inf,vis[i] = 0;
	d[S] = 0; incf[S] = inf;
	q.push(S); 
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
				if(!vis[y]) vis[y] = true,q.push(y);
			}
		}
	} 
	if(d[T] == inf) return false;
	return true;
}
int maxflow,ans;
void update(){
	int x = T;
//	cout << incf[T] << " "<< d[T] <<"\n";
	while(x != S){
		int i = pre[x];
		edge[i] -= incf[T];
		edge[i^1] += incf[T];
		x = to[i^1];
	}
	maxflow += incf[T];
	ans += incf[T]*d[T];
}
int main(){
//	freopen("delicacy.in","r",stdin);
//	freopen("delicacy.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=n;i++) sum += p[i] = read();
	S = 0; T = n+m*sum+1;
	for(int i=1;i<=n;i++) add_edge(S,i+sum*m,p[i],0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j] = read(),add_edge(i+sum*m,(j-1)*sum+1,1,a[i][j]);
	for(int i=1;i<=m;i++) add_edge((i-1)*sum+1,T,1,0);
	while(spfa()){
		update();
		int tmp = to[pre[T]^1];
		int x = (tmp-1)/sum+1,y = (tmp-1)%sum+1;
		add_edge(tmp+1,T,1,0);
//		cout <<tmp << " " << x <<" " <<y <<"\n";
		for(int i=1;i<=n;i++) add_edge(i+sum*m,tmp+1,1,a[i][x]*(y+1));
	}
	cout <<ans;
	return 0;
}
