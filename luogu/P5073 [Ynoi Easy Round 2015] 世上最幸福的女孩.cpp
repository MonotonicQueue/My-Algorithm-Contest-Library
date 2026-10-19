#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
namespace fastio{
    char ibuf[1 << 20],*p1 = ibuf, *p2 = ibuf;
    #define get() p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = get();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = get();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = get();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args&... args){
        read(t);
        read(args...);
    }
    template<typename T> void write(T t){
        if(t < 0) putchar('-'), t = -t;
        if(t >= 10) write(t / 10);
        putchar(t % 10 + '0');
    }
    template<typename T, typename ... Args> void write(T t, Args... args){
        write(t), putchar(' '), write(args...);
    }
    template<typename T> void writeln(T t){
        write(t);
        puts("");
    }
    template<typename T> void writes(T t){
        write(t), putchar(' ');
    }
    #undef get
};
using namespace fastio;
const int N = 3e5+10;
const int M = 6e5+10;
const ll inf = 2e18;
int n,Q,a[N];
ll lst;
struct Line{
	int k; ll b;
	Line(ll k=0,ll b=0): k(k),b(b){}
	Line operator+(const Line &o)const{
		return Line(k+o.k,b+o.b);
	}
};
ll tag[N<<2];
inline pair<Line,ll> max(Line a,Line b){
	//求出两条直线 a,b 在 x = 0 处的 max 以及这个 max 会改变的最小 x
	(a.k < b.k || (a.k == b.k && a.b < b.b)) ? swap(a,b) : void();
	return a.b >= b.b ? mk(a,inf) : mk(b,(b.b-a.b)/(a.k-b.k));
}
inline void chkmn(ll &x,ll y){
	x = x < y ? x : y;
}
struct node{
	Line sum,lmx,rmx,mx;
	ll x;
	node operator+(const node &o)const{
		node res;
		res.x = x < o.x ? x : o.x;
		auto tmp = max(lmx,o.lmx+sum);
		res.lmx = tmp.fi; chkmn(res.x,tmp.se);
		tmp = max(o.rmx,rmx+o.sum);
		res.rmx = tmp.fi; chkmn(res.x,tmp.se);
		res.sum = sum+o.sum;

		tmp = max(mx,o.mx); chkmn(res.x,tmp.se);
		tmp = max(tmp.fi,rmx+o.lmx);
		chkmn(res.x,tmp.se);
		res.mx = tmp.fi;
		return res;
	}
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
	if(l == r){
		t[rt].sum = t[rt].lmx = t[rt].rmx = t[rt].mx = Line(1,a[l]+lst);
		t[rt].x = inf;
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt] = t[ls]+t[rs];
}
inline void change(int rt,ll d){
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
node query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return t[rt];
	push_down(rt);
	int mid = (l+r) >> 1;
	if(qr <= mid) return query(ls,l,mid,ql,qr);
	if(ql >  mid) return query(rs,mid+1,r,ql,qr);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
ll ans[M];
bool flag[M];
vector<tuple<int,int,int>> q[M];
int main(){
	read(n,Q);
	for(int i=1;i<=n;i++) read(a[i]);
	lst = 0; ll now = 0;
	vector<pair<ll,int>> v;
	v.push_back(mk(0,0));
	for(int i=1,op,x,l,r;i<=Q;i++){
		read(op);
		if(op == 1){
			read(x);
			lst = i;
			now += x;
			v.emplace_back(now,i);
		}else{
			flag[i] = true;
			read(l,r);
			q[lst].emplace_back(l,r,i);
		}
	}
	sort(v.begin(),v.end());
	lst = v[0].fi;
	build(1,1,n);
	for(auto &[x,id] : v){
		if(q[id].size() == 0) continue;
		upd(1,1,n,x-lst);
		lst = x;
		for(auto &[l,r,i] : q[id])
			ans[i] = query(1,1,n,l,r).mx.b;
	}
	for(int i=1;i<=Q;i++)
		if(flag[i]) writeln(max(ans[i],0ll));
	return 0;
}