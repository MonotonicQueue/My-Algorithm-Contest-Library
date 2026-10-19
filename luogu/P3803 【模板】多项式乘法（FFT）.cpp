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
const int N = 1<<22;
const int mod = 998244353;
const int g = 3,gi = 332748118;
//gi: g_inv mod 998244353

int n,m,limit,l;
ll F[N],G[N],rev[N];
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
int main(){
	n = read(); m = read();
	for(int i=0;i<=n;i++) F[i] = read();
	for(int i=0;i<=m;i++) G[i] = read();
	limit = 1;
	while(limit <= n+m) limit <<= 1,l++;
	for(int i=0;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	NTT(F,1); NTT(G,1);
	for(int i=0;i<=limit;i++) F[i] = F[i]*G[i];
	NTT(F,0);
	for(int i=0;i<=n+m;i++) cout << F[i] << " "; 
	return 0;
}