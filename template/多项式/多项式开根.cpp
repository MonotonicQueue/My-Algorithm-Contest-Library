#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){ch = getchar(); r = -1;}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar(); 
	}
	return X*r;
}
const int N = 1<<20;
const int mod = 998244353;
const int g = 3,gi = 332748118;
ll inv2;
int n,rev[N];
ll F[N],G[N],a[N],b[N];
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
	for(int i=1;i<n;i++)
		if(i < rev[i]) swap(f[i],f[rev[i]]);
	for(int mid=1;mid<n;mid<<=1){
		ll gn = fpow(type == 1 ? g : gi,(mod-1)/(mid<<1));
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
	ll inv = fpow(n,mod-2);
	for(int i=0;i<n;i++) f[i] = f[i]*inv%mod;
}
ll c[N];
void polyinv(ll *f,ll *g,int n){
	if(n == 1){
		g[0] = fpow(f[0],mod-2);
		return ;
	}
	polyinv(f,g,(n+1)>>1);
	int limit = 1,l = 0;
	while(limit <= (n<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	for(int i=0;i<n;i++) c[i] = f[i];
	for(int i=n;i<limit;i++) c[i] = 0;
	NTT(c,limit,1); NTT(g,limit,1);
	for(int i=0;i<limit;i++)
		g[i] = (2ll-c[i]*g[i]%mod+mod)%mod*g[i]%mod;
	NTT(g,limit,-1);
	for(int i=n;i<limit;i++) g[i] = 0;
	for(int i=0;i<limit;i++) c[i] = 0;
}
void polysqrt(ll *f,ll *g,int n){
	if(n == 1){
		g[0] = 1; 
		return ;
	}
	polysqrt(f,g,(n+1)>>1);
	polyinv(g,a,n);
	int limit = 1,l = 0;
	while(limit <= (n<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	for(int i=0;i<n;i++) b[i] = f[i];
	for(int i=n;i<limit;i++) b[i] = 0;
	NTT(b,limit,1); NTT(g,limit,1);
	NTT(a,limit,1);
	for(int i=0;i<limit;i++)
		g[i] = (g[i]*g[i]%mod+b[i])%mod*inv2%mod*a[i]%mod;
	NTT(g,limit,-1);
	for(int i=n;i<limit;i++) g[i] = 0;
	for(int i=0;i<limit;i++) a[i] = b[i] = 0;
}
int main(){
	inv2 = fpow(2,mod-2);
	n = read();
	for(int i=0;i<n;i++) F[i] = read();
	polysqrt(F,G,n);
	for(int i=0;i<n;i++) cout << G[i] << " ";
	return 0;
}
