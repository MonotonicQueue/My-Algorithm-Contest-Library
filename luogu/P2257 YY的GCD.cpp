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
const int N = 1e7+10;
int pr[N/10],mu[N],sum[N],cnt;
bool vis[N];
inline void init(int n){
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			pr[++cnt] = i;
			mu[i] = -1;
		}
		for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
			vis[i*pr[j]] = 1;
			if(i % pr[j] == 0) break;
			mu[i*pr[j]] = -mu[i];
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j*pr[i]<=n;j++) sum[j*pr[i]] += mu[j];
	for(int i=1;i<=n;i++) sum[i] += sum[i-1]; 
} 
int main(){
	init(1e7);
	int T = read();
	while(T--){
		ll n = read(),m = read();
		if(n > m) swap(n,m);
		ll ans = 0;
		for(ll l=1,r;l<=n;l=r+1){
			r = min(n/(n/l),m/(m/l));
			ans += (n/l)*(m/l)*(sum[r]-sum[l-1]);
		}
		cout << ans << "\n";
	}
	return 0;
}