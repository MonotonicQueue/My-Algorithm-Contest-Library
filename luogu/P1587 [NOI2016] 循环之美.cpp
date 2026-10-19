#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e6+10;
const int M = 3e6;
int n,m,k;
int pr[N],cnt;
ll mu[N],sum[N];
bool vis[N];
inline void init(){
	mu[1] = 1;
	for(int i=2;i<=M;i++){
		if(!vis[i]){
			pr[++cnt] = i;
			mu[i] = -1;
		}
		for(int j=1;j<=cnt&&i*pr[j]<=M;j++){
			vis[i*pr[j]] = 1;
			if(i % pr[j] == 0) break;
			mu[i*pr[j]] = -mu[i];
		}
	}
	for(int i=1;i<=M;i++) sum[i] = sum[i-1]+mu[i];
}
unordered_map<int,ll> mpa;
struct node{ll x,y,z;};
bool operator<(node x,node y){
	if(x.x != y.x) return x.x < y.x;
	if(x.y != y.y) return x.y < y.y;
	return x.z < y.z;
}
map<node,ll> mp;
ll getmu(int x){
	if(x <= M) return sum[x];
	if(mpa[x]) return mpa[x];
	ll ans = 1;
	for(int l=2,r;l<=x;l=r+1){
		r = x/(x/l);
		ans = ans-(r-l+1)*getmu(x/l);
	}
	return mpa[x] = ans;
}
int a[2010],tot;
ll solve(int n,int m,int k){
	if(!n || !m) return 0;
	node h = node{n,m,k};
	if(mp[h]) return mp[h];
	ll ans = 0;
	if(k == 1){
		if(n > m) swap(n,m);
		ll s = 0,t = 0;
		for(int l=1,r;l<=n;l=r+1,s=t){
			r = min(n/(n/l),m/(m/l));
			t = getmu(r);
			ans += (t-s)*(n/l)*(m/l);
		}
		mp[node{m,n,k}] = ans;
	}else{
		for(int i=1;i<=tot && a[i] <= k;i++){
			if(k % a[i] == 0)
				ans += mu[a[i]]*solve(m/a[i],n,a[i]);
		}
	}
	return mp[h] = ans;
}
int main() {
	n = read(); m = read(); k = read();
	init();
	for(int i=1;i<=k;i++)
		if(k % i == 0) a[++tot] = i;
	printf("%lld",solve(n,m,k));
	return 0;
}
