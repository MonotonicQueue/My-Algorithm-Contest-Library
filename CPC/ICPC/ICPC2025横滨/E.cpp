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
struct Frac{
	ll p,q;
};
Frac cmax(Frac x,Frac y){
	if(x.p*y.q > x.q*y.p) return x;
	return y;
}
void solve(){
	ll a = read(),b = read(),c = read(),k = read();
	double L = 0,R = 1e9;
	while(R-L > 1e-6){
		double mid = (L+R)/2.0;
		double x = floor(a/mid)*floor(b/mid)*floor(c/mid);
		if(x >= k) L = mid;
		else R = mid;
	}
	Frac ans = Frac{1,1000000000};
	for(int i=max(int(a/L-3000),1);i<=int(a/L+3000);i++){
		ll p = a,q = i;
		// cout << i << " " <<p << " " << q << "\n";
		if((a*q/p)*(b*q/p)*(c*q/p) >= k) ans = cmax(ans,Frac{p,q});
	}
	for(int i=max(int(b/L-3000),1);i<=int(b/L+3000);i++){
		ll p = b,q = i;
		if((a*q/p)*(b*q/p)*(c*q/p) >= k) ans = cmax(ans,Frac{p,q});
	}
	for(int i=max(int(c/L-3000),1);i<=int(c/L+3000);i++){
		ll p = c,q = i;
		if((a*q/p)*(b*q/p)*(c*q/p) >= k) ans = cmax(ans,Frac{p,q});
	}
	ll d = __gcd(ans.p,ans.q);
	cout << ans.p/d << " " << ans.q/d << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
