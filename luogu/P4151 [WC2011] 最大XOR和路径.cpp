#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e4+10;
const int M = 2e5+10;
int n,m;
int head[N],to[M],nxt[M],tot;
ll D[M],p[70];
inline void add(int u,int v,ll z){
	to[++tot] = v;
	nxt[tot] = head[u];
	D[tot] = z;
	head[u] = tot;
}
bool vis[N]; ll val[N];
void insert(ll x){
	for(int i=63;i>=0;i--)
		if((x>>i) & 1){
			if(!p[i]){p[i] = x; return;}
			x ^= p[i];
		}
}
ll query(){
	ll ans = val[n];
	for(int i=63;i>=0;i--)
		ans = max(ans,ans^p[i]);
	return ans;
}
void dfs(int x,ll res){
	vis[x] = true; val[x] = res;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(!vis[y]) dfs(y,res^D[i]);
		else insert(res^D[i]^val[y]);
	}
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		ll z = read();
		add(u,v,z); add(v,u,z);
	}
	dfs(1,0); printf("%lld",query());
	return 0;
} 
