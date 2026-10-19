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
const int N = 2e5+10;
int n;
int head[N],to[N],nxt[N],edge[N],tot;
inline void add_edge(int u,int v,int w){
	to[++tot] = v; nxt[tot] = head[u];
	head[u] = tot; edge[tot] = w;
}
ll p[N],q[N],l[N],dis[N],f[N];
int dfn[N],cnt;
struct Line{
	ll k,b;
	ll val(ll x){
		return k*x+b;
	}
}a[N];
void dfs1(int x){
	for(int i=head[x];i;i=nxt[i]) dis[to[i]] = dis[x]+edge[i],dfs1(to[i]);
	dfn[x] = ++cnt;
}
const int M = 4e6+10;
const ll inf = 1e18;
struct Li_Chao_Segment{
	int x,lc,rc;
}t[M]; int Ct;
void upd(int &x,int l,int r,int k){
	if(!x){
		x = ++Ct;
		t[x].x = k;
		return ;
	}
	int mid = (l+r)>>1;
	if(a[t[x].x].val(mid) > a[k].val(mid)) swap(k,t[x].x);
	if(l == r) return ;
	if(a[t[x].x].val(l) > a[k].val(l)) upd(t[x].lc,l,mid,k);
	else upd(t[x].rc,mid+1,r,k);
}
ll qry(int x,int l,int r,int k){
	if(!x) return inf;
	if(l == r) return a[t[x].x].val(k);
	int mid = (l+r) >> 1;
	if(k <= mid) return min(qry(t[x].lc,l,mid,k),a[t[x].x].val(k));
	else 		 return min(qry(t[x].rc,mid+1,r,k),a[t[x].x].val(k));
}
int rt[N<<2];
void update(int x,int l,int r,int pos){
	upd(rt[x],0,1e6,pos);
	if(l == r) return ;
	int mid = (l+r) >> 1;
	if(pos <= mid) update(x<<1,l,mid,pos);
	else update(x<<1|1,mid+1,r,pos);
}
ll query(int x,int l,int r,int ql,int qr,int k){
	// cout << ql << " " << qr << "\n";
	if(ql <= l && r <= qr) return qry(rt[x],0,1e6,k);
	int mid = (l+r)>>1; ll res = inf;
	if(ql <= mid) res = min(res,query(x<<1,l,mid,ql,qr,k));
	if(qr >  mid) res = min(res,query(x<<1|1,mid+1,r,ql,qr,k));
	return res;
}
int m;
ll d[N],pos[N];
void dfs2(int x){
	a[dfn[x]] = Line{-dis[x],f[x]};
	update(1,1,n,dfn[x]);
	d[++m] = dis[x]; pos[m] = x;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		int id = lower_bound(d+1,d+1+m,dis[y]-l[y])-d;
		f[y] = query(1,1,n,dfn[y],dfn[pos[id]],p[y])+dis[y]*p[y]+q[y];
		dfs2(y);
	}
	--m;
}
int main(){
    n = read(); int T = read();
	for(int i=2;i<=n;i++){
		int fa = read(),w = read();
		add_edge(fa,i,w);
		p[i] = read(); q[i] = read(); l[i] = read();
	}
	dfs1(1); dfs2(1);
	for(int i=2;i<=n;i++) cout << f[i] << "\n";
	return 0;
}