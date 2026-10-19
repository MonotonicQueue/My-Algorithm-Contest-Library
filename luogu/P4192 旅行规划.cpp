#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
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
const int N = 101000;
const int B = 400;
int n,Q;
ll a[N],k[N],b[N];
int pos[N],L[N],R[N],m;
vector<int> v[N];
int stk[N],top;
void build(int id){
	v[id].clear();
	for(int i=L[id];i<=R[id];i++)
		a[i] += k[id]*i+b[id];
	k[id] = b[id] = 0;
	top = 0;
	for(int i=L[id];i<=R[id];i++){
		while(top >= 2 && (a[stk[top]]-a[stk[top-1]])*(i-stk[top])
		 	<= (a[i]-a[stk[top]])*(stk[top]-stk[top-1])) top--;
		stk[++top] = i;
	}
	for(int i=1;i<=top;i++) v[id].push_back(stk[i]);
}
void init(){
	for(int i=1;i<=n;i++)
		pos[i] = (i-1)/B+1;
	m = (n-1)/B+1;
	for(int i=1;i<=m;i++){
		L[i] = (i-1)*B+1;
		R[i] = i*B;
	}
	R[m] = n;
	for(int i=1;i<=n;i++) a[i] += a[i-1];
	for(int i=1;i<=m;i++) build(i);
}
ll qry(int id){
	ll res = -1e18;
	int l = 0,r = v[id].size()-2;
	if(v[id].size() <= 2){
		for(int x : v[id]) res = max(res,a[x]+b[id]+k[id]*x);
		return res;
	}
	while(l <= r){
		int mid = (l+r) >> 1;
		if((a[v[id][mid+1]]-a[v[id][mid]])*1.0/(v[id][mid+1]-v[id][mid]) >= -k[id]) l = mid+1;
		else r = mid-1;
	}
	for(int i=max(0,l-5);i<min(r+5,int(v[id].size()));i++){
		int x = v[id][i];
		res = max(res,a[x]+b[id]+k[id]*x);
	}
	return res;
}
ll query(int l,int r){
	int bl = pos[l],br = pos[r];
	ll ans = -1e18;
	if(bl == br){
		for(int i=l;i<=r;i++) ans = max(ans,a[i]+b[bl]+k[bl]*i);
		return ans;
	}
	for(int i=l;i<=R[bl];i++) ans = max(ans,a[i]+b[bl]+k[bl]*i);
	for(int i=L[br];i<=r;i++) ans = max(ans,a[i]+b[br]+k[br]*i);
	for(int i=bl+1;i<=br-1;i++)
		ans = max(ans,qry(i));
	return ans;
}
void update(int l,int r,ll d){
	int bl = pos[l],br = pos[r];
	ll t = (r-l+1)*d;
	for(int i=br+1;i<=m;i++) b[i] += t;
	for(int i=r+1;i<=R[br];i++) a[i] += t;
	if(bl == br){
		for(int i=l;i<=r;i++) a[i] += d*(i-l+1);
		build(bl);
		return ;
	}
	for(int i=l;i<=R[bl];i++) a[i] += d*(i-l+1);
	for(int i=L[br];i<=r;i++) a[i] += d*(i-l+1);
	build(bl); build(br);
	for(int i=bl+1;i<=br-1;i++){
		k[i] += d;
		b[i] += d*(1-l);
	}
}

int main(){
	n = read(); 
	for(int i=1;i<=n;i++) a[i] = read();
	init();
	Q = read();
	while(Q--){
		int op = read(),l = read(),r = read();
		if(op == 0){
			int x = read();
			update(l,r,x);
		}else{
			// cout << qry(pos[l]) << "\n";
			cout << query(l,r) << "\n";
		}
	}
	return 0;
}