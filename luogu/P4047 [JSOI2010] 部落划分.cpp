#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
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
const int N = 1010;
int n,k,tot,fa[N];
pair<db,db> a[N];
pair<db,pii> e[N*N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++){
		a[i].fi = read();
		a[i].se = read();
		fa[i] = i;
	}
	auto dis = [&](pair<db,db> x,pair<db,db> y){
		return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
	};
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) e[++tot] = mk(dis(a[i],a[j]),mk(i,j));
	k = n-k;
	sort(e+1,e+1+tot);
	for(int i=1;i<=tot;i++){
		int u = e[i].se.fi,v = e[i].se.se;
		u = get(u); v = get(v);
		if(u == v) continue;
		if(!k){
			printf("%.2lf",e[i].fi);
			return 0;
		}
		fa[u] = v;
		k--;
	}
    return 0;
}
