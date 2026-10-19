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
const int mod = 1e9+7;
const int N = 1e5+10;
int n,k,L,H;
ll f[N];
ll fpow(ll x,int k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
int main(){
	n = read(); k = read();
	L = read(); H = read();
	if(L % k) L = L/k+1;
	else L /= k;
	H /= k;
	if(L > H){puts("0");return 0;}
	for(int i=1;i<=H-L;i++){
		int l = L, r = H;
        if (l % i) l = l/i+1; 
		else l /= i;
		r /= i;
		if(l > r) continue;
		f[i] = (fpow(r-l+1,n)-(r-l+1)+mod)%mod;
	}
	for(int i=H-L;i;i--)
		for(int j=i*2;j<=H-L;j+=i)
			f[i] = (f[i]-f[j]+mod)%mod;
	
	
	if(L == 1) f[1] = (f[1]+1)%mod;
	cout << f[1];
	return 0;
} 