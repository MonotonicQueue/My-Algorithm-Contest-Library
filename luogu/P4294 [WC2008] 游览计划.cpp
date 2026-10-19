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
const int M = 1<<10;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int n,m,k;
int val[N],f[N][M],id[N][N];
pii raw[N];
queue<int> q;
bool vis[N];
struct Pre{
	int op;
	int i,S,T;
}p[N][M];
void spfa(int S){
	while(!q.empty()){
		int x = q.front(); q.pop();
		vis[x] = false;
		for(int i=0;i<4;i++){
			int y = id[raw[x].fi+dx[i]][raw[x].se+dy[i]];
			if(!y) continue;
			if(f[y][S] > f[x][S]+val[y]){
				f[y][S] = f[x][S]+val[y];
				p[y][S] = Pre{2,x,S,0};
				if(!vis[y]) q.push(y),vis[y] = true;
			}
		}
	}
}
char ch[N][N];
void dfs(int x,int S){
	if(!val[x]) ch[raw[x].fi][raw[x].se] = 'x';
	else 		ch[raw[x].fi][raw[x].se] = 'o';
	if(!p[x][S].op) return ;
	if(p[x][S].op == 1){
		dfs(x,p[x][S].S);
		dfs(x,p[x][S].T);
	}else{
		dfs(p[x][S].i,p[x][S].S);
	}
}
int main(){
	n = read(); m = read();
	int sum = 0,cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			id[i][j] = ++sum;
			raw[sum] = mk(i,j);
		}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x = id[i][j];
			val[x] = read();
			if(!val[x]){
				f[x][1<<cnt] = 0;
				cnt++;
			}
		}
	if(!cnt){
		cout << "0\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout << "_";
			cout << "\n";
		}
		return 0;
	}
	for(int S=1;S<(1<<cnt);S++){
		for(int i=1;i<=sum;i++){
			for(int T=S&(S-1);T;T=(T-1)&S)
				if(f[i][S] > f[i][T]+f[i][S^T]-val[i]){
					f[i][S] = f[i][T]+f[i][S^T]-val[i];
					p[i][S] = Pre{1,i,S^T,T};
				}
			if(f[i][S] < 1e9) q.push(i),vis[i] = true;
		}
		spfa(S);
	}
	int ans = 1e9,pr = -1;
	for(int i=1;i<=sum;i++)
		if(ans > f[i][(1<<cnt)-1]){
			ans = f[i][(1<<cnt)-1];
			pr = i;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ch[i][j] = '_';
	cout << ans << "\n";
	dfs(pr,(1<<cnt)-1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout << ch[i][j];
		cout << "\n";
	}
	return 0;
}