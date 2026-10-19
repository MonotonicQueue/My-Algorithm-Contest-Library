#include<bits/stdc++.h>
#define ll long long 
#define int64 __int128
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int mod = 1e9+7;
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
ll phi(ll x){
	ll res = x;
	for(int i=2;i*i<=x;i++){
		if(x % i == 0){
			res = res/i*(i-1);
			while(x % i == 0) x /= i;
		}
	}
	if(x != 1) res = res/x*(x-1);
	return res;
}
signed main(){
	int T = read();
	while(T--){
		ll n = read(),ans = 0;
		for(ll i=1;i*i<=n;i++){
			if(n % i == 0){
				ans = (ans+fpow(n,i)*phi(n/i)%mod)%mod;
				if(i*i!=n) ans = (ans+fpow(n,n/i)*phi(i)%mod)%mod;
			}
		}
		cout << ans*fpow(n,mod-2)%mod << "\n";
	}
	return 0; 
}
