#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1100;
int n;
int a[4][N];
vector<int> G[N];
int dfn[N],low[N],tot;
int ins[N],stk[N],top;
int col[N],cnt;
void tarjan(int x){
	ins[x] = true; stk[++top] = x;
	dfn[x] = low[x] = ++tot;
	for(int y : G[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}else if(ins[y]) low[x] = min(low[x],dfn[y]);
	}
	if(low[x] == dfn[x]){
		int z = 0; cnt++;
		do{
			z = stk[top--];
			col[z] = cnt;
			ins[z] = false;
		}while(z != x);
	}
}
bool chk(){
	for(int i=1;i<=n;i++)
		if(col[i] == col[i+n]) return false;
	return true;
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=3;i++)
			for(int j=1;j<=n;j++) 
				a[i][j] = read();
		cnt = tot = 0;
		for(int i=1;i<=2*n;i++){
			G[i].clear();
			dfn[i] = low[i] = col[i] = 0;
		}
		for(int i=1;i<=n;i++){
			int v1 = a[1][i] > 0,v2 = a[2][i] > 0,v3 = a[3][i] > 0;
			a[1][i] = abs(a[1][i]); a[2][i] = abs(a[2][i]); a[3][i] = abs(a[3][i]);
			G[a[1][i]+v1*n].emplace_back(a[2][i]+(v2^1)*n);
			G[a[1][i]+v1*n].emplace_back(a[3][i]+(v3^1)*n);
			G[a[2][i]+v2*n].emplace_back(a[1][i]+(v1^1)*n);
			G[a[2][i]+v2*n].emplace_back(a[3][i]+(v3^1)*n);
			G[a[3][i]+v3*n].emplace_back(a[1][i]+(v1^1)*n);
			G[a[3][i]+v3*n].emplace_back(a[2][i]+(v2^1)*n);
		}
		for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
		puts(chk() ? "YES" : "NO");
	}
	return 0;
}