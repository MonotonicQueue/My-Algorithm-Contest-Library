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
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 1e5+10;
bool vis[N];
int pr[N],cnt;
ll mu[N],ans; 
void init(int n){
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i] = -1;
			pr[++cnt] = i;
		}
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
			vis[i*pr[j]] = 1;
			if(i % pr[j] == 0) break;
			mu[i*pr[j]] = -mu[i];
		}
	}
//	for(int i=1;i<=n;i++) cout << mu[i] << " ";
	for(int i=1;i<=n;i++) mu[i] += mu[i-1]; 
}
ll calc(ll n,ll m){
	ll res = 0;
	for(ll l=1,r=0;l<=n;l=r+1){
		r = min(n/(n/l),m/(m/l));
		res += (mu[r]-mu[l-1])*(n/l)*(m/l);
//		cout << n/l << " " << n/r << " " << m/l << " " << m/r << " " << res <<"\n"; 
	}
	return res;
}
int main(){
	ll n = read(),m = read();
	if(n > m)  swap(n,m);
	init(n);
	for(ll i=1;i<=n;i++){
//		cout << i << "\n";
		ans += i*calc(n/i,m/i);
	}
	cout << 2ll*ans-n*m;
	return 0;
}
