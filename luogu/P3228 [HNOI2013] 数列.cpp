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
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
ll n,k,m,p;
ll fpow(ll x,ll y){
	x %= p;
	ll res = 1;
	while(y){
		if(y & 1)
			res = res*x%p;
		x = x*x%p;
		y >>= 1;
	}
	return res;
}
int main(){
	n = read(); k = read(); m = read(); p = read();
	n %= p;
	ll ans = n*fpow(m,k-1)%p;
	ll tmp = (__int128)(m*(m+1)/2)%p*fpow(m,k-2)*(k-1)%p;
	cout << ((ans-tmp+p)%p+p)%p;
	return 0;
}