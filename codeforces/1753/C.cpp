#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
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
const int mod = 998244353;
const int N = 2e5+10;
int n,a[N];
ll fpow(ll x,ll k){
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
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		ll res = 0;
		int cnt0 = 0,m = 0;
		for(int i=1;i<=n;i++) cnt0 += a[i] == 0;
		for(int i=1;i<=cnt0;i++) m += a[i];
		ll sum = 1ll*n*(n-1)/2%mod;
		for(ll i=1;i<=m;i++) res = (res+fpow(1ll*i*i,mod-2))%mod;
		res = res*sum%mod;
		cout << res << "\n";
	}
	return 0;
}