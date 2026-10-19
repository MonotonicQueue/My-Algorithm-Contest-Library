#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
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
const int N = 4e5+10;
const ll inf = 2e18;
int n,Q,a[N];
namespace KTT{
struct Line{
	ll k,b;
	Line(ll k=0,ll b=0): k(k),b(b){}
	Line operator+(const Line &o)const{
		return Line(k+o.k,b+o.b);
	}
};
ll tag[N<<2];
pair<Line,ll> max(Line a,Line b){
	//求出两条直线 a,b 在 x = 0 处的 max 以及这个 max 会改变的最小 x
	if(a.k < b.k || (a.k == b.k && a.b < b.b)) swap(a,b);
	if(a.b >= b.b) return mk(a,inf);
	return mk(b,(b.b-a.b)/(a.k-b.k));
}
struct node{
	Line sum,lmx,rmx,mx;
	ll x;
	node operator+(const node &o)const{
		node res;
		res.x = min(x,o.x);
		auto tmp = max(lmx,o.lmx+sum);
		res.lmx = tmp.fi; res.x = min(res.x,tmp.se);
		tmp = max(o.rmx,rmx+o.sum);
		res.rmx = tmp.fi; res.x = min(res.x,tmp.se);
		res.sum = sum+o.sum;

		tmp = max(mx,o.mx); res.x = min(res.x,tmp.se);
		tmp = max(tmp.fi,rmx+o.lmx);
		res.x = min(res.x,tmp.se);
		res.mx = tmp.fi;
		return res;
	}
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
	if(l == r){
		t[rt].sum = t[rt].lmx = t[rt].rmx = t[rt].mx = Line(1,a[l]);
		t[rt].x = inf;
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt] = t[ls]+t[rs];
}
void change(int rt,ll d){
	tag[rt] += d; t[rt].x -= d;
	t[rt].lmx.b += t[rt].lmx.k*d;
	t[rt].rmx.b += t[rt].rmx.k*d;
	t[rt].mx.b += t[rt].mx.k*d;
	t[rt].sum.b += t[rt].sum.k*d;
}
void upd(int rt,int l,int r,ll d){
	if(t[rt].x < d){
		d += tag[rt];
		tag[rt] = 0;
		int mid = (l+r) >> 1;
		upd(ls,l,mid,d);
		upd(rs,mid+1,r,d);
		t[rt] = t[ls]+t[rs];
	}else change(rt,d);
}
inline void push_down(int rt){
	if(tag[rt]){
		change(ls,tag[rt]);
		change(rs,tag[rt]);
		tag[rt] = 0;
	}
}
void update(int rt,int l,int r,int ql,int qr,ll d){
	if(ql <= l && r <= qr) return upd(rt,l,r,d);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update(ls,l,mid,ql,qr,d);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
	t[rt] = t[ls]+t[rs];
}
node query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return t[rt];
	push_down(rt);
	int mid = (l+r) >> 1;
	if(qr <= mid) return query(ls,l,mid,ql,qr);
	if(ql >  mid) return query(rs,mid+1,r,ql,qr);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
}
int main(){
	n = read(); Q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	KTT::build(1,1,n);
	while(Q--){
		int op = read(),l = read(),r = read();
		if(op == 1){
			int x = read();
			KTT::update(1,1,n,l,r,x);
		}else cout << max(KTT::query(1,1,n,l,r).mx.b,0ll) << "\n";
	}
	return 0;
}