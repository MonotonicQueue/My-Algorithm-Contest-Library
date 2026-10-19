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
int a,b,d;
int mu[N],tot,prime[N]; bool vis[N];
void get_mu(int n){
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			prime[++tot] = i;
			mu[i] = -1;
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			vis[i*prime[j]] = 1;
			if(i%prime[j] == 0) break;
			mu[i*prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=n;i++) mu[i] += mu[i-1];
}
int calc(int n,int m){
	int sum = 0;
	for(int l=1,r;l<=min(n,m);l=r+1){
		r = min(n/(n/l),m/(m/l));
		sum += (mu[r]-mu[l-1])*(n/l/d)*(m/l/d);
	}
	return sum;
}
int main(){
	get_mu(5e4);
	int T = read();
	while(T--){
		a = read(); b = read(); d = read();
		cout << calc(a,b) << "\n";
	}
	return 0;
}