#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int M = 5e5+10; 
int n,m,q,h[N],a[N],len,cnt,val[N];
struct Edge{int u,v,w;}e[M];
inline void lsh(){
	for(int i=1;i<=n;i++) a[i] = h[i];
	sort(a+1,a+1+n);
	len = unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++) h[i] = lower_bound(a+1,a+1+len,h[i])-a;
}
int bel[N],fa[N][20];
vector<int> G[N]; 
int get(int x){
	return x == bel[x] ? x : bel[x] = get(bel[x]);
}
int st[N],ed[N],b[N],tot;
void dfs(int x,int ft){
	st[x] = ++tot; b[tot] = x;
	fa[x][0] = ft;
	for(int i=1;i<=18;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int y : G[x]) dfs(y,x);
	ed[x] = tot;
}
int root[N],num;
struct Segment{
	int ls,rs;
	int siz;
}t[N<<5];
inline void push_up(int rt){
	t[rt].siz = t[t[rt].ls].siz+t[t[rt].rs].siz;
}
int update(int rt,int l,int r,int pos){
	int u = ++num;
	t[u] = t[rt]; t[u].siz++;
	if(l == r) return u;
	int mid = (l+r) >> 1;
	if(pos <= mid) t[u].ls = update(t[u].ls,l,mid,pos);
	else		   t[u].rs = update(t[u].rs,mid+1,r,pos);
	return u; 
}
int query(int u,int v,int l,int r,int k){
	if(l == r) return a[l];
	int mid = (l+r) >> 1;
	if(k <= t[t[v].rs].siz-t[t[u].rs].siz) return query(t[u].rs,t[v].rs,mid+1,r,k);
	return query(t[u].ls,t[v].ls,l,mid,k-(t[t[v].rs].siz-t[t[u].rs].siz)); 
}
int main(){
	n = read(); m = read(); q = read();
	for(int i=1;i<=n;i++) h[i] = read();
	lsh(); cnt = n;
	for(int i=1;i<=m;i++){
		e[i].u = read(); e[i].v = read();
		e[i].w = read();
	}
	sort(e+1,e+1+m,[](Edge x,Edge y){return x.w < y.w;});
	for(int i=1;i<=2*n;i++) bel[i] = i;
	for(int i=1;i<=m;i++){
		int x = e[i].u,y = e[i].v;
		x = get(x); y = get(y);
		if(x == y) continue;
		val[++cnt] = e[i].w;
		bel[x] = bel[y] = cnt;
		G[cnt].push_back(x);
		G[cnt].push_back(y);
	} 
	val[0] = 2e9;
	for(int i=1;i<=cnt;i++) if(bel[i] == i) dfs(i,0);
	for(int i=1;i<=tot;i++){
		root[i] = root[i-1];
		if(b[i] <= n) root[i] = update(root[i],1,len,h[b[i]]);
	}
	int lstans = 0;
	while(q--){
		int v = read(),x = read(),k = read();
		v = (v^lstans)%n+1;
		x = x^lstans;
		k = (k^lstans)%n+1;
		for(int i=18;~i;i--)
			if(fa[v][i] && val[fa[v][i]] <= x) v = fa[v][i];
		if(t[root[ed[v]]].siz-t[root[st[v]-1]].siz >= k) printf("%d\n",lstans = query(root[st[v]-1],root[ed[v]],1,len,k));
		else puts("-1"),lstans = 0;
	}
    return 0;
}
