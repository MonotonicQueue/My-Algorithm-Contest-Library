#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e7+10;
const int M = 1e6+10;
int phi[N],pr[M],cnt;
void getphi(int n){
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			phi[i] = i-1;
			pr[++cnt] = i;
		}
		for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
			if(i % pr[j] == 0){
				phi[i*pr[j]] = phi[i]*pr[j];
				break;
			}
			phi[i*pr[j]] = phi[i]*phi[pr[j]];
		}
	}
}
ll fpow(ll x,ll k,int p){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%p;
		x = x*x%p;
		k >>= 1;
	}
	return res;
}
ll mod;
ll solve(ll p){
	if(p == 1) return 0;
	return fpow(2,solve(phi[p])+phi[p],p);
}
signed main(){
	int T = read();
	getphi(1e7);
	while(T--){
		ll p = read(); mod = p;
		cout << solve(p)<<"\n";
	}
	return 0;
} 
