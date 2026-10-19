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
const int N = 56000;
const int mod = 998244353;
int n,m,x,a[N];
int f[N],g[1010][N];
int main(){
	a[1] = a[2] = 1;
	for(int i=3;i<=30;i++) a[i] = a[i-1]+a[i-2];
	for(int i=1;i<=a[10]*1000;i++){
		f[i] = 1e9;
		for(int j=1;a[j]<=i;j++)
			f[i] = min(f[i],f[i-a[j]]+1);
	}
	n = read(); x = read(); m = read();
	g[0][0] = 1;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=n;j++)
			for(int k=a[i];k<=a[i]*n;k++)
				g[j][k] = (g[j][k]+g[j-1][k-a[i]])%mod;
	int ans = 0;
	for(int i=1;i<=a[10]*n;i++)
		if(f[i] == m) ans = (ans+g[n][i])%mod;
	cout << ans;
	return 0;
}
