#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 5e5+10;
int n,m,a[N];
int nxt[N],vis[N];
int mx[N<<2],mn[N<<2],tag[N<<2],add[N<<2];
int mix[N<<2],sum[N<<2],len[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	mx[rt] = max(mx[ls],mx[rs]);
	mn[rt] = min(mn[ls],mn[rs]);
	mix[rt] = min(mix[ls],mix[rs]);
	if(mix[ls] < mix[rs]) sum[rt] = sum[ls];
	else if(mix[rs] < mix[ls]) sum[rt] = sum[rs];
	else sum[rt] = sum[ls]+sum[rs];
}
inline void change_add(int rt,int d){
	mx[rt] += d; add[rt] += d;
	mn[rt] += d; mix[rt] -= d;
}
inline void change(int rt,int d){
	add[rt] = 0; tag[rt] = d;
	mx[rt] = mn[rt] = d; mix[rt] = nxt[d];
	sum[rt] = len[rt];
}
inline void push_down(int rt){
	if(tag[rt]){
		if(add[rt]) tag[rt] += add[rt],add[rt] = 0;
		change(ls,tag[rt]);
		change(rs,tag[rt]);
		tag[rt] = 0;
	}
	if(add[rt]){
		change_add(ls,add[rt]);
		change_add(rs,add[rt]);
		add[rt] = 0;
	}
}
void build(int rt,int l,int r){
	len[rt] = r-l+1;
	if(l == r){
		mx[rt] = mn[rt] = a[l];
		mix[rt] = nxt[a[l]];
		sum[rt] = 1;
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void update1(int rt,int l,int r,int ql,int qr,int d){
	if(ql <= l && r <= qr){
		if(mix[rt] >= d) return change_add(rt,d);
		if(mn[rt] == mx[rt]) return change(rt,mn[rt]+d);
	}
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update1(ls,l,mid,ql,qr,d);
	if(qr >  mid) update1(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
void update2(int rt,int l,int r,int ql,int qr,int d){
	if(ql <= l && r <= qr && mn[rt] == mx[rt]) return change(rt,mn[rt]*d);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update2(ls,l,mid,ql,qr,d);
	if(qr >  mid) update2(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
void update3(int rt,int l,int r,int ql,int qr,int d){
	if(ql <= l && r <= qr) return change(rt,d);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update3(ls,l,mid,ql,qr,d);
	if(qr >  mid) update3(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return (!mix[rt])*sum[rt];
	push_down(rt);
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res += query(ls,l,mid,ql,qr);
	if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
	return res;
}
signed main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	vis[42] = vis[424] = vis[4242] = vis[42424] = vis[424242] = 1;
	int lst = 1e9;
	for(int i=500000;i;i--){
		if(vis[i]) lst = i;
		nxt[i] = lst-i;
	}
	build(1,1,n);
	while(m--){
		int op = read(),l = read(),r = read();
		if(op == 1){
			int x = read();
			update1(1,1,n,l,r,x);
		}else if(op == 2){
			int x = read();
			if(x == 1) continue;
			update2(1,1,n,l,r,x);
		}else if(op == 3){
			int x = read();
			update3(1,1,n,l,r,x);
		}else printf("%d\n",query(1,1,n,l,r));
	}
    return 0;
}
