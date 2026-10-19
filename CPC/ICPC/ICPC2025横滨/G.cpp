#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 2e6+10;
const int mod = 998244353;
ll fac[N],inv[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
inline void init(int n = 2e6){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = i*fac[i-1]%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
	if(x < 0 || y > x) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll calc(int n,int m,int k){
	if(!k) return m == 0;
	ll ans = 0;
	for(int i=0;i*(k+1)<=m&&i<=n;i++){
		if(i & 1) ans -= C(n,i)*C(m+n-1-i*(k+1),n-1)%mod;
		else 	  ans += C(n,i)*C(m+n-1-i*(k+1),n-1)%mod;
		ans = (ans%mod+mod)%mod;
	}
	return ans;
}
void solve(){
	int n = read(),m = read(),k = read();
	cout << (calc(n,m,k)-calc(n,m-1,k-1)+mod)%mod;
}
int main(){
	init();
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
6
 1 2 1 2 2 1
*/