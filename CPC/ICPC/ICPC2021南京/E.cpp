#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 5e4+10;
const int mod = 1e9+7;
int n,m,Q;
ll a[N],ans[N];
struct node{
	int l,r,x,id;
}b[N];
vector<node> q[N];
struct Matrix{
	ll mat[4][4];
	Matrix(){
		memset(mat,0,sizeof(mat));
	}
	ll* operator[](const int x){
		return mat[x];
	}
	Matrix operator*(const Matrix &o)const{
		Matrix res;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					res[i][j] = (res[i][j]+mat[i][k]*o.mat[k][j])%mod;
		return res;
	}
	Matrix operator+(const Matrix &o)const{
		Matrix res;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				res[i][j] = (mat[i][j]+o.mat[i][j])%mod;
		return res;
	}
	void initI(){
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) mat[i][j] = i == j;
	}
	bool chkI(){
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) if(mat[i][j] != (i == j)) return false;
		return true;
	}
	void init(ll d){
		mat[0][0] = mat[1][0] = mat[1][1] = mat[2][2] = mat[3][3] = 1;
		mat[2][0] = mat[2][1] = 2*d;
		mat[3][0] = mat[3][1] = d*d%mod; mat[3][2] = d;
	}
};
Matrix t[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
	t[rt] = t[ls]+t[rs];
}
void build(int rt,int l,int r){
	tag[rt].initI();
	if(l == r){
		ll d = a[l];
		t[rt][0][0] = t[rt][0][1] = d*d%mod;
		t[rt][0][2] = d; t[rt][0][3] = 1;
		return ;
	}
	int mid = (l+r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(rt);
}
void change(int rt,Matrix d){
	t[rt] = t[rt]*d;
	tag[rt] = tag[rt]*d;
}
void push_down(int rt){
	if(!tag[rt].chkI()){
		change(ls,tag[rt]);
		change(rs,tag[rt]);
		tag[rt].initI();
	}
}
void update(int rt,int l,int r,int ql,int qr,Matrix d){
	if(ql <= l && r <= qr) return change(rt,d);
	push_down(rt);
	int mid = (l+r) >> 1;
	if(ql <= mid) update(ls,l,mid,ql,qr,d);
	if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
	push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return t[rt][0][0];
	push_down(rt);
	int mid = (l+r) >> 1; ll res = 0;
	if(ql <= mid) res = (res+query(ls,l,mid,ql,qr))%mod;
	if(qr >  mid) res = (res+query(rs,mid+1,r,ql,qr))%mod;
	return res;
}
int main(){
	n = read(); m = read(); Q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++){
		int l = read(),r = read(),x = read();
		b[i] = node{l,r,x,0};
	}
	for(int i=1;i<=Q;i++){
		int l = read(),r = read(),L = read(),R = read();
		if(L) q[L-1].push_back(node{l,r,-1,i});
		q[R].push_back(node{l,r,1,i});
	}
	for(int i=0;i<=m;i++){
		if(i == 0) build(1,1,n);
		else{
			Matrix M; M.init(b[i].x);
			update(1,1,n,b[i].l,b[i].r,M);
			M.initI();
			M[1][0] = 1;
			if(b[i].l != 1) update(1,1,n,1,b[i].l-1,M);
			if(b[i].r != n) update(1,1,n,b[i].r+1,n,M);
		}	
		for(auto it : q[i]){
			ans[it.id] += it.x*query(1,1,n,it.l,it.r);
		}
	}
	for(int i=1;i<=Q;i++) cout << (ans[i]%mod+mod)%mod << "\n";
    return 0;
}
/*
3 1 1
8 1 6
2 3 2
1 1 1 1
*/
