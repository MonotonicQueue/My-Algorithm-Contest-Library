#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 510;
const int mod = 999911659;
ll n,p;
ll g[N],f[N][12][N];
inline void add(ll &x,ll y){
	x = x+y >= mod ? x+y-mod : x+y;
}
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
ll c[N][10];
ll C(ll x,ll y){
	if(!y) return 1;
	if(x < y) return 0;
	ll res = 1,mul = 1;
	for(ll i=x;i>=x-y+1;i--) res = res*i%mod;
	for(ll i=1;i<=y;i++) mul = mul*i%mod;
	return res*fpow(mul,mod-2)%mod;
}
int vis[N],a[2020];
int main(){
	n = read(); p = read();
	int l = 0,r = 0;
	for(int i=1,now=0;i<=n;i++){
		now = (now*10+1)%p;
		a[i] = now;
		if(vis[now]){
			l = vis[now]; r = i;
			break;
		}
		vis[now] = i;
		g[now]++;
	}
	ll w = 0;
	if(l && r){
		n -= r-1;
		ll x = n/(r-l);
		for(int i=l;i<r;i++) g[a[i]] += x;
		for(int i=1;i<=n%(r-l);i++) g[a[i+l-1]]++;
		for(int i=0;i<p;i++) g[i] %= mod;
		if(n % (r-l) == 0) w = a[r-1];
		else w = a[n%(r-l)+l-1];
	}else w = a[n];
	for(int i=0;i<p;i++)
		for(int j=0;j<=8;j++) c[i][j] = C(g[i]+j-1,j);
	f[0][0][w] = 1;
	for(int i=0;i<p;i++) for(int j=0;j<=8;j++)
		for(int k=0;k<p;k++) for(int h=0;h+j<=8;h++)
			add(f[i+1][j+h][(k+i*h)%p],f[i][j][k]*c[i][h]%mod);
	ll ans = 0;
	for(int i=0;i<9;i++) add(ans,f[p][i][0]);
	cout << ans;
    return 0;
}
