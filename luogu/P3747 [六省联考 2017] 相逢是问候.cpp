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
const int N = 5e4+10;
int n,m,p,c;
int a[N],phi[N],tot;
int getphi(int x){
	int res = x;
	for(int i=2;i*i<=x;i++)
		if(x % i == 0){
			res = res/i*(i-1);
			while(x % i == 0) x /= i;
		}
	if(x > 1) res = res/x*(x-1);
	return res;
}
ll pw1[10100][100],pw2[10100][100];
bool vis1[10100][100],vis2[10100][100];
inline void init(){
	phi[0] = p;
	while(phi[tot] != 1) phi[tot+1] = getphi(phi[tot]),tot++;
	phi[++tot] = 1;
	for(int i=0;i<=tot;i++){
		pw1[0][i] = 1;
		for(int j=1;j<=10000;j++){
			pw1[j][i] = pw1[j-1][i]*c;
			if(pw1[j][i] >= phi[i]) pw1[j][i] %= phi[i],vis1[j][i] = true;
			vis1[j][i] |= vis1[j-1][i]; 
		}
	}
	for(int i=0;i<=tot;i++){
		pw2[0][i] = 1;
		vis2[1][i] = vis1[10000][i];
		for(int j=1;j<=10000;j++){
			pw2[j][i] = pw2[j-1][i]*pw1[10000][i];
			if(pw2[j][i] >= phi[i]) pw2[j][i] %= phi[i],vis2[j][i] = true;
			vis2[j][i] |= vis2[j-1][i]; 
		}
	}
}
bool flag;
ll calc(ll x,int id){
	flag = false;
	int x1 = x/10000,x2 = x%10000;
	ll val = pw1[x2][id]*pw2[x1][id];
	if(val >= phi[id]) val %= phi[id],flag = true;
	flag |= vis1[x2][id]|vis2[x1][id];
	return val;
}
ll solve(ll x,int dep,int s){
	flag = false;
	if(dep == s){
		if(x >= phi[dep]) x %= phi[dep],flag = true;
		return x;
	}
	ll k = solve(x,dep+1,s);
	return calc(flag ? k+phi[dep+1] : k,dep);
}
ll sum[N<<2]; int cnt[N<<2],num[N];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	sum[rt] = (sum[ls]+sum[rs])%p;
	cnt[rt] = cnt[ls]+cnt[rs]; 
}
void build(int rt,int l,int r){
	if(l == r){
		sum[rt] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt); 
}
void update(int rt,int l,int r,int ql,int qr){
	if(cnt[rt] == r-l+1) return ;
	if(l == r){
		sum[rt] = solve(a[l],0,++num[l]);
		if(num[l] == tot) cnt[rt] = 1;
		return ;
	}
	int mid = (l+r)>>1;
	if(ql <= mid) update(ls,l,mid,ql,qr);
	if(qr >  mid) update(rs,mid+1,r,ql,qr);
	push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return sum[rt];
	int mid = (l+r) >> 1;
	ll res = 0;
	if(ql <= mid) res = (res+query(ls,l,mid,ql,qr))%p;
	if(qr >  mid) res = (res+query(rs,mid+1,r,ql,qr))%p;
	return res;
}

int main(){
    n = read(); m = read(); p = read(); c = read();
	for(int i=1;i<=n;i++) a[i] = read();
	init();
	build(1,1,n);
	while(m--){
		int op = read(),l = read(),r = read();
		if(op == 0) update(1,1,n,l,r);
		else		cout << query(1,1,n,l,r) << "\n";
	}
	return 0;
}