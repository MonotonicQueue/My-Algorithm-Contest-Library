#include<bits/stdc++.h>
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
const int N = 3e5+10;
int n,q,c1,c2;
ll w1,w2,a[N],b[N],sum[N];
ll mx[N<<2],tag[N<<2],t[N<<2],maxn[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	mx[rt] = max(mx[ls],mx[rs]);
	t[rt] = t[ls]+t[rs];
	maxn[rt] = max(maxn[ls],maxn[rs]);
}
void build(int rt,int l,int r){
	if(l == r){
		mx[rt] = b[l];
		maxn[rt] = t[rt] = a[l];
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
inline void change(int rt,ll d){
	mx[rt] += d; 
	tag[rt] += d;
}
inline void push_down(int rt){
	if(tag[rt]){
		change(ls,tag[rt]);
		change(rs,tag[rt]);
		tag[rt] = 0;
	}
}
void update1(int rt,int l,int r,int ql,int qr,ll d){
	if(ql <= l && r <= qr) return change(rt,d);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update1(ls,l,mid,ql,qr,d);
	if(qr >  mid) update1(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
void update2(int rt,int l,int r,int pos,ll d){
	if(l == r) return maxn[rt] += d,t[rt] += d,void();
	push_down(rt);
	int mid = (l+r) >> 1;
	if(pos <= mid) update2(ls,l,mid,pos,d);
	else 		   update2(rs,mid+1,r,pos,d);
	push_up(rt);
}
int querymn(int rt,int l,int r,int ql,int qr){
	if(l == r) return l;
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= l && r <= qr){
		if(mx[ls] > w2) return querymn(ls,l,mid,ql,qr);
		return querymn(rs,mid+1,r,ql,qr);
	}
	int res = n+1;
	if(ql <= mid && mx[ls] > w2) res = querymn(ls,l,mid,ql,qr);
	if(qr > mid && mx[rs] > w2 && res == n+1) res = querymn(rs,mid+1,r,ql,qr);
	return res;
}
int querymx(int rt,int l,int r,int ql,int qr){
	if(l == r) return l;
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= l && r <= qr){
		if(mx[rs] > w2) return querymx(rs,mid+1,r,ql,qr);
		return querymx(ls,l,mid,ql,qr);
	}
	int res = n+1;
	if(qr > mid && mx[rs] > w2) res = querymx(rs,mid+1,r,ql,qr);
	if(ql <= mid && mx[ls] > w2 && res == n+1) res = querymx(ls,l,mid,ql,qr);
	return res;
}
ll qrymx(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return maxn[rt];
	push_down(rt);
	int mid = (l+r) >> 1; ll res = 0;
	if(ql <= mid) res = max(res,qrymx(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,qrymx(rs,mid+1,r,ql,qr));
	return res;
}
ll qrysum(int rt,int l,int r,int ql,int qr){
	if(ql > qr) return 0;
	if(ql <= l && r <= qr) return t[rt];
	push_down(rt);
	int mid = (l+r) >> 1; ll res = 0;
	if(ql <= mid) res += qrysum(ls,l,mid,ql,qr);
	if(qr >  mid) res += qrysum(rs,mid+1,r,ql,qr);
	return res;
}
bool solve(int L,int R){
	if(qrymx(1,1,n,L,R) > w1) return false;
	int pl = querymn(1,1,n,L,R);
	if(pl != n+1 && pl+c2-1 > R){
		if(qrysum(1,1,n,pl,R) <= w2) pl = n+1;
	}
	int pr = n+1;
	if(L+c2-1 <= R){
		pr = querymx(1,1,n,L,R-c2+1);
		if(pr != n+1) pr = pr+c2-1;
	}else if(qrysum(1,1,n,L,R) > w2) pr = R;
	if(pl == n+1 && pr == n+1) return true;
	if(pr-pl >= c1) return false;
	if(qrysum(1,1,n,pl,pr) > w1) return false;
	return true;
}
int main(){
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	n = read(); q = read();
	c1 = read(); c2 = read(); w1 = read(); w2 = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum[i] = sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		b[i] = sum[min(n,i+c2-1)]-sum[i-1];
	build(1,1,n);
	while(q--){
		int op = read(),x = read(),y = read();
		if(op == 1){
			update1(1,1,n,max(1,x-c2+1),x,y);
			update2(1,1,n,x,y);
		}else{
			puts(solve(x,y) ? "cont" : "tetris");
		}
	}
	return 0;
}
