#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 5e5+10;
int n,m = 5e5,a[N],lst[N],nxt[N];
int mx[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	mx[rt] = max(mx[ls],mx[rs]);
}
void update(int rt,int l,int r,int pos,int d){
	if(l == r) return mx[rt] = max(d,mx[rt]),void();
	int mid = (l+r) >> 1;
	if(pos <= mid) update(ls,l,mid,pos,d);
	else 		   update(rs,mid+1,r,pos,d);
	push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql > qr) return 0;
	if(ql <= l && r <= qr) return mx[rt];
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
	return res;
}
int f[N];
int main(){
	// freopen("pairing.in","r",stdin);
	// freopen("pairing.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=n;i;i--){
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]) f[nxt[i]] = max(query(1,1,m,1,a[i]-1),query(1,1,m,a[i]+1,m))+2;
		update(1,1,m,a[i],f[i]);
	}
	cout << mx[1];
    return 0;
}
