#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e4+10;
const int mod = 998244353;
int n,a[N];
ll f[N<<1],g[N<<1];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+1+n);
	f[0] = 1;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10000;j++) g[j] = 0;
		for(int j=0;j<=10000;j++){
			if(j+a[i] <= 10000) g[j+a[i]] = f[j];
			else f[10001] = (f[10001]+f[j]*(j+1+a[i])/2)%mod;
		}
		for(int j=0;j<=10000;j++) ans = (ans+max((j+1)/2,a[i])*g[j])%mod;
		for(int j=0;j<=10000;j++) f[j] = (f[j]+g[j])%mod;
	}
	cout << (ans+f[10001])%mod;
	return 0;
}
