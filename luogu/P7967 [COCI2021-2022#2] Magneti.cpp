#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 55;
const int mod = 1e9+7;
int n,D,a[N];
ll f[2][N][10005];
ll inv=1;
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
ll C(ll x){
    ll res = 1;
    for(int i=1;i<=n;i++) res = res*(x-i+1)%mod;
    return res*inv%mod;
}
int main(){
    n = read(); D = read();
	for(int i=1;i<=n;i++) a[i] = read()-1;
	int mx = 0; 
	for(int i=1;i<=n;i++){
		mx = max(mx,a[i]);
		inv = inv*i%mod;
	}
	mx = mx*(n-1);
	mx = min(D-n,mx);
	inv = fpow(inv,mod-2);
	sort(a+1,a+1+n);
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
        int c = i&1;
        memset(f[c],0,sizeof(f[c]));
		for(int j=1;j<=n;j++){
			for(int k=0;k<=mx;k++){
				f[c][j][k] = f[c^1][j-1][k];
				if(k >= a[i]) f[c][j][k] = (f[c][j][k]+f[c^1][j][k-a[i]]*j*2)%mod;
				if(k >= 2*a[i]) f[c][j][k] = (f[c][j][k]+f[c^1][j+1][k-2*a[i]]*(j+1)*j)%mod;
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<=mx;i++)
		ans = (ans+f[n&1][1][i]*C(D-i)%mod)%mod;
	cout << ans;
    return 0;
}