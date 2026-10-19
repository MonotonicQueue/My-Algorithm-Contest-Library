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
const int N = 1e5+5;
int n,m;
ll a[N];
struct Segment_Tree{
	int l,r;
	ll sum,tag;
	#define ls rt<<1
	#define rs rt<<1|1
}c[N*4];
void push_up(int rt){
	c[rt].sum = c[ls].sum+c[rs].sum;
}
void build(int rt,int l,int r){
	c[rt].l = l; c[rt].r = r;
	if(l == r){
		c[rt].sum = a[l];
		return;
	} 
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void add_tag(int rt,ll k){
	c[rt].sum += (c[rt].r-c[rt].l+1)*k;
	c[rt].tag += k;
}
void push_down(int rt){
	add_tag(ls,c[rt].tag);
	add_tag(rs,c[rt].tag);
	c[rt].tag = 0;
}
void update(int rt,int l,int r,ll k){
	if(l <= c[rt].l && c[rt].r <= r){
		add_tag(rt,k);
		return;
	}
	push_down(rt);
	int mid = (c[rt].l+c[rt].r)>>1;
	if(l <= mid) update(ls,l,r,k);
	if(mid < r) update(rs,l,r,k);
	push_up(rt);
}
ll query(int rt,int l,int r){
	if(l <= c[rt].l && c[rt].r <= r) return c[rt].sum;
	push_down(rt);
	int mid = (c[rt].l+c[rt].r)>>1;
	ll sum = 0;
	if(l <= mid) sum += query(ls,l,r);
	if(mid < r) sum += query(rs,l,r);
	return sum;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++)  a[i] = read();
	build(1,1,n);
	while(m--){
		int op,x,y;
		op = read();
		x = read(); y = read();
		if(op == 1){
			ll k = read();
			update(1,x,y,k);
		}else{
			cout << query(1,x,y) << "\n";
		}
	}
	return 0;
}