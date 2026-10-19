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
int n,m,rev[N];
ll F[N],G[N],P[N],R[N];
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
		ll gn = fpow(type==1 ? g : gi,(mod-1)/(mid<<1));
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
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	for(int i=0;i<n;i++) c[i] = f[i];
	for(int i=n;i<limit;i++) c[i] = 0;
	NTT(c,limit,1); NTT(g,limit,1);
	for(int i=0;i<limit;i++)
		g[i] = (2ll-c[i]*g[i]%mod+mod)*g[i]%mod;
	NTT(g,limit,-1);
	for(int i=n;i<limit;i++) g[i] = 0;
	for(int i=0;i<limit;i++) c[i] = 0;
}
ll a[N],b[N],d[N];
void Div(ll *f,ll *g,ll *p,int n,int m){
	int len = n-m+1;
	for(int i=0;i<len;i++) p[i] = f[n-i];
	for(int i=0;i<len;i++) a[i] = g[m-i];
	polyinv(a,b,len);
	int limit = 1,l = 0;
	while(limit <= (len<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	NTT(p,limit,1); NTT(b,limit,1);
	for(int i=0;i<limit;i++) p[i] = p[i]*b[i]%mod;
	NTT(p,limit,-1);
	for(int i=len;i<limit;i++) p[i] = 0;
	reverse(p,p+len);
	for(int i=0;i<limit;i++) a[i] = b[i] = 0;
}
void Mod(ll *f,ll *g,ll *p,ll *r,int n,int m){
	Div(f,g,p,n,m);
	for(int i=0;i<=m;i++) a[i] = g[i];
	for(int i=0;i<=n-m;i++) b[i] = p[i];
	int limit = 1,l = 0;
	while(limit <= (n<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	NTT(a,limit,1); NTT(b,limit,1);
	for(int i=0;i<limit;i++) a[i] = a[i]*b[i]%mod;
	NTT(a,limit,-1);
	for(int i=0;i<m;i++) r[i] = (f[i]-a[i]+mod)%mod;
	for(int i=0;i<limit;i++) a[i] = b[i] = 0;
}
int main(){
	n = read(); m = read(); 
	for(int i=0;i<=n;i++) F[i] = read();
	for(int i=0;i<=m;i++) G[i] = read();
	Mod(F,G,P,R,n,m);
	for(int i=0;i<=n-m;i++) cout << P[i] << " ";
	cout << "\n";
	for(int i=0;i<m;i++) cout << R[i] << " "; 
	return 0;
}