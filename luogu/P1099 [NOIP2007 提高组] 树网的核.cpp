#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-')  ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e5+10;
int n,s;
int head[N],to[N<<1],nxt[N<<1],tot;
int a[N],num,maxn,root;
ll dep[N],edge[N<<1];
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
}
bool flag[N];
int fr[N];
void dfs1(int x,int fa){
	fr[x] = fa;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa) continue;
		dep[y] = dep[x]+edge[i];
		dfs1(y,x);
	}
	if(dep[x] > dep[maxn]) maxn = x;
}

bool dfs2(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa) continue;
		if(dfs2(y,x)){
			a[++num] = x;
			return true;
		}
	}
	if(x == maxn){
		a[++num] = x;
		return true;
	}
	return false;
}
ll d[N];
void dfs3(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(flag[y] || y == fr[x]) continue;
		dfs3(y);
		d[x] = max(d[x],d[y]+edge[i]);
	}
}
ll dis(int x,int y){
	return dep[x]-dep[y];
}
int main(){
//	freopen("core.in","r",stdin);
	//freopen("core.out","w",stdout);
	n = read(); s = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read(),w = read();
		add_edge(u,v,w); add_edge(v,u,w);
	}
	
	dfs1(1,0);
	root = maxn; dep[root] = 0;
	dfs1(root,0); dfs2(root,0);
	for(int i=1;i<=num;i++) flag[a[i]] = true;
	for(int i=1;i<=num;i++) dfs3(a[i]);
	ll ans = 1e18,sum = 0;
	for(int i=1;i<=num;i++) sum = max(sum,d[a[i]]);
	for(int i=1,j=1;i<=num&&j<=num;i++){
		while(dis(a[i],a[j+1]) <= s && j < num) j++;
		ans = min(ans,max(sum,max(dis(a[1],a[i]),dis(a[j],a[num]))));
	}
	cout << ans;
	return 0;
}
/*
5 2
1 2 5
2 3 2
2 4 4
2 5 3
*/
