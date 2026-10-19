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
const int N = 30;
const int M = 19;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int a[N][N];
bool vis[N][N];
int bfs(int sx,int sy,bool op){
	int sum = 0;
	queue<pii> q;
	vector<pii> v;
	q.push(mk(sx,sy));
	vis[sx][sy] = true;
	while(!q.empty()){
		auto [x,y] = q.front(); q.pop();
		v.emplace_back(x,y);
		for(int i=0;i<4;i++){
			int nx = x+dx[i],ny = y+dy[i];
			if(nx < 1 || ny < 1 || nx > M || ny > M) continue;
			if(a[nx][ny] == -1) sum++;
			if(vis[nx][ny] || a[nx][ny] != op) continue;
			q.push(mk(nx,ny));
			vis[nx][ny] = 1;
		}
	}
	if(!sum){
		for(auto [x,y] : v) a[x][y] = -1;
		return v.size();
	}
	return 0;
}
void solve(bool op){
	for(int i=1;i<=19;i++)
		for(int j=1;j<=19;j++) vis[i][j] = 0;
	int cnt[2] = {0,0};
	for(int i=1;i<=19;i++)
		for(int j=1;j<=19;j++)
			if(a[i][j] == (op^1) && !vis[i][j]) cnt[op^1] += bfs(i,j,op^1);
	for(int i=1;i<=19;i++)
		for(int j=1;j<=19;j++)
			if(a[i][j] == op && !vis[i][j]) cnt[op] += bfs(i,j,op);
	cout << cnt[1] << " " << cnt[0] << "\n";
}
int main(){
	memset(a,-1,sizeof(a));
	int T = read();
	for(int _=1;_<=T;_++){
		int x = read(),y = read();
		int op = _ & 1;
		a[x][y] = op;
		solve(op);
	}
	return 0;
}