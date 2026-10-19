#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
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
const int N = 710;
const int mod = 998244353;
int n;
ll a[N],b[N],c[N];
ll f[2][N][N],g[2][N][N];
ll u[N][N],v[N][N],s[N][N];
ll fac[N],inv[N],ans[N];
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
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = fpow(fac[n],mod-2);
	for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	for(int i=0;i< n;i++) c[i] = read();
	u[0][0] = a[1]; v[0][0] = b[1];
	for(int i=1;i<=n;i++){
		int c = i&1;
		if(i == 1) f[c][1][0] = 1;
		else{
			for(int j=1;j<=i;j++)
				for(int k=0;k<i;k++) f[c][j][k] = 0;
			for(int j=1;j<=i;j++)
				for(int k=0;k<i;k++){
					f[c][j][k] = f[c^1][j][k]*(k+1)%mod;
					if(k){
						f[c][j][k] = (f[c][j][k]+f[c^1][j-1][k-1])%mod;
						f[c][j][k] = (f[c][j][k]+f[c^1][j][k-1]*(i-1-k)%mod)%mod;
					}
				}
		}
		for(int j=1;j<=i;j++)
			for(int k=0;k<i;k++) g[c][j][k] = f[c][j][i-k-1];
		for(int x=0;x<i;x++)
			for(int j=1;j<=i;j++)
				u[i][x] = (u[i][x]+f[c][j][x]*a[j+1]%mod)%mod,
				v[i][x] = (v[i][x]+g[c][j][x]*b[j+1]%mod)%mod;
	}
	for(int i=0;i<=n;i++)
		for(int k=0;k<=i;k++)
			u[i][k] = u[i][k]*inv[i]%mod,
			v[i][k] = v[i][k]*inv[i]%mod;
	for(int i=0;i<=n;i++)
		for(int x=0;x<=i;x++)
			for(int y=0;x+y+(i>0)<n;y++)
				s[i][y] = (s[i][y]+u[i][x]*c[x+y+(i>0)]%mod)%mod;
	for(int i=0;i<=n;i++)
		for(int j=0;i+j+1<=n;j++)
			for(int y=0;y<=j;y++) ans[i+j+1] = (ans[i+j+1]+s[i][y]*v[j][y]%mod)%mod;
	for(int i=1;i<=n;i++) cout << ans[i]*fac[i-1]%mod << " ";
	return 0;
}