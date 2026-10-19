#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
const int inf = 1e9;
int n,a[N],val[N],cnt[N];
struct Segment{
	int mx[N<<2];
	#define ls rt<<1
	#define rs rt<<1|1
	inline void push_up(int rt){
		mx[rt] = max(mx[ls],mx[rs]);
	}
	void build(int rt,int l,int r,int v){
		mx[rt] = v;
		if(l == r) return ;
		int mid = (l+r)>>1;
		build(ls,l,mid,v);
		build(rs,mid+1,r,v);
	}
	void update(int rt,int l,int r,int pos,int v){
		if(l == r){
			mx[rt] = v;
			return ;
		}
		int mid = (l+r)>>1;
		if(pos <= mid) update(ls,l,mid,pos,v);
		else update(rs,mid+1,r,pos,v);
		push_up(rt);
	}
	int query(int rt,int l,int r,int ql,int qr){
		if(ql <= l && r <= qr) return mx[rt];
		int mid = (l+r)>>1,res = -inf;
		if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
		if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
		return res;
	}
}odd,even;
bool chk(int x,int mx){
	if(mx < 0) return false;
	if(mx & 1) return  odd.query(1,1,n,x,n) >= mx;
	else 	   return even.query(1,1,n,x,n) >= mx;
}
int ans[N];
int main(){
    n = read();
	for(int i=1,mx=0;i<=n;i++){
		a[i] = read();
		if(a[i] > mx) mx = a[i],val[i] = 2;
		else val[i] = 1;
	}
	odd.build(1,1,n,-inf-1);
	even.build(1,1,n,0);
	for(int i=n;i;i--){
		int vodd = odd.query(1,1,n,a[i],n),
			veven = even.query(1,1,n,a[i],n);
		// cout << vodd << " " << veven << "\n";
		if(val[i] & 1){
			odd.update(1,1,n,a[i],veven+val[i]);
			even.update(1,1,n,a[i],vodd+val[i]);
		}else{
			odd.update(1,1,n,a[i],vodd+val[i]);
			even.update(1,1,n,a[i],veven+val[i]);
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout << odd.query(1,1,n,a[i],a[i]) << " ";
	// 	cout << even.query(1,1,n,a[i],a[i]) << " ";
	// 	cout << "\n";
	// }
	for(int i=n;i;i--) cnt[i] = cnt[i+1]+(val[i] == 2);
	int mxA = 0,mxB = 0,va = 0,vb = 0;
	for(int i=1;i<=n;i++){
		odd.update(1,1,n,a[i],-inf);
		even.update(1,1,n,a[i],0);
		if(chk(mxB,va-vb+cnt[i+1]+(a[i]>mxA)) || chk(mxA,vb-va+cnt[i+1]-(a[i]>mxA))){
			ans[i] = 0;
			va += a[i] > mxA;
			mxA = max(mxA,a[i]);
		}else{
			ans[i] = 1;
			vb += a[i] > mxB;
			mxB = max(mxB,a[i]);
		}
	}
	if(va != vb) cout << "-1";
	else for(int i=1;i<=n;i++) cout << ans[i];
    return 0;  
}