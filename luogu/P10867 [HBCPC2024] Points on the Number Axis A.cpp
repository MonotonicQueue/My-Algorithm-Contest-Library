#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
const int mod = 998244353;
int n;
ll a[N],sum;
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
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum = (sum+a[i])%mod;
	}
	cout << sum*fpow(n,mod-2)%mod;
	return 0;
}