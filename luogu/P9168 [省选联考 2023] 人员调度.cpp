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
const int N = 2e5+10;
const int inf = 1e9;
int n,k,m;
vector<int> E[N];
int fa[N],dep[N],siz[N],son[N],top[N],dfn[N],raw[N],ttt;
void dfs1(int x,int fr){
	fa[x] = fr;
	dep[x] = dep[fr]+1;
	siz[x] = 1;
	for(int y : E[x]){
		dfs1(y,x);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	} 
}
void dfs2(int x,int topx){
	dfn[x] = ++ttt;
	raw[ttt] = x;
	top[x] = topx;
	if(!son[x]) return ;
	dfs2(son[x],topx);
	for(int y : E[x]){
		if(y == son[x]) continue;
		dfs2(y,y);
	} 
}
struct Employee{
	int x,v;
	bool operator < (const Employee &y) const{
		return v < y.v;
	}
}a[N];
#define ls rt<<1
#define rs rt<<1|1
struct Segment{
	int mnsz,tag;
	pair<int,int> mx;
}t[N<<2];
inline void push_up(int rt){
	t[rt].mnsz = min(t[ls].mnsz,t[rs].mnsz);
	t[rt].mx = max(t[ls].mx,t[rs].mx);
} 
void build(int rt,int l,int r){
	t[rt].mx = mk(0,r);
	if(l == r) 	return ;
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
inline void change(int rt,int d){
	t[rt].mnsz += d;
	t[rt].tag += d; 
}
inline void push_down(int rt){
	if(t[rt].tag){
		change(ls,t[rt].tag);
		change(rs,t[rt].tag);
		t[rt].tag = 0;
	}
}
void updatemx(int pos,int x,int rt=1,int l=1,int r=n){
	if(l == r){
		t[rt].mx = mk(x,pos);
		return ;
	}
	push_down(rt); 
	int mid = (l+r)>>1;
	if(pos <= mid) updatemx(pos,x,ls,l,mid);
	else 		   updatemx(pos,x,rs,mid+1,r);
	push_up(rt);
}
pair<int,int> querymx(int ql,int qr,int rt=1,int l=1,int r=n){
	
	if(ql <= l && r <= qr) return t[rt].mx;
	push_down(rt); 
	int mid = (l+r)>>1;
	if(ql > mid) return querymx(ql,qr,rs,mid+1,r);
	if(qr <= mid) return querymx(ql,qr,ls,l,mid);
	return max(querymx(ql,qr,ls,l,mid),querymx(ql,qr,rs,mid+1,r));
}

void update(int ql,int qr,int d,int rt=1,int l=1,int r=n){
	if(ql <= l && r <= qr){
		change(rt,d);
		return ;
	}
	push_down(rt);
	int mid = (l+r)>>1;
	if(ql <= mid) update(ql,qr,d,ls,l,mid);
	if(qr >  mid) update(ql,qr,d,rs,mid+1,r);
	push_up(rt);
}
int find(int rt,int l,int r){
	if(l == r) return l;
	push_down(rt);
	int mid = (l+r)>>1;
	if(t[rs].mnsz) return find(ls,l,mid);
	return find(rs,mid+1,r);
}
int query(int ql,int qr,int rt=1,int l=1,int r=n){
	if(ql <= l && r <= qr)
		return t[rt].mnsz ? -1 : find(rt,l,r);
	int mid = (l+r)>>1;
	push_down(rt);
	if(qr <= mid) return query(ql,qr,ls,l,mid);
	if(ql >  mid) return query(ql,qr,rs,mid+1,r);
	int res = query(ql,qr,rs,mid+1,r);
	if(~res) return res;
	return query(ql,qr,ls,l,mid);
}
int qry_range(int x){
	int res = query(dfn[top[x]],dfn[x]);
	return ~res ? raw[res] : qry_range(fa[top[x]]);
}
void upd_range(int x,int d){
	for(; top[x]; x=fa[top[x]]) 
		update(dfn[top[x]],dfn[x],d);
}
multiset<int> s[N];
void Add(int x,int v){
	s[x].insert(v);
	updatemx(dfn[x],*s[x].rbegin());
	upd_range(x,-1);
}
void del(int x,int v){
	assert(!s[x].empty());
	s[x].erase(s[x].lower_bound(v));
	updatemx(dfn[x],s[x].empty() ? -inf : *s[x].rbegin());
	upd_range(x,1);
}
ll ans[N];
namespace Seg{
	vector<int> v[N<<2];
	void add(int ql,int qr,int id,int rt=1,int l=0,int r=m){
		if(ql <= l && r <= qr){
			v[rt].push_back(id);
			return ;
		}
		int mid = (l+r)>>1;
		if(ql <= mid) add(ql,qr,id,ls,l,mid);
		if(qr >  mid) add(ql,qr,id,rs,mid+1,r);
	}
	ll res;
	struct node{
		int x,xv,y,yv;
	};
	void solve(int rt,int l,int r){
		vector<node> c;
		c.clear();
		for(int x : v[rt]){
			int y = qry_range(a[x].x);
			pair<int,int> p = querymx(dfn[y],dfn[y]+siz[y]-1);
			if(p.fi + a[x].v > 0){
				res += p.fi+a[x].v;
				c.push_back(node{a[x].x,a[x].v,p.se,p.fi});
				del(raw[p.se],p.fi);
				Add(a[x].x,-a[x].v);
			}
		}
		if(l == r){
			ans[l] = res;
		}else{
			int mid = (l+r)>>1;
			solve(ls,l,mid);
			solve(rs,mid+1,r);
		}
		for(node z;!c.empty();c.pop_back()){
			z = c.back();
			res -= z.xv+z.yv;
			del(z.x,-z.xv);
			Add(raw[z.y],z.yv);
		}
	}
}
int lst[N];
int main(){
	int sid = read();
	n = read(); k = read() ; m = read();
	for(int i=1;i<=n;i++) s[i].insert(0);
	for(int i=2;i<=n;i++){
		fa[i] = read();
		E[fa[i]].push_back(i);
	}
	dfs1(1,0); dfs2(1,1);
	for(int i=1;i<=k;i++) a[i].x = read(),a[i].v = read();
	for(int i=1;i<=m;i++){
		int op = read();
		if(op == 1){
			k++;
			a[k].x = read(); a[k].v = read();
			lst[k] = i;
		}else{
			int id = read();
			Seg::add(lst[id],i-1,id);
			lst[id] = -1;
		}
	}
	for(int i=1;i<=k;i++)
		if(lst[i] != -1) Seg::add(lst[i],m,i);
	build(1,1,n);
	Seg::solve(1,0,m);
	for(int i=0;i<=m;i++) cout << ans[i] << " ";
	return 0;
}