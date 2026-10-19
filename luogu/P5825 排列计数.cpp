#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1<<20;
const int mod = 998244353;
const int gg = 3,ig = (mod+1)/gg;
int n;
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
void init(int n = 1e6){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

typedef vector<ll> poly;
int rev[N];
inline poly NTT(poly F,int type){
	int n = F.size();
	for(int i=0;i<n;i++)
		if(i < rev[i]) swap(F[i],F[rev[i]]);
	for(int mid=1;mid<n;mid<<=1){
		ll gn = fpow(type == 1 ? gg : ig,(mod-1)/(mid << 1));
		for(int j=0,len=mid<<1;j<n;j+=len){
			ll g0 = 1;
			for(int i=0;i<mid;i++){
				ll x = F[i+j],y = F[i+j+mid]*g0%mod;
				F[i+j] = (x+y)%mod;
				F[i+j+mid] = (x-y+mod)%mod;
				g0 = g0*gn%mod;
			}
		}
	}
	if(type != 1){
		int inv = fpow(n,mod-2);
		for(int i=0;i<n;i++) F[i] = F[i]*inv%mod;	
	}
	return F;
}
poly operator + (poly x,poly y){
	int n = x.size(),m = y.size();
	poly res(max(n,m));
	for(int i=0;i<n;i++) res[i] = x[i];
	for(int i=0;i<m;i++) res[i] = (res[i]+y[i])%mod;
	return res;
}
poly operator * (poly x,poly y){
	int n = x.size(),m = y.size();
	int l = 0;
	while((1 << l) < n+m-1) l++;
	for(int i=1;i<(1<<l);i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	poly f(1<<l),g(1<<l);
	for(int i=0;i<n;i++) f[i] = x[i];
	for(int i=0;i<m;i++) g[i] = y[i];
	f = NTT(f,1); g = NTT(g,1);
	for(int i=0;i<(1<<l);i++) f[i] = f[i]*g[i]%mod;
	f = NTT(f,-1);
	f.resize(n+m-1);
	return f;
}
signed main(){
    init();
	n = read();
    poly f(n+1,0),g(n+1,0);
    for(int i=0;i<=n;i++) g[i] = ((i & 1) ? mod-1 : 1)*inv[i]%mod;
    for(int i=0;i<=n;i++) f[i] = inv[i]*fpow(i,n)%mod;
    f = f*g;
    for(int i=0;i<=n;i++) f[i] = f[i]*fac[i]%mod;
    for(int i=0;i<=n;i++) f[i] = f[i]*fac[n-i]%mod;
    for(int i=0;i<=n;i++) g[i] = ((i & 1) ? mod-1 : 1)*inv[i]%mod;
    f = f*g;
    for(int i=0;i<=n;i++) f[i] = f[i]*inv[n-i]%mod;
    for(int i=n;~i;i--) cout << f[i] << " ";
    return 0;
}
