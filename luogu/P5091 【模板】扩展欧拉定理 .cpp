#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,m;
ll Phi(ll x){
	ll s = x;
	for(int i=2;i*i<=x;i++){
		if(x%i != 0) continue;
		s = s/i*(i-1);
		while(x%i == 0) x /= i;
	}
	if(x > 1) s = s/x*(x-1);
}
int main(){
	cin >> a >> m;
	ll phi = Phi(m);
	char c = getchar();
	while(c = getchar()){
		if(!isdigit(c)) break;
		b = b*10+c-'0';
		bool flag = false;
		if(b >= phi){
			b %= phi;
			flag = true;
		}
		if(flag) b += phi;
	}
	ll ans = 1,base = a;
	while(b){
		if(b & 1) ans = ans*base%m;
		base = base*base%m;
		b >>= 1;
	}
	cout << ans;
	return 0;
}