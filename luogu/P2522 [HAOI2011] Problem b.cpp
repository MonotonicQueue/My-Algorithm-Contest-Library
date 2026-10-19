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
int T;
int a,b,c,d,k;
int mu[N],prime[N],tot; bool vis[N];
void get_mu(int n){
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
			else mu[i*prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=n;i++) mu[i] += mu[i-1];
}
int calc(int a,int b){
	int ans = 0;
	for(int l=1,r;l<=min(a,b);l=r+1){
		r = min(a/(a/l),b/(b/l));
		ans += ((mu[r]-mu[l-1])*(a/k/l)*(b/k/l));
	}
	return ans;
}
int main(){
	get_mu(5e4);
	T = read();
	while(T--){
		a = read(); b = read();
		c = read(); d = read(); k = read();
		cout << calc(b,d)-calc(b,c-1)-calc(a-1,d)+calc(a-1,c-1) << "\n";
	}
	return 0;
}