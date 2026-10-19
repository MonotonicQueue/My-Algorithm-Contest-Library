#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int mod = 998244353;
ll n;
ll fpow(ll x,__int128 k){
	x %= mod;
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
int main(){
	n = read();
	if(n % mod == 0){
		cout << 0;
		return 0;
	}
	__int128 k=0,pw = 1;
	while(pw <= n) pw *= 10,k++;
	// cout << k << "\n";
	ll ans = ((fpow(10,(__int128)n*k)-1)*(fpow(fpow(10,k)-1,mod-2))%mod+mod)%mod;
	cout << (n%mod*ans%mod+mod)%mod;
	return 0;
}
