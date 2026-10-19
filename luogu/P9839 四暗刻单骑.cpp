#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') ch = getchar(),r = -1;
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10,inf = 1e9;
int n,m,k,flag,a[N],ans[2][N];
vector<int> pos[N],v[N];
struct Ques{int x,y,l,r,id;}; vector<Ques>q[N];
int find(int x,int l,int r){
	vector<int>::iterator it = upper_bound(pos[x].begin(),pos[x].end(),l);
	if(it == pos[x].end() || *it > r) return -1; return *it;
}
int getwin(int x,int l,int r,int fg=0){
	int nxt = find(x,l+fg,r);
	if(nxt == -1) return inf;
	if((nxt & 1) == (l & 1)) return nxt;
	int nnxt = find(x,nxt,r);
	if(nnxt == -1) return flag == (l&1) ? nxt : inf;
	if((nnxt & 1) == (l & 1)) return nxt;
	return inf;
}
struct Segment{int minn,pos;}c[N<<2];
#define ls rt<<1
#define rs rt<<1|1
Segment merge(Segment x,Segment y){	return x.minn > y.minn ? y : x;}
void build(int rt,int l,int r){
	if(l == r){c[rt] = Segment{inf,l};return ;}
	int mid = (l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	c[rt] = merge(c[ls],c[rs]);
}
void update(int rt,int l,int r,int p,int d){
	if(l == r){c[rt] = Segment{d,l}; return ;}
	int mid = (l+r)>>1;
	if(p <= mid) update(ls,l,mid,p,d);
	else 		 update(rs,mid+1,r,p,d);
	c[rt] = merge(c[ls],c[rs]);
}
Segment query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return c[rt];
	int mid = (l+r)>>1;
	if(qr <= mid) return query(ls,l,mid,ql,qr);
	if(ql >  mid) return query(rs,mid+1,r,ql,qr);
	return merge(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
int calc(int x,int y,int l,int r){
	if(x == y){
		int nxt = find(x,l-1,r);
		if(nxt == -1) return flag ? 1 : -1;
		else if((nxt & 1) == (l & 1)) return 1;
		else return -1; 
	}
	if(a[l] == y){
		int nxt = find(y,l,r);
		if((nxt & 1) == (l & 1) && nxt != -1) return 1;
		else if(nxt == -1) return flag ? 1 : -1;
	}
	int wx = getwin(x,l-2,r,1),wy = getwin(y,l-1,r);
	int ans = min(wx,wy),p = wx > wy ? l-1 : l-2;
	Segment qu = query(1,1,n,l,r);
	if(qu.minn < ans) ans = qu.minn,p = qu.pos;
	if(ans == inf) return flag ? 1 : -1;
	return ((l & 1) == (p & 1)) ? 1 : -1;
}
void solve(){
	build(1,1,n);
	for(int r=1;r<=n;r++){
		for(int x:v[r]) update(1,1,n,x,getwin(a[x],x,r));
		for(Ques x:q[r]) ans[flag][x.id] = calc(x.x,x.y,x.l,x.r);
	}
}
int main(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read(),pos[a[i]].push_back(i);
	for(int i=1;i<=m;i++){
		int x = read(), y = read(), l = read(), r = read();
		q[r].push_back(Ques{x,y,l,r,i});
	}
	for(int i=1;i<=n;i++){
		int nxt = find(a[i],i,n);
		if(nxt == -1) continue;
		v[nxt].push_back(i);
		int nnxt = find(a[i],nxt,n);
		if(nnxt != -1) v[nnxt].push_back(i);
	}
	flag = 0; solve(); flag = 1; solve();
	for(int i=1;i<=m;i++) 
		if(ans[1][i] == -1) puts("B");
		else if(ans[0][i] == 1) puts("A");
		else puts("D");
	return 0;
}