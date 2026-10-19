#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 210;
const int M = N*(N+1)/2;
const int mod = 1e9+7;
int n,lim,m;
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
ll pw[M][N],C[N][N];
void init(){
	C[0][0] = 1;
	for(int i=1;i<=n;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++) C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=m;i++){
		pw[i][0] = 1;
		for(int j=1;j<=n;j++) pw[i][j] = pw[i][j-1]*i%mod;
	}
}
ll f[N][M],g[M],tmp[M];
typedef vector<ll> poly;
poly operator*(poly x,poly y){
	int n = x.size(),m = y.size();
	poly res(n+m-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) res[i+j] = (res[i+j]+x[i]*y[j])%mod;
	return res;
}
void solve(){
	poly G = {1};
    for(int i=1;i<=m;i++){
        poly h = {-i,1};
        G = G*h;
    }
    for(int i=1;i<=m;i++){
        ll t = 1;
        for(int j=1;j<=m;j++)
            if(i != j) t = t*(i-j)%mod;
        if(t < 0) t += mod;
        t = fpow(t,mod-2);
        t = t*f[n][i]%mod;
        for(int j=0;j<=m;j++) tmp[j] = G[j];
        for(int j=m;j;j--){
            tmp[j-1] = (tmp[j-1]+tmp[j]*i)%mod;
            g[j-1] = (g[j-1]+tmp[j]*t)%mod;
        }
    }
}
int main(){
	n = read(); lim = read();
	if(lim > n*(n+1)/2) return puts("0"),0;
	m = n*(n+1)/2+1;
	init();
	for(int i=1;i<=m;i++){
		f[0][i] = 1;
		f[1][i] = i;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++)
				f[i][j] = (f[i][j]+C[i-1][k-1]*f[k-1][j]%mod*f[i-k][j])%mod;
			f[i][j] = f[i][j]*pw[j][i]%mod;
		}
	}
	solve();
	ll ans = 0;
	for(int i=lim;i<=m;i++) ans = (ans+g[i])%mod;
	cout << (ans+mod)%mod << "\n";
	return 0;
}

