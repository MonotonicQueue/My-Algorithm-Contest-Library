#include<bits/stdc++.h>
#define ll long long
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
int n,q;
ll W,a[N],t[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	t[rt] = t[ls]+t[rs];
}
void build(int rt,int l,int r){
	if(l == r){
		t[rt] = a[l];
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
inline void change(int rt,int l,int r,ll d){
	t[rt] += (r-l+1)*d;
	tag[rt] += d;
}
inline void push_down(int rt,int l,int r){
	if(tag[rt]){
		int mid = (l+r) >> 1;
		change(ls,l,mid,tag[rt]);
		change(rs,mid+1,r,tag[rt]);
		tag[rt] = 0;
	}
}
void update(int rt,int l,int r,int ql,int qr,ll d){
	if(ql <= l && r <= qr) return change(rt,l,r,d);
	push_down(rt,l,r);
	int mid = (l+r) >> 1;
	if(ql <= mid) update(ls,l,mid,ql,qr,d);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
int query(int rt,int l,int r,ll now,ll bas){
	if(l == r) return l-1;
	push_down(rt,l,r);
	int mid = (l+r) >> 1;
	if(bas*t[ls] < now) return query(rs,mid+1,r,now-bas*t[ls],bas);
	return query(ls,l,mid,now,bas);
}
void solve(){
	ll sum = t[1],ans = 0,now = W,bas = 1;
	while(now > sum){
		now -= sum;
		ans += n;
		sum *= 2;
		bas *= 2;
	}
	ans += query(1,1,n,now,bas);
	cout << ans << "\n";
}
int main(){
//	freopen("wxyt.in","r",stdin);
//	freopen("wxyt.out","w",stdout);
	n = read(); q = read(); W = read();
	for(int i=1;i<=n;i++) a[i] = read();
	build(1,1,n);
	while(q--){
		int l = read(),r = read();
		ll d = read();
		update(1,1,n,l,r,d);
		solve();
	}
	return 0;
}