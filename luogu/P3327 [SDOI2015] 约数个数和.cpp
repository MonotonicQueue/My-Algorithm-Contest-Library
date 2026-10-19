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
const int N = 5e4+5;
int mu[N],prime[N],tot,s[N];
ll h[N];
bool vis[N];
void init(){
	int n = 5e4;
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			mu[i] = -1;
			prime[++tot] = i;
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			vis[i*prime[j]] = 1;
			if(i%prime[j] == 0) break;
			mu[i*prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=n;i++) mu[i] += mu[i-1];
	for(int i=1;i<=n;i++){
		ll ans = 0;
		for(int l=1,r;l<=i;l=r+1){
			r = i/(i/l);
			ans += (r-l+1)*(i/l);
		}
		h[i] = ans;
	}
} 
int main(){
	init();
	int T = read();
	while(T--){
		int n,m;
		ll ans=0;
		n = read(); m = read();
		for(int l=1,r;l<=min(n,m);l=r+1){
			r = min(n/(n/l),m/(m/l));
			ans+=(mu[r]-mu[l-1])*1ll*h[n/l]*h[m/l];
		}
		cout << ans << "\n";
	}
	return 0;
}