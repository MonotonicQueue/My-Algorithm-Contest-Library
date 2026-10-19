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
const int N = 2e5+10;
int n,Q,a[N],m;
vector<pii> q[N];
vector<int> v[N];
int root[N];
struct Segment{
	int ls,rs,siz;
}t[N<<5]; int cnt;
int update(int rt,int l,int r,int pos,int d){
	int u = ++cnt;
	t[u] = t[rt];
	t[u].siz += d;
	if(l == r) return u;
	int mid = (l+r) >> 1;
	if(pos <= mid) t[u].ls = update(t[u].ls,l,mid,pos,d);
	else t[u].rs = update(t[u].rs,mid+1,r,pos,d);
	return u;
}
int ask(int rt,int l,int r,int ql,int qr){
	if(ql > qr) return 0;
	if(ql <= l && r <= qr) return t[rt].siz;
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res += ask(t[rt].ls,l,mid,ql,qr);
	if(qr >  mid) res += ask(t[rt].rs,mid+1,r,ql,qr);
	return res;
}
int query(int rt,int l,int r,int k){
	if(l == r) return l;
	int mid = (l+r) >> 1;
	if(t[t[rt].ls].siz < k) return query(t[rt].rs,mid+1,r,k-t[t[rt].ls].siz);
	return query(t[rt].ls,l,mid,k);
}
int ans[N];
int main(){
	n = read(); Q = read();
	for(int i=1;i<=n;i++) a[i] = read(),m = max(m,a[i]);
	for(int i=1;i<=n;i++) v[a[i]].push_back(i);
	for(int i=1;i<=Q;i++){
		int x = read(),k = read();
		m = max(m,k);
		q[k].push_back(mk(x,i));
	}
	for(int i=1;i<=m;i++) sort(q[i].begin(),q[i].end());
	++n;
	root[m+1] = update(0,1,n,n,1000000000);
	for(int i=m;i;i--){
		root[i] = root[i+1];
		for(int x : v[i]) root[i] = update(root[i],1,n,x,1);
	}
	for(int k=1;k<=m;k++){
		int i = 0,x = 0,j = 0;
		while(j < q[k].size()){
			while(i < q[k][j].fi){
				x++;
				i = query(root[x],1,n,k+ask(root[x],1,n,1,i));
			}
			// cout << x << " " << i << "\n";
			ans[q[k][j].se] = a[q[k][j].fi] >= x;
			j++;
		}
	}
	for(int i=1;i<=Q;i++)
		puts(ans[i] ? "YES" : "NO");
	return 0;
}
/*
10 1
3 1 4 4 3 1 1 4 4 4
9 1
*/