#include<bits/stdc++.h>
#define ll long long
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
const int N = 210;
const int M = 3e5+10;
const int mod = 998244353;
int c,n,T;
ll a[N],t[N],suma[N],sumt[N],pw[N];
ll g[M],ans;
int main(){
	c = read(); n = read(); T = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) t[i] = read();
	for(int i=1;i<=n;i++)
		suma[i] = (suma[i-1]+a[i])%mod,
		sumt[i] = sumt[i-1]+t[i];
	pw[0] = 1;
	for(int i=1;i<=n;i++) pw[i] = pw[i-1]*2%mod;
	g[0] = 1;
	for(int i=1;i<=n;i++){
		ll cnt = 0;
		for(int j=0;j<=T-t[i];j++) cnt = (cnt+g[j])%mod;
		ans = (ans+cnt*a[i]%mod*pw[n-i]%mod)%mod;
		for(int j=T;j>=t[i];j--) g[j] = (g[j-t[i]]+g[j])%mod;
	}
	memset(g,0,sizeof(g));
	g[0] = 1;
	for(int i=n;i>=1;i--){
		ll cnt = 0;
		for(int j=0;j<=T-sumt[i];j++) cnt = (cnt+g[j])%mod;
		ans = (ans+cnt*a[i]%mod*pw[i-1]%mod)%mod;
		for(int j=T;j>=t[i];j--) g[j] = (g[j-t[i]]+g[j])%mod;
	}
	cout << ans;
	return 0;
}



























