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
const int N = 1.5e5+10;
int n,m;
struct Edge{
	int u,v,A,B;
}E[N];
bool cmp(Edge x,Edge y){
	return x.A != y.A ? x.A < y.A : x.B < y.B;
}
int w[N];
struct LCT{
	int fa,son[2];
	int tag,maxn,id;
}c[N];
bool isRoot(int x){
	int fa = c[x].fa;
	return c[fa].son[0] != x && c[fa].son[1] != x;
}
#define ls c[x].son[0]
#define rs c[x].son[1]
inline void push_up(int x){
	c[x].maxn = w[x]; c[x].id = x;
	if(ls && c[ls].maxn > c[x].maxn) c[x].maxn = c[ls].maxn,c[x].id = c[ls].id;
	if(rs && c[rs].maxn > c[x].maxn) c[x].maxn = c[rs].maxn,c[x].id = c[rs].id;
}
inline void reverse(int x){
	if(!x) return;
	swap(ls,rs);
	c[x].tag ^= 1;
}
inline void push_down(int x){
	if(!c[x].tag) return;
	reverse(ls); reverse(rs);
	c[x].tag = 0;
}
inline void push(int x){
	if(!isRoot(x)) push(c[x].fa);
	push_down(x);
}
inline void rotate(int x){
	int y = c[x].fa,z = c[y].fa;
	bool k = c[y].son[1] == x;
	if(!isRoot(y)) c[z].son[c[z].son[1] == y] = x;
	c[x].fa = z;
	c[y].son[k] = c[x].son[k^1];
	if(c[x].son[k^1]) c[c[x].son[k^1]].fa = y;
	c[y].fa = x;
	c[x].son[k^1] = y;
	push_up(y);
}
void splay(int x){
	push(x);
	while(!isRoot(x)){
		int y = c[x].fa,z = c[y].fa;
		if(!isRoot(y))
			(c[z].son[0] == y)^(c[y].son[0] == x) ? rotate(x) : rotate(y);
		rotate(x);
	}
	push_up(x);
}
void access(int x){
	for(int child=0;x;child=x,x=c[x].fa){
		splay(x);
		c[x].son[1] = child;
		push_up(x);
	}
}
inline void makeroot(int x){
	access(x); splay(x); reverse(x);
}
inline void split(int x,int y){
	makeroot(x); access(y); splay(y);
}
inline void link(int x,int y){
	makeroot(x); c[x].fa = y;
}
int findroot(int x){
	access(x); splay(x);
	while(ls) push_down(x),x = ls;
	return x;
}
int main() {
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		E[i].u = read(); E[i].v = read();
		E[i].A = read(); E[i].B = read();
	}
	sort(E+1,E+1+m,cmp);
	int ans = 1e9;
	for(int i=1;i<=m;i++){
		w[i+n] = E[i].B;
		if(E[i].u == E[i].v) continue;
		int x = E[i].u,y = E[i].v;
		if(findroot(x) != findroot(y)){
			link(x,i+n); link(i+n,y);
		}else{
			split(x,y);
			int pos = c[y].id; ll ma = c[y].maxn;
			if(ma <= w[i+n]) continue;
			splay(pos);
			c[c[pos].son[0]].fa = 0; c[c[pos].son[1]].fa = 0;
			link(x,i+n); link(i+n,y);
		}
		if(findroot(1) == findroot(n)){
			split(1,n);
			ans = min(ans,c[n].maxn+E[i].A);
		}
	}
	if(ans == 1e9) printf("-1");
	else printf("%lld",ans);
	return 0;
}