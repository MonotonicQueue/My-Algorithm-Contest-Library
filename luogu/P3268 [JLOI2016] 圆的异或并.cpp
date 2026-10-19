#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 2e5+10;
int n;
struct node{
	ll id,x,y,r;
	ll t;
}; 
ll m,l,X[N],Y[N],R[N];
bool operator<(node a,node b){
    double u, v;
    if(abs(l - a.x) == a.r) u = a.y; else 
        u = a.y + (a.t ? 1 : -1) * sqrt(pow(a.r, 2) - pow(l - a.x, 2));
    if(abs(l - b.x) == b.r) v = b.y; else 
        v = b.y + (b.t ? 1 : -1) * sqrt(pow(b.r, 2) - pow(l - b.x, 2));
    if(a.t == true) u += 1e-9;
    if(b.t == true) v += 1e-9;
    return u < v;
}
struct Temp{
	ll id,s,t;
}a[N*2];

bool cmp(Temp x,Temp y){
	return x.s < y.s;
}
set<node>t;
ll f[N*2],d[N*2];
ll ans;
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		X[i] = read(); Y[i] = read(); R[i] = read();
		a[++m] = Temp{i,X[i]-R[i],1};
		a[++m] = Temp{i,X[i]+R[i],0};
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		l = a[i].s;
		int p = a[i].id;
		node x = node{p,X[p],Y[p],R[p],1},
			 y = node{p,X[p],Y[p],R[p],0};
		if(a[i].t){
			auto q = t.lower_bound(x);
			if(q == t.end()) f[p] = 0;
			else f[p] = q -> t ? q -> id : f[q -> id];
			t.insert(x); t.insert(y);
			d[p] = d[f[p]]+1;
			ans += R[p]*R[p]*(d[p]%2==1?1:-1);
		}else{
			t.erase(x);
			t.erase(y);
		}
	}
	cout << ans;
	return 0;
}