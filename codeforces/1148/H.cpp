#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 2e5+10;
int n,p[N],pl[N],pr[N];
namespace SGT{
	#define ls rt<<1
	#define rs rt<<1|1
	int mn[N<<2];
	inline void push_up(int rt){
		mn[rt] = min(mn[ls],mn[rs]);
	}
	void update(int rt,int l,int r,int pos,int d){
		if(l == r) return mn[rt] = d,void();
		int mid = (l+r) >> 1;
		if(pos <= mid) update(ls,l,mid,pos,d);
		else		   update(rs,mid+1,r,pos,d);
		push_up(rt);
	}
	int query(int rt,int l,int r,int k){
		if(l == r) return l;
		int mid = (l+r) >> 1;
		if(mn[ls] < k) return query(ls,l,mid,k);
		return query(rs,mid+1,r,k);
	}
	#undef ls
	#undef rs
}
map<int,int> root[N];
struct Segment{
	int ls,rs;
	ll K,B;
	ll tagk,tagb;
}t[N<<6];
int cnt;
int build(int l,int r){
	int rt = ++cnt;
	if(l == r) return rt;
	int mid = (l+r) >> 1;
	t[rt].ls = build(l,mid);
	t[rt].rs = build(mid+1,r);
	return rt;
}
int update(int u,int l,int r,int ql,int qr,ll k,ll b){
	int rt = ++cnt; t[rt] = t[u];
	if(ql <= l && r <= qr){
		t[rt].tagk += k;
		t[rt].tagb += b;
		return rt;
	}
	t[rt].K += (min(r,qr)-max(l,ql)+1)*k;
	t[rt].B += (min(r,qr)-max(l,ql)+1)*b;
	int mid = (l+r) >> 1;
	if(ql <= mid) t[rt].ls = update(t[rt].ls,l,mid,ql,qr,k,b);
	if(qr >  mid) t[rt].rs = update(t[rt].rs,mid+1,r,ql,qr,k,b);
	return rt;
}
ll query(int rt,int l,int r,int ql,int qr,ll x){
	if(ql <= l && r <= qr) return (t[rt].tagk*(r-l+1)+t[rt].K)*x+t[rt].tagb*(r-l+1)+t[rt].B;
	ll res = (t[rt].tagk*x+t[rt].tagb)*(min(r,qr)-max(l,ql)+1);
	int mid = (l+r) >> 1;
	if(ql <= mid) res += query(t[rt].ls,l,mid,ql,qr,x);
	if(qr >  mid) res += query(t[rt].rs,mid+1,r,ql,qr,x);
	return res;
}
void add(int x,int l,int r,int t){
	int u = (--root[x].end())->se;
	root[x][t] = update(u,1,n,l,r,1,1-t);
	if(!pl[x]) pl[x] = l,pr[x] = r;
	else pl[x] = min(pl[x],l),pr[x] = max(pr[x],r);
}
int main(){
	n = read();
	if(n == 0) return 0;
	ll lstans = 0;
	int rt = build(1,n);
	for(int i=0;i<=n;i++) root[i][0] = rt;
	for(int i=1;i<=n;i++){
		ll x = read(),l = read(),r = read(),k = read();
		x = (x+lstans) % (n+1);
		l = (l+lstans) % i + 1;
		r = (r+lstans) % i + 1;
		k = (k+lstans) % (n+1);
		if(l > r) swap(l,r);
		p[x] = i;
		SGT::update(1,0,n,x,i);
		if(pl[x]){
			int now = pr[x];
			while(now >= pl[x]){
				int y = SGT::query(1,0,n,now);
				add(y,max(p[y]+1,pl[x]),now,i);
				now = max(p[y]+1,pl[x])-1;
			}
			int u = (--root[x].end())->se;
			root[x][i] = update(u,1,n,pl[x],pr[x],-1,i-1);
			pl[x] = pr[x] = 0;
		}
		add(x ? 0 : 1,i,i,i);
		lstans = query((--root[k].upper_bound(r))->se,1,n,l,r,r);
		cout << lstans << "\n";
	}
    return 0;
}