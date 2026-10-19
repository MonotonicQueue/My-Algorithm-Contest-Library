#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
const int M = 1e7+10;
int n,m,t,val[N];
int head[N],to[N<<1],nxt[N<<1],tot=1;
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int dep[N],fa[N][20];
void dfs0(int x,int fr){
	dep[x] = dep[fr]+1;
	fa[x][0] = fr;
	for(int i=1;i<=t;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fr) continue;
		dfs0(y,x);
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=t;i>=0;i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i=t;i>=0;i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int getdis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int root,siz[N],S,Maxn;
bool vis[N];
void getroot(int x,int fr){
	siz[x] = 1;
	int maxpart = 0;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fr || vis[y]) continue;
		getroot(y,x);
		maxpart = max(maxpart,siz[y]);
		siz[x] += siz[y];
	}
	maxpart = max(maxpart,S-siz[x]);
	if(maxpart < Maxn){
		Maxn = maxpart;
		root = x;
	}
}
int dfa[N];
void solve(int x){
	vis[x] = 1;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(vis[y]) continue;
		root = 0;
		S = Maxn = siz[y];
		getroot(y,x);
		dfa[root] = x;
		solve(root);
	}
}
int rt1[N],rt2[N],cnt;
struct Segment{
	int ls,rs,val;
}c[M];
void update(int &rt,int l,int r,int p,int d){
	if(!rt) rt = ++cnt;
	if(l == r){
		c[rt].val += d;
		return ;
	}
	int mid = (l+r)>>1;
	if(p <= mid) update(c[rt].ls,l,mid,p,d);
	else 		 update(c[rt].rs,mid+1,r,p,d);
	c[rt].val = c[c[rt].ls].val + c[c[rt].rs].val;
}
int query(int rt,int l,int r,int ql,int qr){
	if(!rt) return 0;
	if(ql <= l && r <= qr) return c[rt].val;
	int mid = (l+r)>>1,res = 0;
	if(ql <= mid) res += query(c[rt].ls,l,mid,ql,qr);
	if(qr >  mid) res += query(c[rt].rs,mid+1,r,ql,qr);
	return res;
}
void modify(int x,int v){
	int cur = x;
	while(cur){
		int y = dfa[cur];
		update(rt1[cur],0,n-1,getdis(cur,x),v);
		if(y) update(rt2[cur],0,n-1,getdis(y,x),v);
		cur = dfa[cur];
	}
}
int ask(int x,int k){
	int cur = x,pre = 0,res = 0;
	while(cur){
		if(getdis(cur,x) > k){
			pre = cur; cur = dfa[cur]; continue;
		}
		res += query(rt1[cur],0,n-1,0,k-getdis(cur,x));
		if(pre) res -= query(rt2[pre],0,n-1,0,k-getdis(cur,x));
		pre = cur; cur = dfa[cur];
	}
	return res;
	
}
int main(){
	n = read(); m = read();
	t = log(n)/log(2);
	for(int i=1;i<=n;i++) val[i] = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		add_edge(u,v); add_edge(v,u);
	}
	dfs0(1,0);
	S = Maxn = n;
	getroot(1,0);
	solve(root);
	for(int i=1;i<=n;i++) modify(i,val[i]);
	int lstans = 0;
	while(m--){
		int op = read(),x = read(),y = read();
		x ^= lstans; y ^= lstans;
		if(op == 0){
			lstans = ask(x,y);
			printf("%d\n",lstans);
		}else{
			modify(x,y-val[x]);
			val[x] = y;
		}
	}
	return 0;
}
