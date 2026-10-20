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
int n,m,u[N],a[N],f[N*900];
double o[N],q;
void solve(){
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++) cin >> u[i];
	for(int i=1;i<=n;i++) cin >> o[i];
	for(int i=1;i<=n;i++) a[i] = o[i]*o[i]*100;
	for(int i=1;i<=n;i++)
		for(int j=900*i;j>=a[i];j--) f[j] = max(f[j],f[j-a[i]]+u[i]);
	double k = m*m/q/q*100; int ans = 0;
//	printf("%.5lf\n",k);
	for(int j=0;j<=k;j++) ans = max(ans,f[j]);
	cout << ans;
}
int main(){
	int T = 1;
	while(T--) solve(); 
	return 0;
}
/*

	for(int i=1;i<=k;i++) cin >> f[i];
*/