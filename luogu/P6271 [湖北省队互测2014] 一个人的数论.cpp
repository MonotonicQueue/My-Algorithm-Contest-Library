#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e3+10;
const int mod = 1e9+7;
int d,m;
ll fpow(ll x,ll k){
	if(k == -1) k = mod-2;
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
struct poly{
	int len;
	ll f[210];
	void init(ll x){
		f[0] = x;
	}
	void init(ll x,ll y){
		f[0] = x; f[1] = y; len = 1;
	}
	poly(){
		len = 0; memset(f,0,sizeof(f));
	}
	ll &operator[](int x){
		return f[x];
	}
};
poly operator*(poly x,poly y){
	poly res; res.len = x.len+y.len;
	for(int i=0;i<=x.len;i++)
		for(int j=0;j<=y.len;j++)
			res[i+j] = (res[i+j]+x[i]*y[j]%mod)%mod;
	return res;
}
poly operator+(poly x,poly y){
	poly res; res.len = max(x.len,y.len);
	for(int i=0;i<=res.len;i++) res[i] = (x[i]+y[i])%mod;
	return res;
}
ll f[210],g[110];
void Lagrange(){
	for(int i=1;i<=d+2;i++) g[i] = (g[i-1]+fpow(i,d))%mod;
	poly res;
	for(ll i=1;i<=d+2;i++){
		poly x; x.init(g[i]);
		for(ll j=1;j<=d+2;j++){
			if(i == j) continue;
			ll inv = fpow((i-j+mod)%mod,mod-2);
			poly y; y.init((mod-j)*inv%mod,inv);
			x = x*y;
//			for(int i=0;i<=x.len;i++) cout << x[i] << " ";
//			cout << "\n";
		}
		res = res+x;
//		for(int i=0;i<=res.len;i++) cout << res[i] << " ";
//		cout << "\n";
	}
	for(int i=0;i<=d+1;i++) f[i] = res[i];
//	for(int i=0;i<=d+1;i++) cout << f[i] << " ";
//	cout << "\n";
}
ll n=1,p[N];
signed main(){
	d = read(); Lagrange(); m = read();
	for(int i=1;i<=m;i++){
		p[i] = read(); ll k = read();
		n = n*fpow(p[i],k)%mod;
	}
	ll ans = 0;
	for(int a=0;a<=d+1;a++){
		ll res = f[a]*fpow(n,a)%mod,sum = 0;
		for(int i=1;i<=m;i++){
			ll t = (mod-1)*fpow(p[i],d-a)%mod;
			sum = (sum*t%mod+sum+t)%mod;
		}
//		cout << res <<" " << sum << "\n";
		ans = (ans+res*sum)%mod;
	}
	for(int i=0;i<=d+1;i++) ans = (ans+fpow(n,i)*f[i])%mod;
	cout << ans;
	return 0;
}