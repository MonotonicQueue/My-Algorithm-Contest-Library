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
const int N = 1e3+10;
int n,m,C,M; 
int head[N],to[N<<1],nxt[N<<1],tot,deg[N];
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int dis[N][N];
vector<int>v[N];
map<ll,double> mp;
inline ll h(ll t,ll x,ll y){
	return t*100000000+x*10000+y;
}
double dfs(int t,int x,int y){
	if(x == y) return 0;
	if(dis[x][y] <= 2) return 1.0;
	if(mp[h(t,x,y)]) return mp[h(t,x,y)];
	int u = 0,uu = 0;
	for(int i:v[x]){
		if(dis[i][y] < dis[u][y]) u = i;
		else if(dis[i][y] == dis[u][y]) u = min(u,i);
	}
	for(int i:v[u]){
		if(dis[i][y] < dis[uu][y]) uu = i;
		else if(dis[i][y] == dis[uu][y]) uu = min(uu,i);
	}
	u = uu ;
	double res = 0;
	for(int i=head[y];i;i=nxt[i]){
		int v = to[i];
		res += dfs(t+1,u,v)/(1.0+deg[y]);
	}
	res += dfs(t+1,u,y)/(1.0+deg[y]);
	return mp[h(t,x,y)] = res+1;
}
int main(){
	n = read(); m = read();
	C = read(); M = read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		add_edge(u,v); add_edge(v,u);
		deg[u]++; deg[v]++;
		dis[u][v] = dis[v][u] = 1;
	}
	for(int i=1;i<=n;i++) dis[i][i] = 0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(dis[i][k] <= 10000)
			for(int j=1;j<=n;j++)
				dis[i][j] = dis[i][j] > dis[i][k]+dis[k][j] ? dis[i][k]+dis[k][j] : dis[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j] == 1) v[i].push_back(j);
	printf("%.3lf",dfs(0,C,M));
	return 0;
}
/*
4 3
1 4
1 2
2 3
3 4

9 9
9 3
1 2
2 3
3 4
4 5
3 6
4 6
4 7
7 8
8 9
*/