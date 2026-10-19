#include<bits/stdc++.h>
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
const int dx[8] = {1,1,1,0,0,-1,-1,-1};
const int dy[8] = {1,-1,0,1,-1,1,0,-1};
const int mod = 12345678;
int n,m;
char mp[10][10];
ll ans;
bool chk(int x,int y){
	if(mp[x][y] == 'X') return false;
	for(int k=0;k<8;k++){
		int nx = x+dx[k],ny = y+dy[k];
		if(mp[nx][ny] == 'X') return false;
	}
	return true;
}
ll f[30][1<<8];
struct node{
	int x,y;
}a[10]; int tot;
bool flag[10][10];
ll calc(){
	memset(f,0,sizeof(f));
	tot = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(mp[i][j] == 'X') a[++tot] = node{i,j};
	f[0][0] = 1;
	for(int s=0;s<(1<<tot);s++){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) flag[i][j] = true;
		for(int i=1;i<=tot;i++)
			if(!((s >> (i-1)) & 1)){
				flag[a[i].x][a[i].y] = 0;
				for(int k=0;k<8;k++) flag[a[i].x+dx[k]][a[i].y+dy[k]] = false;
			}
		int cnt = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cnt += flag[i][j];
		for(int i=0;i<=cnt;i++){
			f[i+1][s] = (f[i+1][s]+f[i][s]*(cnt-i)%mod)%mod;
			for(int j=0;j<tot;j++)
				if(!((s >> j) & 1)) f[i+1][s|(1<<j)] = (f[i+1][s|(1<<j)]+f[i][s])%mod;
		}
	}
	return f[n*m][(1<<tot)-1];
}
void dfs(int x,int y,int k){
	if(x > n) ans = (ans+k*calc()%mod+mod)%mod;
	else if(y > m) dfs(x+1,1,k);
	else{
		dfs(x,y+1,k);
		if(chk(x,y)){
			mp[x][y] = 'X';
			dfs(x,y+1,-k);
			mp[x][y] = '.';
		}
	}
}
ll solve(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j] == 'X')
				for(int k=0;k<8;k++){
					int nx = i+dx[k],ny = j+dy[k];
					if(mp[nx][ny] == 'X') return 0;
				}
	dfs(1,1,1);
	return ans;
}
int main(){
    n = read(); m = read();
	for(int i=1;i<=n;i++) cin >> mp[i]+1;
	cout << solve();
	return 0;
}