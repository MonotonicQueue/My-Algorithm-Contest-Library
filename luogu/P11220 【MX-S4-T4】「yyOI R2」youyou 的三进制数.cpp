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
const int N = 6e5+10;
int n,w,cnt;
vector<int> G[N],E[N];
int bas[N];
int dfn[N],low[N],stk[N],top,num;
void tarjan(int x,int ft){
	stk[++top] = x;
	low[x] = dfn[x] = ++num;
	for(int y : G[x]){
		if(y == ft) continue;
		if(!dfn[y]){
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if(low[y] >= dfn[x]){
				cnt++;
				int z;
				do{
					z = stk[top--];
					E[cnt].push_back(z);
					E[z].push_back(cnt);
				}while(z != y);
				E[cnt].push_back(x);
				E[x].push_back(cnt);
			}
		}else low[x] = min(low[x],dfn[y]);
	}
}
ll siz[N],f[N];
void dfs(int x,int ft){
	siz[x] = x <= n;
	ll sum = 0;
	for(int y : E[x]){
		if(y == ft) continue;
		dfs(y,x);
		sum += siz[y]*siz[x];
		siz[x] += siz[y];
	}
	if(x <= n){
		for(int y : E[x]){
			if(y == ft) continue;
			f[y] -= (n+1-siz[y])*siz[y];
		}
		f[0] += sum;
		f[x] += siz[x]*(n+1-siz[x]);
	}
}
void dfs0(int x,int ft){
	for(int y : E[x]){
		if(y == ft) continue;
		f[y] += f[x];
		dfs0(y,x);
	}
}
int main(){
	n = read(); w = read();
	auto add_edge = [&](int x,int y){
		G[x].push_back(y);
		G[y].push_back(x);
	};
	for(int i=1;i<=n;i++) add_edge(i/3,i);
	bas[0] = 1;
	for(int i=1;i<=n;i++) bas[i] = bas[i/3]*3;
	for(int i=1;i<=w;i++){
		if(i % 3 == 0) continue;
		int x = i/3,y = i%3;
		x = bas[x]*y+x;
		if(x <= n) add_edge(x,i);
	}
	cnt = n;
	tarjan(0,0);
	dfs(0,0); dfs0(0,0);
	for(int i=0;i<=n;i++) cout << f[i]*2 << "\n";
    return 0;
}

