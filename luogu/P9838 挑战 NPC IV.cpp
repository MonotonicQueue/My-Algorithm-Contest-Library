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
const int N = 62;
const int M = 1e6+10;
const int mod = 998244353;
ll pw[N+5],sum[N+5],fac[N],inv[N];
ll a[N],b[N];
int LOG2[M],cnt[N];
ll fpow(ll x,ll k){
	x %= mod; k %= mod-1;
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
ll S(ll x){
	x %= mod;
	return x*(x+1)%mod*(2*x+1)%mod*inv[6]%mod;
}
ll calc(ll n,ll l,ll r){
	if(l > r) return 0;
	if(r > n/2 && l <= n/2) return (calc(n,l,n/2)+calc(n,n/2+1,r))%mod;
	if(l > n/2) l = n-l,r = n-r,swap(l,r);
	ll res = n%mod*((l+r)%mod)%mod*((r-l+1)%mod)%mod*inv[2]%mod;
	ll rtn = (S(r)-S(l-1)+mod)%mod;
	return ((res-rtn)%mod+mod)%mod;
}
ll g(ll x,ll y){
	x %= mod; y %= mod;
	return y*(x-y+1ll)%mod;
}
inline void solve(ll n){
	ll l = 1,r = n,res = 0;
	for(int i=log(n)/log(2);i>=0;i--){
		ll sum = (n>>i)-(n>>(i+1));
		ll nl = sum/2,nr = sum-nl;
		if(l < n-r+1) swap(nl,nr);
		res = (res+(i+1)*calc(n+1,l,l+nl-1)%mod)%mod;
		res = (res+(i+1)*calc(n+1,r-nr+1,r)%mod)%mod;
		l += nl; r -= nr;
	}
	printf("%lld\n",res);
}
ll f[16][9][5][3][2][11005];
int t[N],Maxn = 11000;
int main(){
	int Q = read();
	pw[0] = fac[0] = 1;
	for(int i=1;i<=N;i++) pw[i] = pw[i-1]*2;
	for(int i=1;i<=20;i++) fac[i] = fac[i-1]*i;
	inv[2] = fpow(2,mod-2); inv[6] = fpow(6,mod-2);
	for(int i=2;i<=1000000;i++) LOG2[i] = LOG2[i/2]+1;
	int maxn = 10000;
	while(Q--){
		ll n = read(),k = read();
		if(n > 28){
			solve(n);
			continue;
		}
		for(int i=1;i<=n;i++) a[i] = 1+LOG2[i&(-i)];
		for(int i=1;i<=n;i++) b[i] = i*(n-i+1);
		sort(a+1,a+1+n); sort(b+1,b+1+n);
		for(int i=1;i<=n;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		ll Sum = 1;
		for(int i=1;i<=LOG2[n]+1;i++) Sum *= fac[cnt[i]];
		f[0][0][0][0][0][0] = 1;
		for(t[1]=0;t[1]<=cnt[1];t[1]++) for(t[2]=0;t[2]<=cnt[2];t[2]++) for(t[3]=0;t[3]<=cnt[3];t[3]++) 
		for(t[4]=0;t[4]<=cnt[4];t[4]++) for(t[5]=0;t[5]<=cnt[5];t[5]++) {
			int sum = t[1]+t[2]+t[3]+t[4]+t[5];
			if(!sum) continue;
			for(int j=0;j<=Maxn;j++){
				int i = 0;
				for(int k=1;k<=5;k++){
					if(t[k] == 0 || j-k*b[sum] < 0) continue;
					t[k]--;
					i += f[t[1]][t[2]][t[3]][t[4]][t[5]][j-k*b[sum]];
					t[k]++;
				}
				f[t[1]][t[2]][t[3]][t[4]][t[5]][j] = i;
			}
		}
		ll res = 0;
		for(int i=0;i<=Maxn;i++){
			res += Sum*f[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][i];
			if(res >= k){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
