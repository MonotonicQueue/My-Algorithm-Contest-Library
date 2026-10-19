#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
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
const int N = 1e6+10;
ll n,k,w,h;
ll exgcd(ll &x,ll &y,ll a,ll b){
	if(!b){x = 1; y = 0; return a;}
	ll d = exgcd(x,y,b,a%b);
	ll z = x; x = y; y = z-(a/b)*y;
	return d;
}
ll inv(ll x,ll mod){
	ll X,Y;
	exgcd(X,Y,x,mod);
	X = (X%mod+mod)%mod;
	assert(X*x%mod == 1);
	return X;
}
ll solve(ll x,ll y,ll mod){
	ll d = __gcd(x,mod);
	if(y % d) return -1;
	x /= d; y /= d; mod /= d;
	if(mod == 1) return 0;
	return y*inv(x,mod)%mod;
}
char s[N];
vector<pii> v;

int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		w = read()*2; h = read()*2;
		scanf("%s",s+1);
		v.clear();
		ll x = 0,y = 0;
		for(int i=1;i<=n;i++){
			if(s[i] == 'U') y++;
			if(s[i] == 'D') y--;
			if(s[i] == 'L') x--;
			if(s[i] == 'R') x++;
			x = (x+w)%w; y = (y+h)%h;
			v.push_back(mk(x,y));
		}
		ll ww = w/__gcd(x,w),
		   hh = h/__gcd(y,h),
		   lcm = ww*hh/__gcd(ww,hh);
		ll ans = 0;
		for(auto it : v){
			ll nx = it.fi,ny = it.se;
			if(nx) nx = w-nx;
			if(ny) ny = h-ny;
			ll kx = solve(x,nx,w);
			ll ky = solve(y,ny,h);
			if(kx == -1 || ky == -1) continue;
			ll c = ((ky-kx)%hh+hh)%hh;
			ll z = solve(ww,c,hh);
			if(z == -1) continue;
			ll a = kx+z*ww;
			if(a <= k-1) ans += (k-a-1)/lcm+1;
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
1
2 4 2 2
UR

*/