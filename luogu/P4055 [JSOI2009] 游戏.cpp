#include<bits/stdc++.h>
#define ll long long
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
const int N = 110;
const int M = 1e4+10;
const int dx[5] = {0,0,1,-1};
const int dy[5] = {1,-1,0,0};
int n,m;
bool ban[N][N];
int head[M],to[M<<2],nxt[M<<2],tot;
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int match[M],vis[M],rt,flag[M];
bool dfs1(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[y] == rt) continue;
		vis[y] = rt;
		if(!match[y] || dfs1(match[y])){
			match[y] = x;
			match[x] = y;
			return true;
		}
	}
	return false;
}
int s[M],top;
void dfs2(int x){
	vis[x] = rt;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[match[y]] == rt || match[y] == x || !match[y]) continue;
		s[++top] = match[y];
		dfs2(match[y]);
	}
}
int main(){
	n = read(); m = read();
	int sum = 0,ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch; cin >> ch;
			if(ch == '.') ban[i][j] = true,sum++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if((i+j)&1 || !ban[i][j]) continue;
			for(int k=0;k<4;k++){
				int x = i+dx[k],y = j+dy[k];
				if(!ban[x][y]) continue;
				add_edge((i-1)*m+j,(x-1)*m+y);
				add_edge((x-1)*m+y,(i-1)*m+j);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if((i+j)&1 || !ban[i][j]) continue;
			rt++;
			ans += dfs1((i-1)*m+j);
		}
	if(sum%2 == 0 && ans == sum/2){
		puts("LOSE"); return 0;
	}
	puts("WIN");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(match[(i-1)*m+j]) flag[(i-1)*m+j] = true;
	rt++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(flag[(i-1)*m+j] || !ban[i][j]) continue;
			s[++top] = (i-1)*m+j;
			dfs2((i-1)*m+j);
		}
	sort(s+1,s+1+top);
	for(int i=1;i<=top;i++){
		int x = s[i]/m+1,y = s[i]%m;
		if(!y){
			y = m;
			x--;
		}
		cout << x <<" " << y <<"\n";
	}
	return 0;
}