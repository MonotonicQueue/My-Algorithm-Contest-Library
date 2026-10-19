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
const int N = 1<<20;
const int mod = 998244353;
const int g = 3,gi = 332748118;
int n,rev[N],limit;
ll F[N],G[N];
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
void NTT(ll *A,int type){
	for(int i=1;i<limit;i++)
		if(i < rev[i]) swap(A[i],A[rev[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		ll gn = fpow(type ? g : gi,(mod - 1)/(mid << 1));
		for(int len=mid<<1,j=0;j<limit;j+=len){
			ll g0 = 1;
			for(int i=0;i<mid;i++){
				ll A0 = A[i+j],A1 = g0*A[i+j+mid]%mod;
				A[i+j] = (A0+A1)%mod;
				A[i+j+mid] = (A0-A1+mod)%mod;
				g0 = g0*gn%mod; 
			}
		}
	}
	if(!type){
		ll inv = fpow(limit,mod-2);
		for(int i=0;i<=limit;i++) A[i] = A[i]*inv%mod;
	}
}
ll c[N];
void polyinv(int deg,ll *A,ll *B){
	if(deg == 1){
		B[0] = fpow(A[0],mod-2);
		return ;
	}
	polyinv((deg+1)>>1,A,B);
	limit = 1; int l = 0;
	while(limit < (deg<<1)) limit <<= 1,l++;
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i&1) << (l-1));
	for(int i=0;i<deg;i++) c[i] = A[i];
	for(int i=deg;i<limit;i++) c[i] = 0;
	NTT(c,1); NTT(B,1);
	for(int i=0;i<limit;i++)
		B[i] = (2ll-c[i]*B[i]%mod+mod)%mod*B[i]%mod;
	NTT(B,0);
	for(int i=deg;i<limit;i++) B[i] = 0;
}
int main(){
	n = read();
	for(int i=0;i<n;i++) F[i] = read();
	polyinv(n,F,G);
	for(int i=0;i<n;i++) cout << G[i] << " ";
	return 0;
}