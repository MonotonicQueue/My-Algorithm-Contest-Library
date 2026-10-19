#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 510;
const int M = 6e4+10;
int n,m;
struct node{
	int x,y,c;
}a[N*N];
int ans[M];
struct Ques{int xl,xr,yl,yr,k,id;};
int t[N][N];
void add(int x,int y,int z){
	for(int i=x;i<=n;i+=i&(-i))
		for(int j=y;j<=n;j+=j&(-j)) t[i][j] += z;
}
int ask(int x,int y){
	int res = 0;
	for(int i=x;i;i-=i&(-i))
		for(int j=y;j;j-=j&(-j)) res += t[i][j];
	return res;
}
int query(int xl,int yl,int xr,int yr){
	return ask(xr,yr)-ask(xl-1,yr)-ask(xr,yl-1)+ask(xl-1,yl-1);
}
void solve(int l,int r,vector<Ques> &q){
	if(q.empty()) return ;
	if(l == r){
		for(auto &it : q) ans[it.id] = a[l].c;
		return ;
	}
	int mid = (l+r) >> 1;
	for(int i=l;i<=mid;i++) add(a[i].x,a[i].y,1);
	vector<Ques> ql,qr;
	for(auto &it : q){
		int sum = query(it.xl,it.yl,it.xr,it.yr);
		if(sum < it.k){
			it.k -= sum;
			qr.push_back(it);
		}else ql.push_back(it);
	}
	for(int i=l;i<=mid;i++) add(a[i].x,a[i].y,-1);
	solve(l,mid,ql); solve(mid+1,r,qr);
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int c = read();
			a[(i-1)*n+j] = node{i,j,c};
		}
	sort(a+1,a+1+n*n,[](node x,node y){return x.c < y.c;});
	vector<Ques> q;
	for(int i=1;i<=m;i++){
		int xl = read(),yl = read(),xr = read(),yr = read(),k = read();
		q.push_back(Ques{xl,xr,yl,yr,k,i});
	}
	solve(1,n*n,q);
	for(int i=1;i<=m;i++) cout << ans[i] << "\n";
    return 0;
}