#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int N = 1e5+10;
const int M = 1.6e5+10;
const int mod = 39989;
int n,cnt;
struct line{
	double k,b;
}p[N];
double calc(int id,int x){
	return p[id].k*x+p[id].b;
}
void add(int x,int y,int xx,int yy){
	cnt++;
	if(x == xx) p[cnt].k = 0,p[cnt].b = max(y,yy);
	else p[cnt].k = (yy-y)*1.0/(xx-x),p[cnt].b = y-p[cnt].k*x;
}
int t[M];
#define ls rt<<1
#define rs rt<<1|1
const double eps = 1e-9;
int cmp(double x,double y){
	if(x-y > eps) return 1;
	if(y-x > eps) return -1;
	return 0;
}
void upd(int rt,int l,int r,int u){
	int &v = t[rt],mid = (l+r)>>1;
	int bmid = cmp(calc(u,mid),calc(v,mid));
	if(bmid == 1 || (bmid == 0 && u < v)) swap(u,v);
	int bl = cmp(calc(u,l),calc(v,l)),br = cmp(calc(u,r),calc(v,r));
	if(bl == 1 || (bl == 0 && u < v)) upd(ls,l,mid,u);
	if(br == 1 || (br == 0 && u < v)) upd(rs,mid+1,r,u);
}
void update(int ql,int qr,int id,int rt=1,int l=1,int r=mod){
	if(ql <= l && r <= qr){
		upd(rt,l,r,id);
	}else{
		int mid = (l+r)>>1;
		if(ql <= mid) update(ql,qr,id,ls,l,mid);
		if(qr >  mid) update(ql,qr,id,rs,mid+1,r);
	}
}
typedef pair<double,int> pdi;
pdi pmax(pdi x,pdi y){
	if(cmp(x.fi,y.fi) == 1 || (cmp(x.fi,y.fi) == 0 && x.se < y.se)) return x;
	return y;
}
pdi query(int pos,int rt=1,int l=1,int r=mod){
	if(pos < l || pos > r) return mk(0,0);
	int mid = (l+r)>>1;
	if(l == r) return mk(calc(t[rt],pos),t[rt]);
	return pmax(mk(calc(t[rt],pos),t[rt]),pmax(query(pos,ls,l,mid),query(pos,rs,mid+1,r)));
}
int lstans;
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		int op = read();
		if(op == 0){
			int x = read();
			x = (x+lstans-1)%mod+1;
			cout << (lstans = query(x).se) << "\n";
		}else{
			int x = read(),y = read(),
			   xx = read(),yy = read();
			x = (x+lstans-1)%mod+1;
			y = (y+lstans-1)%1000000000+1;
			xx = (xx+lstans-1)%mod+1;
			yy = (yy+lstans-1)%1000000000+1;
			if(x > xx) swap(x,xx),swap(y,yy);
			add(x,y,xx,yy);
			update(x,xx,cnt);
		}
	}
	return 0;
}
