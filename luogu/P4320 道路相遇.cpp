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
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 1e6+10;
const int M = 1e6+10;
int n,m,q;
struct Gragh{
	int head[N],to[M<<1],nxt[M<<1],tot;
	inline void add_edge(int u,int v){
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
}G1,G2;
int dfn[N],low[N],num,cnt;
int stk[N],Top;
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	stk[++Top] = x; 
	for(int i=G1.head[x];i;i=G1.nxt[i]){
		int y = G1.to[i];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if(low[y] == dfn[x]){
				cnt++;
				int z = 0;
				do{
					z = stk[Top--];
					G2.add_edge(cnt,z);
					G2.add_edge(z,cnt);
				}while(z != y);
				G2.add_edge(cnt,x);
				G2.add_edge(x,cnt);
			}
		}else low[x] = min(low[x],dfn[y]);
	}
}
int fa[N],siz[N],top[N],son[N],Dfn[N],dfc,st[N],dep[N];
void dfs1(int x,int fr){
	dep[x] = dep[fr]+1;
	fa[x] = fr;
	siz[x] = 1;
	for(int i=G2.head[x];i;i=G2.nxt[i]){
		int y = G2.to[i];
		if(y == fr) continue;
		dfs1(y,x);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	}
}
void dfs2(int x,int topx){
	top[x] = topx;
	Dfn[++dfc] = x;
	st[x] = dfc;
	if(!son[x]) return ;
	dfs2(son[x],topx);
	for(int i=G2.head[x];i;i=G2.nxt[i]){
		int y = G2.to[i];
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y,y);
	}
}
#define ls rt<<1
#define rs rt<<1|1
int c[N<<2];
void build(int rt,int l,int r){
	if(l == r){
		c[rt] = Dfn[l] <= n;
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	c[rt] = c[ls]+c[rs];
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return c[rt];
	int mid = (l+r)>>1,res = 0;
	if(ql <= mid) res += query(ls,l,mid,ql,qr);
	if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
	return res;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G1.add_edge(u,v); G1.add_edge(v,u);
	}
	cnt = n;
	tarjan(1);
	dfs1(1,0); dfs2(1,1);
	build(1,1,dfc);
	q = read();
	while(q--){
		int u = read(),v = read();
		int ans = 0;
		while(top[u] != top[v]){
			if(dep[top[u]] < dep[top[v]]) swap(u,v);
			ans += query(1,1,dfc,st[top[u]],st[u]);
			u = fa[top[u]];  
		}
		if(dep[u] > dep[v]) swap(u,v);
		ans += query(1,1,dfc,st[u],st[v]); 
		cout << ans << "\n"; 
	}
	return 0;
}
