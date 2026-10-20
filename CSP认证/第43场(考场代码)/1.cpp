#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(ch != '-' && !isdigit(ch)) ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
//const int mod = 1e9+7;
//ll fpow(ll x,ll k){
//	ll res = 1;
//	while(k){
//		if(k & 1)
//			res = res*x%mod;
//		x = x*x%mod;
//		k >>= 1;
//	}
//	return res;
//}
const int N = 110;
int n,m,k;
double u[N],o[N],x[N],f[N];
void solve(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) cin >> u[i];
	for(int i=1;i<=n;i++) cin >> o[i];
	for(int i=1;i<=k;i++) cin >> x[i];
	for(int i=1;i<=k;i++) cin >> f[i];
	double U = 0,O = 0;
	for(int i=1;i<=n;i++) U += u[i];
	for(int i=1;i<=n;i++) O += o[i]*o[i];
	O = sqrt(O);
	double z = (m-U)/O;
	int p = 1;
	for(int i=2;i<=k;i++){
		if(abs(x[i]-z) < abs(x[p]-z)) p = i;
	}
	printf("%.3lf",f[p]);
}
int main(){
	int T = 1;
	while(T--) solve(); 
	return 0;
}
/*

	for(int i=1;i<=k;i++) cin >> f[i];
*/