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
const int N = 65;
int n,m,p;
ll a[N],fac[N],inv[N],iinv[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%p;
		x = x*x%p;
		k >>= 1;
	}
	return res;
}
ll gcd(ll x,ll y){
	return y ? gcd(y,x%y) : x;
}
inline void init(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%p;
	for(int i=1;i<=n;i++) inv[i] = fpow(fac[i],p-2);
	for(int i=1;i<=n;i++) iinv[i] = fpow(i,p-2);
}
ll ans;
ll calc(int len){
//	for(int i=1;i<=len;i++) cout << a[i] << " ";
//	cout << "\n";
	ll res = 0,k = 0;
	for(int i=1;i<=len;i++) k += a[i]/2;
	for(int i=1;i<=len;i++)
		for(int j=1;j<i;j++)
			k += gcd(a[i],a[j]);
	res = fpow(m,k);
	for(int i=1;i<=len;i++) res = res*iinv[a[i]]%p;
	int cnt = 0;
	for(int i=1;i<=len;i++){
		if(a[i] == a[i-1]) cnt++;
		else{
			res = res*inv[cnt]%p;
//			cout << cnt << " ";
			cnt = 1;
		}
	}
//	cout << cnt << "\n";
	res = res*inv[cnt]%p;
	return res;
}
void dfs(int x,int len,int lst){
	if(!x){
		ans = (ans+calc(len))%p;
		return ;
	}
	for(int i=min(lst,x);i>=1;i--){
		a[len+1] = i;
		dfs(x-i,len+1,i);
	}
}
int main(){
	n = read(); m = read(); p = read();
	init();
	dfs(n,0,n);
	cout << ans;
	return 0;
} 