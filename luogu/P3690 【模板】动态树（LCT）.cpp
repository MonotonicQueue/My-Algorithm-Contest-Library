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
int n,m,val[N]; 
struct Link_Cut_Tree{
	int son[2],fa;
	int val,tag,sum;
}t[N];
#define ls t[x].son[0]
#define rs t[x].son[1]
inline void push_up(int x){
	t[x].sum = t[ls].sum^t[x].val^t[rs].sum;
}
bool isRoot(int x){
	int f = t[x].fa;
	return t[f].son[0] != x && t[f].son[1] != x;
}
void rotate(int x){
	int f = t[x].fa,g = t[f].fa;
	bool k = t[f].son[1] == x;
	if(!isRoot(f)) t[g].son[t[g].son[1] == f] = x;
	t[x].fa = g;
	t[f].fa = x;
	t[f].son[k] = t[x].son[k^1];
	if(t[x].son[k^1]) t[t[x].son[k^1]].fa = f;
	t[x].son[k^1] = f;
	push_up(f);
}
inline void reverse(int x){
	if(!x) return ;
	swap(ls,rs);
	t[x].tag ^= 1;
}
inline void push_down(int x){
	if(t[x].tag){
		reverse(ls); reverse(rs);
		t[x].tag = 0;
	}
}
void push(int x){
	if(!isRoot(x)) push(t[x].fa);
	push_down(x);
}
void splay(int x){
	push(x);
	while(!isRoot(x)){
		int y = t[x].fa,z = t[y].fa;
		if(!isRoot(y))
			(t[z].son[0] == y) ^ (t[y].son[0] == x) ? rotate(x) : rotate(y);
		rotate(x);
	}
	push_up(x);
}
void access(int x){
	for(int child=0;x;child=x,x=t[x].fa){
		splay(x);
		rs = child;
		push_up(x);
	}
}
void makeroot(int x){
	access(x); splay(x); reverse(x);
}
void split(int x,int y){
	makeroot(x); access(y); splay(y);
} 
int findroot(int x){
	access(x); splay(x);
	while(ls) push_down(x),x = ls;
	return x;
}
void link(int x,int y){
	makeroot(x); t[x].fa = y;
}
void cut(int x,int y){
	split(x,y);
	if(t[y].son[0] != x || rs) return ;
	t[y].son[0] = t[x].fa = 0;
	push_up(x);
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) t[i].sum = t[i].val = read();
	while(m--){
		int op = read(),x = read(),y = read();
		if(op == 0){
			split(x,y);
			cout << t[y].sum <<"\n";
		}else if(op == 1){
			if(findroot(x) != findroot(y)) link(x,y);
		}else if(op == 2){
			cut(x,y);
		}else{
			splay(x); t[x].val = y;
		}
	}
	return 0;
}
