#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e4+10;
int T,n;
struct node{
	int d;
	ll a,b;
}c[N];
ll ans;
ll d[N];
bool cmp(node x,node y){
	if(x.d != y.d) return x.d < y.d;
	if(x.d ==  -1) return x.a < y.a;
	return x.b > y.b;
}
int main(){
	T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++){
			c[i].a = read(); c[i].b = read();
			if(c[i].a > c[i].b) c[i].d = 1;
			else if(c[i].a == c[i].b) c[i].d = 0;
			else c[i].d = -1;
		}
		sort(c+1,c+1+n,cmp);
		ll sum = 0; ans = 0;
		for(int i=1;i<=n;i++){
			sum += c[i].a;
			d[i] = max(d[i-1],sum)+c[i].b;
		}
		cout << d[n] << "\n";
	}
	return 0;
}
