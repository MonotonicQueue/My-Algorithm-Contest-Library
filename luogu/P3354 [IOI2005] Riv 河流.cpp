#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 110;
int n,K,fa[N];
vector<int> G[N];
ll w[N],d[N],dep[N],siz[N];
ll f[N][N][55];
int stk[N],top;
void dfs(int x){
	stk[++top] = x;
	for(int y : G[x]){
		dep[y] = dep[x]+d[y];
		dfs(y);
		for(int i=1;i<=top;i++)
			for(int j=K;~j;j--){
				f[x][stk[i]][j] += f[y][stk[i]][0];
				for(int k=0;k<=j;k++) f[x][stk[i]][j] = min(f[x][stk[i]][j],f[x][stk[i]][k]+f[y][stk[i]][j-k]);
			}
	}
	for(int i=1;i<top;i++){
		for(int j=K;~j;j--){
			if(j >= 1)
				f[x][stk[i]][j] = min(f[x][x][j-1],f[x][stk[i]][j]+(dep[x]-dep[stk[i]])*w[x]);
			else f[x][stk[i]][j] += (dep[x]-dep[stk[i]])*w[x];
		}
	}
	top--;
}
int main(){
	n = read(); K = read();
	for(int i=1;i<=n;i++){
		w[i] = read(); fa[i] = read();
		d[i] = read(); G[fa[i]].push_back(i);
	}
	dfs(0);
	cout << f[0][0][K];
    return 0;
}
