#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-48,ch = getchar();
	return X*r;
}
const int N = 50;
const int M = 1e4+10;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int n,m,k,nx,ny;
int head[N*N],to[M<<1],nxt[M<<1],tot;
bool col[N][N];
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
char a[N][N];
bool vis[N*N],ban[N*N],won[N*N];
int match[N*N],ans;
int stk[N*N],top;
bool dfs(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(ban[y]) continue;
		if(vis[y]) continue;
		vis[y] = true;
		if(!match[y] || dfs(match[y])){
			match[y] = x;
			match[x] = y;
			return true;
		}
	}
	return false;
}
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j] == 'O') col[i][j] = true;
			else if(a[i][j] == '.') nx = i,ny = j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(col[i][j]) continue;
			for(int t=0;t<4;t++){
				int x = i+dx[t],y = j+dy[t];
				if(x < 1 || y < 1 || x > n || y > m || !col[x][y]) continue;
				add_edge((i-1)*m+j,(x-1)*m+y);
				add_edge((x-1)*m+y,(i-1)*m+j);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!col[i][j]) continue;
			memset(vis,0,sizeof(vis));
			ans += dfs((i-1)*m+j);
		}
	
	k = read();
	for(int i=1;i<=2*k;i++){
		int cur = (nx-1)*m+ny;
		nx = read(); ny = read();
		ban[cur] = 1;
		if(!match[cur]) continue;
		int nxt = match[cur];
		match[cur] = match[nxt] = 0;
		memset(vis,0,sizeof(vis));
		if(!dfs(nxt)) won[i] = true;
	}
	for(int i=1;i<=2*k;i++)
		if(won[2*i-1] && won[2*i])
			stk[++top] = i;
	printf("%d\n",top);
	for(int i=1;i<=top;i++) printf("%d\n",stk[i]);
	return 0;
} 