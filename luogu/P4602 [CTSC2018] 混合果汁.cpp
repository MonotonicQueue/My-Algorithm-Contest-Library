#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m,k = 1e5;
struct node{ll d,p,l;}a[N];
struct Ques{ll g,L; int id;};
int cnt,root[N];
struct Segment{
	int lc,rc;
	ll sum,val;
}t[N*20];
#define ls t[rt].lc
#define rs t[rt].rc
int insert(int u,int l,int r,int pos,ll lim){
	int rt = ++cnt;
	t[rt] = t[u]; t[rt].sum += lim; t[rt].val += pos*lim;
	if(l == r) return rt;
	int mid = (l+r) >> 1;
	if(pos <= mid) t[rt].lc = insert(t[rt].lc,l,mid,pos,lim);
	else 		   t[rt].rc = insert(t[rt].rc,mid+1,r,pos,lim);
	return rt; 
}
ll query(int rt,int l,int r,ll lim){
	if(l == r) return lim*l;
	int mid = (l+r) >> 1;
	if(lim <= t[ls].sum) return query(ls,l,mid,lim);
	return t[ls].val+query(rs,mid+1,r,lim-t[ls].sum); 
}
int ans[N];
void solve(int l,int r,vector<Ques> &q){
	if(q.empty()) return ;
	if(l == r){
		for(auto it : q) ans[it.id] = a[l].d;
		return ;
	}
	int mid = (l+r) >> 1;
	vector<Ques> ql,qr;
	for(auto it : q){
		ll val = query(root[mid+1],1,k,it.L);
		if(val <= it.g && t[root[mid+1]].sum >= it.L) qr.push_back(it);
		else ql.push_back(it);
	}
	solve(l,mid,ql); solve(mid+1,r,qr);
}
int main(){
	n = read(); m = read();
	vector<node> v;
	for(int i=1;i<=n;i++){
		ll d = read(),p = read(),l = read();
		a[i] = node{d,p,l};
	}
	sort(a+1,a+1+n,[](node x,node y){return x.d < y.d;});
	for(int i=n;i;i--)
		root[i] = insert(root[i+1],1,k,a[i].p,a[i].l);
	root[0] = root[1]; a[0].d = -1;
	vector<Ques> q;
	for(int i=1;i<=m;i++){
		ll g = read(),L = read();
		if(L > t[root[0]].sum) ans[i] = -1;
		else q.push_back(Ques{g,L,i});
	}
	solve(0,n,q);
	for(int i=1;i<=m;i++) cout << ans[i] << "\n";
    return 0;
}

