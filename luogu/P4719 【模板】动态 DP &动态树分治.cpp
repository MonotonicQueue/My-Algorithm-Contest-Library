#include<bits/stdc++.h>
#define ll long long
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
const int N = 1e5+10;
int n,m,a[N];
int head[N],to[N<<1],nxt[N<<1],tot;
int fa[N],dep[N],id[N],siz[N],son[N],top[N],ed[N],dfn[N],Num;
int f[N][2];
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
struct Martix{
	int mat[2][2];
	Martix(){
		memset(mat,0xcf,sizeof(mat));
	}
	Martix operator*(Martix b){
		Martix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					c.mat[i][j] = max(c.mat[i][j],mat[i][k]+b.mat[k][j]);
		return c;
	}
}val[N];
struct Segment{
	int l,r;
	Martix m;
	#define ls rt<<1
	#define rs rt<<1|1
}c[N<<2];
void push_up(int rt){
	c[rt].m = c[ls].m*c[rs].m;
}
void build(int rt,int l,int r){
	c[rt].l = l; c[rt].r = r;
	if(l == r){
		c[rt].m = val[dfn[l]];
		return ;
	}
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void update(int rt,int pos){
	if(c[rt].l == c[rt].r){
		c[rt].m = val[dfn[pos]];
		return ;
	}
	int mid = (c[rt].l+c[rt].r)>>1;
	if(pos <= mid) update(ls,pos);
	else update(rs,pos);
	push_up(rt);
}
Martix query(int rt,int l,int r){
	if(l <= c[rt].l && c[rt].r <= r) return c[rt].m;
	int mid = (c[rt].l+c[rt].r)>>1;
	if(r <= mid) return query(ls,l,r);
	if(l >  mid) return query(rs,l,r);
	return query(ls,l,r)*query(rs,l,r);
}
void dfs1(int x,int father){
	fa[x] = father; dep[x] = dep[father]+1;
	siz[x] = 1;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == father) continue;
		dfs1(y,x);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	}
}
void dfs2(int x,int topx){
	top[x] = topx; id[x] = ++Num;
	ed[topx] = max(ed[topx],id[x]); dfn[Num] = x;
	f[x][0] = 0; f[x][1] = a[x];
	val[x].mat[0][0] = val[x].mat[0][1] = 0;
	val[x].mat[1][0] = a[x];
	if(!son[x]) return;
	dfs2(son[x],topx);
	f[x][0] += max(f[son[x]][0],f[son[x]][1]);
	f[x][1] += f[son[x]][0]; 
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y,y);
		f[x][0] += max(f[y][0],f[y][1]);
		f[x][1] += f[y][0];
		val[x].mat[0][0] += max(f[y][0],f[y][1]);
		val[x].mat[0][1] = val[x].mat[0][0];
		val[x].mat[1][0] += f[y][0];
	}
}
void update_range(int x,int w){
	val[x].mat[1][0] += w-a[x];
	a[x] = w;
	Martix aft,bef;
	while(x){
		bef = query(1,id[top[x]],ed[top[x]]);
		update(1,id[x]);
		aft = query(1,id[top[x]],ed[top[x]]);
		x = fa[top[x]];
		val[x].mat[0][0] += max(aft.mat[0][0],aft.mat[1][0])-max(bef.mat[0][0],bef.mat[1][0]);
		val[x].mat[0][1] = val[x].mat[0][0];
		val[x].mat[1][0] += aft.mat[0][0]-bef.mat[0][0];
	}
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		add_edge(u,v); add_edge(v,u);
	}
	dfs1(1,0); dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int u = read(),w = read();
		update_range(u,w);
		Martix ans = query(1,id[1],ed[1]);
		cout << max(ans.mat[0][0],ans.mat[1][0]) << "\n";
	}
	return 0;
}