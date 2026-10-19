#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
const int mod = 1e9+7;
int n,m,A,P,Q;
int a[N];
int rnd(){
	A = (7*A+13)%19260817;
	return A;
}
int root[N],cnt;
struct Segment{
	int ls,rs;
	ll sum;
}t[N*20];
#define lc t[rt].ls
#define rc t[rt].rs
int build(int l,int r){
	int rt = ++cnt;
	if(l == r){
		t[rt].sum = 1ll << a[l];
		return rt;
	}
	int mid = (l+r) >> 1;
	t[rt].ls = build(l,mid);
	t[rt].rs = build(mid+1,r);
	t[rt].sum = t[lc].sum+t[rc].sum;
	return rt;
}
int update(int u,int l,int r,int pos,int d){
	int rt = ++cnt; t[rt] = t[u];
	if(l == r) return t[rt].sum = 1ll << d,rt;
	int mid = (l+r) >> 1;
	if(pos <= mid) t[rt].ls = update(lc,l,mid,pos,d);
	else 		   t[rt].rs = update(rc,mid+1,r,pos,d);
	t[rt].sum = t[lc].sum+t[rc].sum;
	return rt;
}
ll query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return t[rt].sum;
	ll res = 0; int mid = (l+r) >> 1;
	if(ql <= mid) res += query(lc,l,mid,ql,qr);
	if(qr >  mid) res += query(rc,mid+1,r,ql,qr);
	return res;
}
int main(){
	n = read(); m = read(); A = read();
	P = read(); Q = read();
	for(int i=1;i<=n;i++) a[i] = rnd()%Q+1;
	root[0] = build(1,n);
	for(int _=1;_<=m;_++){
		int opt = rnd()%P+1;
		auto getLR = [&](int &l,int &r){
			int L = rnd()%n+1,R = rnd()%n+1;
			l = min(L,R); r = max(L,R);
		};
		root[_] = root[_-1];
		if(opt == 1){
			int l,r; getLR(l,r);
			ll res = query(root[_],1,n,l,r);
			for(int i=60;~i;i--)
				if((res >> i) & 1){
					cout << i << "\n";
					break;
				}
		}else if(opt == 2){
			int l,r; getLR(l,r);
			int k = rnd()%Q+1;
			ll res = query(root[_],1,n,l,r),ans = 0;
			for(int i=k;i<=60;i++)
				if((res >> i) & 1) ans = (ans+(1ll << (i+1)))%mod;
				else break;
			cout << ans << "\n";
		}else if(opt == 3){
			int pos = rnd()%n+1,k = rnd()%Q+1;
			root[_] = update(root[_],1,n,pos,k);
		}else{
			int t = rnd()%_;
			root[_] = root[t];
		}
	}
	return 0;
}