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
const int N = 1e7+5;
const int mod = 20101009;
bool vis[N];
int mu[N],prime[N],sum[N],tot;
inline void init_mu(int n){
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i] = -1;
			prime[++tot] = i;
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			vis[i*prime[j]] = 1;
			if(i%prime[j] == 0) break;
			mu[i*prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=n;i++) sum[i] = (mu[i]*i%mod+mod)%mod; 
	for(int i=1;i<=tot;i++)
		for(int j=1;j*prime[i]<=n;j++) sum[j*prime[i]] = (sum[j*prime[i]]+sum[j])%mod;
	for(int i=1;i<=n;i++) sum[i] = (sum[i-1]+1ll*sum[i]*i%mod)%mod;
//	for(int i=1;i<=10;i++) cout << sum[i] << " ";
}
inline int g(int x,int y){
	return (1ll*x*(x+1)/2%mod)*(1ll*y*(y+1)/2%mod)%mod;
}

int main(){
	init_mu(1e7);
	int n = read(),m = read();
	int ans = 0;
	if(n > m) swap(n,m);
	for(ll l=1,r;l<=n;l=r+1){
		r = min(n/(n/l),m/(m/l));
		ans = (ans+1ll*g(n/l,m/l)%mod*(sum[r]-sum[l-1]+mod)%mod)%mod;
	}
	cout << ans << "\n";


	return 0;
}