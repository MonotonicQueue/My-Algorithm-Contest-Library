#include<bits/stdc++.h>
#define ll long long
#define int ll
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
const int N = 11000;
int n,m,k,ans;
int a[N],head[N],to[N*2],nxt[N*2],tot;
void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int dis[N];
vector<int>v[N];
bool cmp(int x,int y){
	return a[x] > a[y];
}
bool f[N][N];
void bfs(int rt){
	queue <int> q;
	q.push(rt);
	memset(dis,-1,sizeof(dis));
	dis[rt] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(x != rt){
			f[rt][x] = 1;
			if(f[1][x]){
				v[rt].push_back(x);
				sort(v[rt].begin(),v[rt].end(),cmp);
				if(v[rt].size() > 3) v[rt].pop_back();
			}
		}
		if(dis[x] == k) continue;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(dis[y] == -1)
				dis[y] = dis[x]+1,q.push(y);
		}
	}
}
signed main(){
	n = read(); m = read(); k = read()+1;
	for(int i=2;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		add_edge(u,v); add_edge(v,u);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++){
			if(i == j || !f[i][j]) continue;
			for(int c=0;c<v[i].size();c++)
			for(int b=0;b<v[j].size();b++)
				if(v[i][c] != j && v[i][c] != v[j][b] &&i != v[j][b])
					ans = max(ans,a[i]+a[j]+a[v[i][c]]+a[v[j][b]]);
		}
	cout << ans;
	return 0;
}