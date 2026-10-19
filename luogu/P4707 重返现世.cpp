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
int n,m,k;
ll inv[N],f[12][N];
signed main(){
	n = read(); k = read(); m = read();
	k = n-k+1;  inv[1] = 1;
	for(int i=2;i<=m;i++) inv[i] = inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=k;i++) f[i][0] = -1;
	for(int i=1;i<=n;i++){
		int x = read();
		for(int j=m;j>=x;j--)
			for(int t=k;t;t--) f[t][j] = (f[t][j]+f[t-1][j-x]-f[t][j-x]+mod)%mod;
	}
	ll ans = 0;
	for(int i=1;i<=m;i++) ans = (ans+f[k][i]*inv[i]%mod)%mod;
	cout << ans*m%mod;
	return 0;
}

