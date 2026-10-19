#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 4e5+10;
int n,dfn[N],low[N],tot,cnt;
int stk[N],top;
vector<int> G[N],E[N];
void tarjan(int x){
	// cout << x << "\n";
	dfn[x] = low[x] = ++tot;
	stk[++top] = x;
	for(int y : G[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if(low[y] == dfn[x]){
				++cnt;
				// cout << cnt << "\n";
				int z;
				do{
					z = stk[top--];
					E[z].push_back(cnt);
					E[cnt].push_back(z);
				}while(z != y);
				E[x].push_back(cnt);
				E[cnt].push_back(x);
			}
		}else low[x] = min(low[x],dfn[y]);
	}
}
int st,ed;
void dfs(int x,int fa,int ans){
	if(x == ed){
		if(ans == n+1) puts("No solution");
		else cout << ans << "\n";
		exit(0);
	}
	if(x <= n && x != st) ans = min(ans,x);
	for(int y : E[x]){
		if(y == fa) continue;
		dfs(y,x,ans);
	}
}
int main(){
	n = read();
	while(true){
		int x = read(),y = read();
		if(x == 0 && y == 0) break;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cnt = n;
	st = read(),ed = read();
	tarjan(st);
	dfs(st,0,n+1);
	puts("No solution");
	return 0;
}