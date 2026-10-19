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
const int N = 35;
int h,q;
map<int,int> t;
#define ls x<<1
#define rs x<<1|1 
double dfs(int x,int sum,int mx){
	if(x >= (1<<h)) mx =  max(mx,t[x]);
	if(t[x] <= mx) return 1.0*mx*sum/(1<<h);
	return dfs(ls,sum/2,max(mx,t[x]-t[ls]))+dfs(rs,sum/2,max(mx,t[x]-t[rs]));
}
int main(){
	h = read(); q = read();
	while(q--){
		char op[114];
		cin >> op;
		if(op[0] == 'a') {
			int v = read(),e = read();
			while(v) t[v] += e,v /= 2;
		}else{
			printf("%.10lf\n",dfs(1,1<<h,0));
		}
	}
	return 0;
}