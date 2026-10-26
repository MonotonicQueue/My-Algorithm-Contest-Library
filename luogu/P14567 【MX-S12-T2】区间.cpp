#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
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
int n,c[N],cnt[N],a[N],L[N],R[N],d[N];
ll v[N],f[N];
int mn[N<<2],mx[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void push_up(int rt){
	mn[rt] = min(mn[ls],mn[rs]);
	mx[rt] = max(mx[ls],mx[rs]);
}
void build(int rt,int l,int r){
	if(l == r){
		mn[rt] = L[c[l]];
		mx[rt] = R[c[l]];
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int pos,int d){
	if(l == r){
		mx[rt] = max(mx[rt],d);
		return ;
	}
	int mid = (l+r) >> 1;
	if(pos <= mid) update(ls,l,mid,pos,d);
	if(pos >  mid) update(rs,mid+1,r,pos,d);
	push_up(rt);
}
int querymn(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return mn[rt];
	int mid = (l+r) >> 1,res = 1e9;
	if(ql <= mid) res = min(res,querymn(ls,l,mid,ql,qr));
	if(qr >  mid) res = min(res,querymn(rs,mid+1,r,ql,qr));
	return res;
}
int querymx(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return mx[rt];
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res = max(res,querymx(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,querymx(rs,mid+1,r,ql,qr));
	return res;
}
ll ans = 1e18;
ll calc(int l,int r){
	ll sum = 0;
	for(int i=l;i<=r;i++)
		sum += v[i]*f[i-l+1];
	return sum;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) c[i] = read();
	for(int i=1;i<=n;i++) v[i] = read();
	for(int i=1;i<=n;i++) f[i] = read();
	for(int i=1;i<=n;i++) cnt[c[i]]++;
	for(int i=1;i<=n;i++){
		L[i] = n,R[i] = 1;
	}
	for(int i=1;i<=n;i++){
		L[c[i]] = min(L[c[i]],i);
		R[c[i]] = max(R[c[i]],i);
	}
	build(1,1,n);
	vector<pii> v;
	for(int i=n;i>=1;i--){
		if(i != L[c[i]]) continue;
		if(i > querymn(1,1,n,L[c[i]],R[c[i]])) continue;
		d[i] = querymx(1,1,n,L[c[i]],R[c[i]]);
		update(1,1,n,i,d[i]);
		v.emplace_back(i,d[i]);
	}
	sort(v.begin(),v.end());
	pii now = mk(1,0);
	for(auto it : v){
		if(now.se == 0) now = it;
		else if(it.fi > now.se) ans = min(ans,calc(now.fi,now.se)),now = it;
		else{
			// assert(it.se < now.se && it.fi > now.fi);
			now = it;
		}
	}
	ans = min(ans,calc(now.fi,now.se));
	cout << ans;
} 
int main(){
	// freopen("interval.in","r",stdin);
	// freopen("interval.out","w",stdout);
	int T = 1;
	while(T--) solve(); 
	return 0;
}
