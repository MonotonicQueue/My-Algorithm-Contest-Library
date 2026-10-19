#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e5+10;
struct ChairmanTree{
	struct Segment{
		int lc,rc;
		int cnt;
	}c[N<<5];
	int tot = 0,root[N];
	int build(int l,int r){
		int p = ++tot;
		if(l == r) return p;
		int mid = (l+r)>>1;
		c[p].lc = build(l,mid);
		c[p].rc = build(mid+1,r);
		return p;
	}
	int update(int rt,int l,int r,int pos){
		int p = ++tot;
		c[p] = c[rt]; c[p].cnt++;
		if(l == r) return p;
		int mid = (l+r)>>1;
		if(pos <= mid) c[p].lc = update(c[p].lc,l,mid,pos);
		else c[p].rc = update(c[p].rc,mid+1,r,pos);
		return p; 
	}
	int query(int p,int q,int l,int r,int k){
		if(l == r) return l;
		int cnt = c[c[p].lc].cnt-c[c[q].lc].cnt,mid = (l+r)>>1;
		if(cnt >= k) return query(c[p].lc,c[q].lc,l,mid,k);
		return query(c[p].rc,c[q].rc,mid+1,r,k-cnt);
	}
}CT;
namespace Tree{
	int n;
	int head[N],to[N*2],nxt[N*2],tot=0;
	int st[N],ed[N],Num,dfn[N];
	inline void add_edge(int u,int v){
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	int fa[N][20],deep[N],t;
	void dfs(int x,int from){
		deep[x] = deep[from]+1;
		st[x] = ++Num;
		dfn[Num] = x;
		fa[x][0] = from;
		for(int i=1;i<=t;i++)
			fa[x][i] = fa[fa[x][i-1]][i-1];
		for(int i=head[x];i;i=nxt[i]){
			int y = to[i];
			if(y == from) continue;
			dfs(y,x);
		}
		ed[x] = Num;
	}
	int lca(int x,int y){
		if(deep[x] < deep[y]) swap(x,y);
		for(int i=t;i>=0;i--)
			if(deep[fa[x][i]] >= deep[y])
				x = fa[x][i];
		if(x == y) return x;
		for(int i=t;i>=0;i--)
			if(fa[x][i] != fa[y][i]){
				x = fa[x][i];
				y = fa[y][i];
			}
		return fa[x][0];
	}
	int get_dis(int x,int y){
		int Lca = lca(x,y);
		return deep[x]+deep[y]-2*deep[Lca];
	}
	inline void init(){
		for(int i=1;i<n;i++){
			int u,v;
			u = read(); v = read();
			add_edge(u,v); add_edge(v,u);
		}
		t = log(n)/log(2);
		dfs(1,0);
		CT.root[0] = CT.build(1,n);
		for(int i=1;i<=n;i++)
			CT.root[i] = CT.update(CT.root[i-1],1,n,dfn[i]);
	}
}
namespace BigTree{
	int n,m;
	ll st[N],ed[N],Num,pre[N],dfn[N];
	ll fa[N][20],deep[N],t,cnt,lnk[N],dis[N][20];
	ll get_root(ll x){
		int l = 1,r = n;
		while(l <= r){
			int mid = (l+r)>>1;
			if(x >= st[mid]) l = mid+1;
			else r = mid-1;
		}
		return r;
	}
	ll get_pre(ll x){
		int rt = get_root(x);
		return CT.query(CT.root[Tree::ed[pre[rt]]],CT.root[Tree::st[pre[rt]]-1],1,Tree::n,x-st[rt]+1);
	}
	inline void init(){
		t = Tree::t;
		n = 1; st[1] = 1; ed[1] = Tree::n;
		pre[1] = 1; deep[1] = 1;
		cnt = ed[1];
		for(int i=1;i<=m;i++){
			int u = read(); ll v = read();
			int rt = get_root(v);
			n++; deep[n] = deep[rt]+1;
			lnk[n] = v;
			pre[n] = u;
			st[n] = cnt+1;
			ed[n] = cnt+Tree::ed[u]-Tree::st[u]+1;
			cnt = ed[n];
			fa[n][0] = rt;
			dis[n][0] = Tree::deep[get_pre(v)]-Tree::deep[pre[rt]]+1;
			for(int j=1;j<=t;j++)
				fa[n][j] = fa[fa[n][j-1]][j-1],
				dis[n][j] = dis[n][j-1]+dis[fa[n][j-1]][j-1];
		}
	}
	ll solve(ll u,ll v){
		ll ret=0;
		int rtu=get_root(u),rtv=get_root(v);
		if(rtu == rtv) return Tree::get_dis(get_pre(u),get_pre(v));
		if(deep[rtu]<deep[rtv]) {
			swap(u,v);
			swap(rtu,rtv);
		}
		ret+=Tree::deep[get_pre(u)]-Tree::deep[pre[rtu]];
		u=rtu;
		for(int i=t; i>=0; i--) 
		if(deep[fa[u][i]]>deep[rtv]) {
				ret += dis[u][i];
				u = fa[u][i];
		}
		if(get_root(lnk[u])==rtv) return ret+1+Tree::get_dis(get_pre(lnk[u]),get_pre(v));
		ret += Tree::deep[get_pre(v)]-Tree::deep[pre[rtv]];
		v=rtv;
		if(deep[u] > deep[v]) {
			ret += dis[u][0];
			u = fa[u][0];
		}
		for(int i=t; i>=0; i--) 
			if(fa[u][i]!=fa[v][i]) {
				ret+=dis[u][i]+dis[v][i];
				u = fa[u][i];
				v = fa[v][i];
			}
		u = lnk[u]; v = lnk[v];
		return ret+Tree::get_dis(get_pre(u),get_pre(v))+2;
	}
}
int main() {
	Tree::n = read(); BigTree::m = read(); 
	int q = read(); Tree::init();
	BigTree::init();
	while(q--){
		ll x = read(),y = read();
		cout << BigTree::solve(x,y) << "\n";
	}
	return 0;
}