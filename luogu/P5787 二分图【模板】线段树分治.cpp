#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,m,k;
struct Edge{int x,y;}e[N];
vector<int>v[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void update(int rt,int l,int r,int ql,int qr,int x){
	if(ql <= l && r <= qr){
		v[rt].push_back(x);
		return;
	}
	int mid = (l+r)>>1;
	if(ql <= mid) update(ls,l,mid,ql,qr,x);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,x);
}
int fa[N],h[N],top;
struct Stk{int x,y,h1,h2;}st[N];
int get(int x){
	if(x == fa[x]) return x;
	return get(fa[x]);
}
void merge(int x,int y){
	int fx = get(x),fy = get(y);
	if(h[fx] > h[fy]) swap(fx,fy);
	st[++top] = Stk{fx,fy,h[fx],h[fy]};
	fa[fx] = fy; h[fy] += h[fx];
}
void solve(int rt,int l,int r){
	bool flag = true;
	int lsttop = top;
	for(int i=0;i<v[rt].size();i++){
		int a = get(e[v[rt][i]].x),b = get(e[v[rt][i]].y);
		if(a == b){
			flag = false;
			for(int i=l;i<=r;i++) puts("No");
			break;
		}
		merge(e[v[rt][i]].x,e[v[rt][i]].y+n); 
		merge(e[v[rt][i]].x+n,e[v[rt][i]].y); 
	}
	if(flag){
		if(l == r) puts("Yes");
		else{
			int mid = (l+r)>>1;
			solve(ls,l,mid);
			solve(rs,mid+1,r);
		}
	}
	while(top > lsttop){
		fa[st[top].x] = st[top].x;
		h[st[top].y] = st[top].h2;
		top--;
	}
}
int main(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		e[i].x = read(); e[i].y = read();
		int l = read()+1,r = read();
		update(1,1,n,l,r,i);
	}
	for(int i=1;i<=2*n;i++) fa[i] = i,h[i] = 1;
	solve(1,1,n);
	return 0;
} 
