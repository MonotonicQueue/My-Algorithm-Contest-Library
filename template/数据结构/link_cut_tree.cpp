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
int n,m;
struct Link_Cut_Tree{
	int fa,son[2];
	int sum,val,tag;
}c[N];
#define ls c[x].son[0]
#define rs c[x].son[1]
bool isRoot(int x){
	int fa = c[x].fa;
	return c[fa].son[0] != x && c[fa].son[1] != x;
}
inline void push_up(int x){
	c[x].sum = c[x].val^c[ls].sum^c[rs].sum;
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
	bool k = c[y].son[1] == x;//判断是左儿子或右儿子
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
		rs = child;
		push_up(x);
	}
}
void makeroot(int x){
	access(x); splay(x); reverse(x);
}
void split(int x,int y){
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x,int y){
	makeroot(x); c[x].fa = y;
}
void cut(int x,int y){
	split(x,y);
	if(c[y].son[0] != x || rs) return;
	c[y].son[0] = 0; c[x].fa = 0; 
	push_up(x);
}
int findroot(int x){
	access(x); splay(x);
	while(ls) push_down(x),x = ls;
	return x;
}
int main() {
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		c[i].sum = c[i].val = read();
	while(m--){
		int op = read();
		int a = read(),b = read();
		if(op == 0){
			split(a,b);
			cout << c[b].sum << "\n";
		}else if(op == 1){
			if(findroot(a) != findroot(b))
				link(a,b);
		}else if(op == 2){
			cut(a,b);
		}else{
			splay(a); c[a].val = b;
		}
	}
	return 0;
}
