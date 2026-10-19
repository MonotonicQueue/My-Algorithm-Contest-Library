#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int N = 1<<20;
const int mod = 1004535809;
const int g = 3;
int n,rev[N];
ll F[N],G[N],fac[N],inv[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1) res = res*x%mod;
		x = x*x%mod;
		k >>= 1; 
	}
	return res;
}
void NTT(ll *f,int n,int type){
	for(int i=0;i<n;i++)
		if(i < rev[i]) swap(f[i],f[rev[i]]);
	for(int mid=1;mid<n;mid<<=1){
		ll gn = fpow(type == 1 ? g : fpow(g,mod-2),(mod-1)/(mid<<1));
		for(int len=mid<<1,j=0;j<n;j+=len){
			ll g0 = 1;
			for(int i=0;i<mid;i++){
				ll x = f[i+j],y = f[i+j+mid]*g0%mod;
				f[i+j] = (x+y)%mod;
				f[i+j+mid] = (x-y+mod)%mod;
				g0 = g0*gn%mod; 
			}
		}
	}
	if(type == 1) return ;
	ll Inv = fpow(n,mod-2);
	for(int i=0;i<n;i++) f[i] = f[i]*Inv%mod;
}
ll c[N];
void polyinv(ll *f,ll *g,int n){
	if(n == 1){
		g[0] = fpow(f[0],mod-2);
		return ;
	}
	polyinv(f,g,(n+1)>>1);
	int limit = 1,l = 0;
	while(limit < (n<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	for(int i=0;i<n;i++) c[i] = f[i];
	for(int i=n;i<limit;i++) c[i] = 0;
	NTT(c,limit,1); NTT(g,limit,1);
	for(int i=0;i<limit;i++) g[i] = (2ll-g[i]*c[i]%mod+mod)%mod*g[i]%mod;
	NTT(g,limit,-1);
	for(int i=n;i<limit;i++) g[i] = 0;
	for(int i=0;i<limit;i++) c[i] = 0;
}
ll a[N],b[N];
void polydev(ll *f,ll *g,int n){
	for(int i=1;i<n;i++) g[i-1] = f[i]*i%mod;
	g[n-1] = 0;
}
void polyinvdev(ll *f,ll *g,int n){
	for(int i=1;i<n;i++) g[i] = f[i-1]*fpow(i,mod-2)%mod;
	g[0] = 0;
}
void polyln(ll *f,ll *g,int n){
	polydev(f,a,n);
	polyinv(f,b,n);
	
	int limit = 1,l = 0;
	while(limit < (n<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	NTT(a,limit,1); NTT(b,limit,1);
	for(int i=0;i<limit;i++) a[i] = a[i]*b[i]%mod;
	NTT(a,limit,-1);
	polyinvdev(a,g,n);
	for(int i=0;i<limit;i++) a[i] = b[i] = 0;
}
int main(){
	n = read();
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i>=1;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(ll i=0;i<=n;i++) F[i] = fpow(2,1ll*i*(i-1)/2)*inv[i]%mod;
	polyln(F,G,n+1);
	cout << G[n]*fac[n]%mod;
	return 0;
}