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
const int N = 1e5+10;
int n,tot;
char s[N];
int son[N][2],fail[N];
bool ed[N];
void insert(){
	int p = 0,m = strlen(s+1);
	for(int i=1;i<=m;i++){
		int c = s[i]-'0';
		if(!son[p][c]) son[p][c] = ++tot;
		p = son[p][c];
	}
	ed[p] = true;
}
void getFail(){
	queue<int> q;
	for(int i=0;i<=1;i++)
		if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<=1;i++){
			if(son[x][i]){
				fail[son[x][i]] = son[fail[x]][i];
				ed[son[x][i]] |= ed[son[fail[x]][i]];
				q.push(son[x][i]);
			}else son[x][i] = son[fail[x]][i];
		}
	}
}
bool vis[N],ins[N];
void dfs(int x){
	if(ins[x]){
		puts("TAK");
		exit(0);
	}
	if(vis[x]) return ;
	vis[x] = ins[x] = true;
	for(int i=0;i<=1;i++)
		if(!ed[son[x][i]]) dfs(son[x][i]);
	ins[x] = false;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert();
	}
	getFail(); dfs(0);
	puts("NIE");
	return 0;
}