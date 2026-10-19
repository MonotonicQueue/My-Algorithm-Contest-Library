#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 110;
const int mod = 10000007; 
ll n,a[N],b[N],c[N][N]; 
ll fpow(ll x,ll k){
	if(!x) return 1;
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
int num[N],k;
void init(){
	ll v = 1;
	while(v <= n){
		v *= 2; k++;
	}
	for(int i=1;i<=k;i++)
		num[i] = (n>>(i-1))&1;
	c[0][0] = c[1][0] = c[1][1] = 1; 
	for(int i=2;i<=k;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = c[i-1][j]+c[i-1][j-1];
	}
	a[1] = a[0] = 1;
	for(int i=2;i<=k;i++){
		a[i] = a[i-1]; b[i] = 1;
		for(int j=1;j<i;j++){
		//	cout << fpow(j+1,c[i-1][j]) << " ";
			b[i] = (b[i]*fpow(j+1,c[i-1][j])%mod);
		}
		a[i] = a[i]*b[i]%mod;
		//cout << endl;
	}
}
int main() {

	n = read();
	if(n == 1){
		cout << 1;
		return 0;
	}
	init();
	//for(int i=1;i<=k;i++) cout << a[i] <<" ";
	ll ans = a[k-1],cnt = 1;
	for(int i=k-1;i>=1;i--){
		if(!num[i]) continue;
		for(int j=0;j<i;j++)
			ans = ans*fpow(j+cnt,c[i-1][j])%mod;
		cnt++;
	}
	ans = ans*cnt%mod;
	cout << ans;
	return 0;
}