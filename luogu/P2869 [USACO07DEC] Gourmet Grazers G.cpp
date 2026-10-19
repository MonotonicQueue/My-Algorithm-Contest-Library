#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e5+1000;
int n,m,root,tot;
struct SPLAY{
	int son[2],fa;
	int val,cnt,siz;
}c[N];
int get(int x){
	return c[c[x].fa].son[1] == x;
}
inline void update(int x){
	if(!x) return;
	c[x].siz = c[x].cnt;
	if(c[x].son[0]) c[x].siz += c[c[x].son[0]].siz;
	if(c[x].son[1]) c[x].siz += c[c[x].son[1]].siz;
}
void rotate(int x){
	int f = c[x].fa, g = c[f].fa;
	int son = get(x);
	if(son == 1){
		c[f].son[1] = c[x].son[0];
		if(c[f].son[1]) c[c[f].son[1]].fa = f;
		c[x].son[0] = f;
	}else{
		c[f].son[0] = c[x].son[1];
		if(c[f].son[0]) c[c[f].son[0]].fa = f;
		c[x].son[1] = f;
	}
	c[f].fa = x;
	c[x].fa = g;
	if(g){
		if(c[g].son[0] == f) c[g].son[0] = x;
		else c[g].son[1] = x;
	}
	update(f); update(x);
}
void splay(int x,int goal){
	if(!goal) root = x;
	while(true){
		int f = c[x].fa,g = c[f].fa;
		if(f == goal) break;
		if(g != goal){
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	update(x);
}
void insert(int x){
	if(!tot){
		root = ++tot;
		c[tot].fa = 0;
		c[tot].val = x;
		c[tot].siz = c[tot].cnt = 1;
		return;
	}
	int u = root, fa = 0;
	while(true){
		if(c[u].val == x){
			c[u].cnt++;
			update(u); update(fa);
			splay(u,0);
			break;
		}
		fa = u;
		u = c[u].son[c[u].val < x];
		if(!u){
			tot++;
			c[tot].fa = fa;
			c[tot].val = x;
			c[tot].siz = c[tot].cnt = 1;
			c[fa].son[c[fa].val < x] = tot;
			update(fa);
			splay(tot,0);
			break;
		}
	}
}
int find_pre(int x){
	int u = root,ans = 1;
	while(u){
		if(c[u].val == x){
			if(c[u].son[0]){
				u = c[u].son[0];
				while(c[u].son[1]) u = c[u].son[1];
				ans = u;
			}
			break;
		}
		if(c[u].val < x && c[ans].val < c[u].val) ans = u;
		u = c[u].son[c[u].val<x];
	}
	return ans;
}
int find(int x){
	int u = root,ans = 1;
	while(u){
		if(c[u].val == x) return u;
		if(c[u].val < x && c[ans].val < c[u].val) ans = u;
		u = c[u].son[c[u].val<x];
	}
	return ans;
}
int find_nxt(int x){
	int u = root,ans = 2;
	while(u){
		if(c[u].val == x){
			if(c[u].son[1]){
				u = c[u].son[1];
				while(c[u].son[0]) u = c[u].son[0];
				ans = u;				
			}
			break;
		}
		if(c[u].val > x && c[ans].val > c[u].val) ans = u;
		u = c[u].son[c[u].val<x];
	}
	return ans;
}
void del(int x){
	int pre = find_pre(x);
	int nxt = find_nxt(x);
	splay(pre,0); splay(nxt,pre);
	int u = c[nxt].son[0];
	c[u].cnt--;
	if(!c[u].cnt){
		c[nxt].son[0] = 0;
		c[u].fa = c[u].siz = c[u].val = 0;
		c[u].son[0] = c[u].son[1] = 0;
	}else splay(u,0);
	update(nxt);
}
struct node{
	int x,y;
}a[N],b[N];
bool cmp(node x,node y){
	return x.x != y.x ? x.x < y.x : x.y < y.y;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		a[i].x = read();
		a[i].y = read();
	} sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		b[i].x = read();
		b[i].y = read();
	} sort(b+1,b+1+m,cmp);
	insert(-2e9); insert(2e9);
	int sum = 0,res = 0;
	ll ans = 0;
	for(int i=1,j=1;i<=m;i++){
		while(a[j].x<=b[i].x&&j<=n){
			insert(a[j].y); j++; sum++;
		}
		if(!sum) continue;
		int u = find(b[i].y);
		if(u == 1) continue; //没查到
		del(c[u].val); 
		res++; sum--;
		ans += b[i].x;
		if(res == n) break;
	}
	if(res == n) cout << ans;
	else cout << "-1";
	return 0;
}