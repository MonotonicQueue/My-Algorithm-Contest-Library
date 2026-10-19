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
const int N = 2e5+10;
int n,Q,k;
ll v[N],w[N];
int head[N],to[N*2],nxt[N*2],tot;
inline void add_edge(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
int c[N];
struct Ques{
	int x,y,t,id,d;
}q[N]; int sq;
struct Change{
	int x,y;
}g[N]; int sg;
int siz[N],fa[N],st[N],ed[N],dfn[N],Num;
int son[N],top[N],dep[N],pos[N];
void dfs1(int x,int father){
	dep[x] = dep[father]+1;
	st[x] = ++Num; dfn[Num] = x;
	fa[x] = father; siz[x] = 1;
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == father) continue;
		dfs1(y,x);
		siz[x] += siz[y];
		if(siz[son[x]] < siz[y]) son[x] = y;
	}
	ed[x] = ++Num; dfn[Num] = x;
}
void dfs2(int x,int topx){
	top[x] = topx;
	if(!son[x]) return;
	dfs2(son[x],topx);
	for(int i=head[x];i;i=nxt[i]){
		int y = to[i];
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y,y);
	}
}
int lca(int x,int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	return x;
}
bool cmp(Ques x,Ques y){
	if(pos[x.x] != pos[y.x]) return pos[x.x] < pos[y.x];
	if(pos[x.y] != pos[y.y]) return pos[x.y] < pos[y.y];
	return x.t < y.t;
}
ll cnt[N],sum,ans[N];
bool used[N];
inline void add(int x){
	x = c[x];
	cnt[x]++;
	sum += v[x]*w[cnt[x]];
}
inline void del(int x){
	x = c[x];
	sum -= v[x]*w[cnt[x]];
	cnt[x]--;
}
inline void work(int x){
	if(used[x]) del(x);
	else add(x);
	used[x] ^= 1;
}
inline void change(int t){
	if(used[g[t].x]){
		sum -= w[cnt[c[g[t].x]]]*v[c[g[t].x]];
		cnt[c[g[t].x]]--;
		cnt[g[t].y]++;
		sum += w[cnt[g[t].y]]*v[g[t].y];
	}
	swap(g[t].y,c[g[t].x]);
}
signed main(){
	n = read(); k = read(); Q = read();
	for(int i=1;i<=k;i++) v[i] = read();
	for(int i=1;i<=n;i++) w[i] = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		add_edge(u,v); add_edge(v,u);
	}
	dfs1(1,0); dfs2(1,1);
	int block = pow(2*n,0.666666);
	for(int i=1;i<=2*n;i++) pos[i] = (i-1)/block+1;
	for(int i=1;i<=n;i++) c[i] = read();
	while(Q--){
		int type = read();
		int x = read(),y = read();
		if(type == 1){
			q[++sq].id = sq; q[sq].t = sg;
			if(st[x] > st[y]) swap(x,y);
			int d = lca(x,y);
			if(x == d){
				q[sq].x = st[x];
				q[sq].y = st[y];
				q[sq].d = 0;
			}else{
				q[sq].x = ed[x];
				q[sq].y = st[y];
				q[sq].d = d;
			}
		}
		else g[++sg] = Change{x,y};
	}
	sort(q+1,q+1+sq,cmp);
	int L = 1,R = 0,T = 0;
	for(int i=1;i<=sq;i++){
		while(L > q[i].x) work(dfn[--L]);
		while(L < q[i].x) work(dfn[L++]);
		while(R > q[i].y) work(dfn[R--]);
		while(R < q[i].y) work(dfn[++R]);
		if(q[i].d) work(q[i].d);
		while(T < q[i].t) change(++T);
		while(T > q[i].t) change(T--);
		ans[q[i].id] = sum;
		if(q[i].d) work(q[i].d);
	}
	for(int i=1;i<=sq;i++) printf("%lld\n",ans[i]);
	return 0;
}