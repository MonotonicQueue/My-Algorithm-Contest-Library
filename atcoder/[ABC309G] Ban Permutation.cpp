#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 110;
const int mod = 998244353;
int n,K;
ll f[N][N][1<<9],fac[N];
int main(){
	n = read(); K = read();
	f[0][0][0] = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<(1<<(2*K-1));k++){
				f[i+1][j][k>>1] = (f[i][j][k]+f[i+1][j][k>>1])%mod;
				int s = k>>1;
				for(int l=0;l<=2*K-2;l++){
					if(i+1+l-(K-1) >= 1 && i+1+l-(K-1) <= n && (s & (1<<l)) == 0)
						f[i+1][j+1][s^(1<<l)] = (f[i+1][j+1][s^(1<<l)]+f[i][j][k])%mod;
				}
			}
	fac[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	ll res = 0;
	for(int j=0;j<=n;j++){
		ll sum = 0;
		for(int k=0;k<(1<<(2*K-1));k++) sum = (sum+f[n][j][k])%mod;
		res = (res+sum*((j & 1) ? mod-1 : 1)%mod*fac[n-j]%mod)%mod;
	}
	cout << res;
	return 0;
}
