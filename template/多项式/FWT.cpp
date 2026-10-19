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
const int N = (1<<17)+5;
const int mod = 998244353;
int n;
ll a[N],b[N],A[N],B[N];
inline void FWTOR(ll *f,ll op){
	for(int mid=1;mid<n;mid<<=1)
		for(int len=mid<<1,j=0;j<n;j+=len)
			for(int i=0;i<mid;i++)
				f[i+j+mid] = (f[i+j]*op+f[i+j+mid])%mod;
}
inline void FWTAND(ll *f,ll op){
	for(int mid=1;mid<n;mid<<=1)
		for(int len=mid<<1,j=0;j<n;j+=len)
			for(int i=0;i<mid;i++)
				f[i+j] = (f[i+j]+f[i+j+mid]*op)%mod;
}
inline void FWTXOR(ll *f,ll op){
	for(int mid=1;mid<n;mid<<=1)
		for(int len=mid<<1,j=0;j<n;j+=len)
			for(int i=0;i<mid;i++){
				ll A0 = f[i+j],A1 = f[i+j+mid];
				f[i+j] = (A0+A1)*op%mod;
				f[i+j+mid] = (A0-A1+mod)*op%mod;
			}
}
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}

void init(){
	for(int i=0;i<n;i++) A[i] = a[i],B[i] = b[i];
}
void work(){
	for(int i=0;i<n;i++) A[i] = A[i]*B[i]%mod;
}
void output(){
	for(int i=0;i<n;i++) cout << A[i] << " ";
	cout << "\n";
}
int main(){
	n = read(); n = 1<<n;
	for(int i=0;i<n;i++) a[i] = read();
	for(int i=0;i<n;i++) b[i] = read();
	init(); FWTOR(A,1); FWTOR(B,1); 
	work(); FWTOR(A,mod-1); output();
	init(); FWTAND(A,1); FWTAND(B,1); 
	work(); FWTAND(A,mod-1); output();
	init(); FWTXOR(A,1); FWTXOR(B,1); 
	work(); FWTXOR(A,fpow(2,mod-2)); output();
	return 0; 
}

