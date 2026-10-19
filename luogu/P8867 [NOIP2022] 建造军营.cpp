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
const int N = 5e5+10;
const int M = 2e6+10;
const int mod = 1e9+7;
int m;
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
struct e_DCC_Edge{
	int n;
	int head[N],to[M],nxt[M],tot;
	ll siz[N],cnt[M],f[N][2],s[N],ans;
	inline void add_edge(int u,int v){
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void DP(int x,int fa){
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(y == fa) continue;
			DP(y,x);
			f[x][1] = (f[x][1]*(2*f[y][0]+f[y][1])%mod+f[x][0]*f[y][1]%mod)%mod;
			f[x][0] = (f[x][0]*f[y][0]*2)%mod;
		}
		if(x == 1) ans = (ans+f[x][1])%mod;
		else ans = (ans+f[x][1]*fpow(2,s[1]-s[x]-1))%mod;
	}
	void dfs(int x,int fa){
		s[x] = cnt[x];
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(y == fa) continue;
			dfs(y,x);
			s[x] += s[y]+1;
		}
	}
	inline void work(){
		for(int i=1;i<=n;i++){
			cnt[i] /= 2;
			f[i][0] = fpow(2,cnt[i]);
			f[i][1] = fpow(2,cnt[i]+siz[i])-f[i][0];
		}
		dfs(1,0); DP(1,0);
		printf("%lld",ans);
	}
}G2;
struct Gragh_Edge{
	int n;
	int head[N],to[M],nxt[M],tot;
	int dfn[N],low[N],vis[N],Num,dcc;
	bool cut[M];
	Gragh_Edge(){tot = 1;Num = dcc = 0;}
	inline void add_edge(int u,int v){
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void tarjan(int x,int in_edge){
		dfn[x] = low[x] = ++Num;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(!dfn[y]){
				tarjan(y,i);
				low[x] = min(low[x],low[y]);
				if(dfn[x] < low[y])
					cut[i] = cut[i^1] = true;
			}else if(i != (in_edge^1)) low[x] = min(low[x],dfn[y]);
		}
	}
	void dfs(int x){
		vis[x] = dcc; G2.siz[dcc]++;
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(!vis[y] && !cut[i]) dfs(y);
		}
	}
	inline void work(){
		n = read(); m = read();
		for(int i=1;i<=m;i++){
			int u = read(),v = read();
			add_edge(u,v);
			add_edge(v,u);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i,0);
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				dcc++;
				dfs(i);
			}
		G2.n = dcc;
		for(int i=2;i<=tot;i++){
			int x = to[i],y = to[i^1];
			if(vis[x] != vis[y])
				G2.add_edge(vis[x],vis[y]);
			else G2.cnt[vis[x]]++;
		}
	}
}G1;

int main(){
	G1.work(); G2.work();
	return 0;
} 