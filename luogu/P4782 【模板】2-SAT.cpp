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
const int N = 2e6+10;
int n,m;
vector<int> G[N];
int dfn[N],low[N],tot;
int stk[N],top;
int col[N],cnt;
bool ins[N];
void tarjan(int x){
	ins[x] = true;
	stk[++top] = x;
	dfn[x] = low[x] = ++tot;
	for(int y : G[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}else if(ins[y]) low[x] = min(low[x],dfn[y]);
	}
	if(dfn[x] == low[x]){
		int z = 0;
		cnt++;
		do{
			z = stk[top--];
			col[z] = cnt;
			ins[z] = false;
		}while(z != x);
	}
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int a = read(),va = read(),b = read(),vb = read();
		G[a+va*n].emplace_back(b+(vb^1)*n);
		G[b+vb*n].emplace_back(a+(va^1)*n);
	}
	for(int i=1;i<=(n<<1);i++) if(!dfn[i]) tarjan(i);
	bool flag = true;
	for(int i=1;i<=(n<<1);i++)
		if(col[i] == col[i+n]) flag = false;
	if(!flag) puts("IMPOSSIBLE");
	else{
		puts("POSSIBLE");
		for(int i=1;i<=n;i++)
			cout << (col[i] < col[i+n]) << " ";
	}
	return 0;
}