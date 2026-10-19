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
int n,m,k;
struct node{
	int l,r;
	ll w;
}a[N];
vector<int> v[N];
ll val[N<<2],tag[N<<2],w;
int b[N],tot;
inline void lsh_init(){
	sort(b+1,b+1+tot);
	tot = unique(b+1,b+1+tot)-b-1;
	for(int i=1;i<=m;i++){
		a[i].l = lower_bound(b+1,b+1+tot,a[i].l-1)-b;
		a[i].r = lower_bound(b+1,b+1+tot,a[i].r+1)-b;
	}
	for(int i=1;i<=m;i++) v[a[i].r].push_back(i);
}
#define ls rt<<1
#define rs rt<<1|1
void push_up(int rt){
	val[rt] = max(val[ls],val[rs]);
} 
void build(int rt,int l,int r){
	val[rt] = 0;tag[rt] = 0;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline void push_down(int rt){
	if(tag[rt]){
		val[ls] += tag[rt];
		val[rs] += tag[rt];
		tag[ls] += tag[rt];
		tag[rs] += tag[rt]; 
		tag[rt] = 0;
	}
}
void update(int rt,int l,int r,int ql,int qr,ll d){
	if(ql <= l && r <= qr){
		val[rt] += d;
		tag[rt] += d;
		return ;
	}
	push_down(rt);
	int mid = (l+r)>>1;
	if(ql <= mid) update(ls,l,mid,ql,qr,d);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
	push_up(rt);
} 
ll query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return val[rt];
	push_down(rt);
	int mid = (l+r)>>1; ll res = 0;
	if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
	return res; 
}
int main(){
	int C = read(),T = read();
	while(T--){
		tot = 0;
		n = read(); m = read(); k = read(); w = read();
		for(int i=1;i<=m;i++){
			int x = read(),y = read();
			a[i].l = x-y+1; a[i].r = x;
			a[i].w = read();
			b[++tot] = a[i].l-1; b[++tot] = a[i].r+1;
		}
		lsh_init();
		ll ans = 0;
		build(1,1,tot);
		update(1,1,tot,1,1,w*b[1]);
		int t = 0;
		for(int i=2;i<=tot;i++){
			for(int j:v[i]) update(1,1,tot,1,a[j].l,a[j].w);
			for(;b[i]-b[t]-1>k;t++);
			ans = max(ans,query(1,1,tot,t,i-1)+w-b[i]*w);
			update(1,1,tot,i,i,ans+b[i]*w);
		}
		for(int i=1;i<=tot;i++) v[i].clear();
		cout << ans << "\n";
	}
	return 0;
} 