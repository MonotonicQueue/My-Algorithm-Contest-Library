#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e5+5; 
int n;
struct Point{
	ll x,y;
}p[N];
bool cmp1(Point x,Point y){
	return x.x < y.x;
}
bool cmp2(Point x,Point y){
	return x.y < y.y;
}
int cnt;
struct Edge1{
	ll x,h1,h2;
	vector<ll> y,flag;
}a[N];
ll raw[N],tot;
map<ll,int>vx,val;
struct Segment{
	int l,r;
	ll cnt,len;
	#define ls rt<<1
	#define rs rt<<1|1
}c[N<<2];
inline void push_up(int rt){
	if(c[rt].cnt) c[rt].len = c[rt].r-c[rt].l+1;
	else{
		if(c[rt].l != c[rt].r) c[rt].len = c[ls].len+c[rs].len;
		else c[rt].len = 0;
	}
}
void build(int rt,int l,int r){
	c[rt].l = l; c[rt].r = r;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void update(int rt,int pos,int d){
	if(c[rt].l == c[rt].r){
		c[rt].cnt += d;
		push_up(rt);
		return;
	}
	int mid = (c[rt].l+c[rt].r)>>1;
	if(pos <= mid) update(ls,pos,d);
	else update(rs,pos,d);
	push_up(rt); 
}
ll query(int rt,int l,int r){
	if(l <= c[rt].l && c[rt].r <= r) return c[rt].len;
	int mid = (c[rt].l+c[rt].r)>>1; ll ans = 0;
	if(l <= mid) ans += query(ls,l,r);
	if(r >  mid) ans += query(rs,l,r);
	return ans;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		p[i].x = read();
		p[i].y = read();
	}
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(p[i].x == p[i-1].x){
			a[cnt].h1 = min(a[cnt].h1,p[i].y);
			a[cnt].h2 = max(a[cnt].h2,p[i].y);
		}else{
			a[++cnt].x = p[i].x;
			vx[p[i].x] = cnt;
			a[cnt].h1 = a[cnt].h2 = p[i].y;
		}
	}
	sort(p+1,p+1+n,cmp2);
	ll x1=1e9,x2=0;
	for(int i=1;i<=n;i++){
		if(p[i].y == p[i-1].y){
			x1 = min(x1,p[i].x);
			x2 = max(x2,p[i].x);
		}else{
			if(i != 1){
				a[vx[x1]].y.push_back(p[i-1].y);
				a[vx[x2]].y.push_back(p[i-1].y);
				a[vx[x1]].flag.push_back(1);
				a[vx[x2]].flag.push_back(-1);
			}
			x1=p[i].x; x2=p[i].x;
			raw[++tot] = p[i].y;
			val[p[i].y] = tot;
		}
	}
	a[vx[x1]].y.push_back(p[n].y);
	a[vx[x2]].y.push_back(p[n].y);
	a[vx[x1]].flag.push_back(1);
	a[vx[x2]].flag.push_back(-1);
	build(1,1,tot);
	ll ans = 0;
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<a[i].y.size();j++)
			if(a[i].flag[j] == 1)
				 update(1,val[a[i].y[j]],a[i].flag[j]);
		ans += query(1,val[a[i].h1],val[a[i].h2]);
		for(int j=0;j<a[i].y.size();j++)
			if(a[i].flag[j] == -1)
				 update(1,val[a[i].y[j]],a[i].flag[j]);
	}
	cout << ans;
	return 0;
}