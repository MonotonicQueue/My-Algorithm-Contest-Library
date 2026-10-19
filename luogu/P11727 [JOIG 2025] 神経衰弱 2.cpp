#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 8e5+10;
const ll inf = 1e18;
int n,a[N],V[N];
struct Segment{
	ll t[N<<2];
	#define ls rt<<1
	#define rs rt<<1|1
	inline void push_up(int rt){
		t[rt] = max(t[ls],t[rs]);
	}
	void update(int rt,int l,int r,int pos,ll d){
		if(l == r) return t[rt] = d,void();
		int mid = (l+r) >> 1;
		if(pos <= mid) update(ls,l,mid,pos,d);
		else 		   update(rs,mid+1,r,pos,d);
		push_up(rt);
	}
	ll query(int rt,int l,int r,int ql,int qr){
		if(ql > qr) return -1e18;
		if(ql <= l && r <= qr) return t[rt];
		int mid = (l+r) >> 1; ll res = 0;
		if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
		if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
		return res;
	}
}T[2];
ll f[N][2];
int lst[N];
int main(){
	n = read();
	for(int i=1;i<=2*n;i++) a[i] = read();
	for(int i=1;i<=n;i++) V[i] = read();
	n *= 2;
	for(int i=1;i<=n;i++){
		if(!lst[a[i]]){
			lst[a[i]] = i;
			f[i][0] = f[i][1] = -inf;
		}else{
			int l = lst[a[i]];
			f[i][0] = max(T[0].query(1,1,n,1,l)+V[a[i]],T[1].query(1,1,n,1,l)+V[a[i]]);
			f[i][1] = T[0].query(1,1,n,1,l)+V[a[i]];
			T[0].update(1,1,n,i,f[i][0]);
			T[1].update(1,1,n,lst[a[i]],f[i][1]);
		}
	}
	cout << T[0].t[1];
    return 0;
}