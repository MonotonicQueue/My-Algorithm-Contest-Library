#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 999911659;
int n,q;
ll a[5],f[50010][5],p[5] = {0,2,3,4679,35617};
inline void init(){
	for(int i=1;i<=4;i++){
		f[0][i] = 1;
		for(int j=1;j<=p[i];j++){
			f[j][i] = f[j-1][i]*j%p[i];
		}
	}
		
}
inline ll S(int x){//search
	if(x == 2) return 1;
	if(x == 3) return 2;
	if(x == 4679) return 3;
	return 4;
}
inline ll inv(int x,int y,int m){//费马小定理求逆元 
	ll ans = 1 , base = x;
	while(y){
		if(y&1)
			ans = ans*base%m;
		base = base*base%m;
		y >>= 1;
	}
	return ans;
}
inline ll C(int x,int y,int m){
	if(y < x) return 0;
	return f[y][S(m)]*inv(f[x][S(m)],m-2,m)*inv(f[y-x][S(m)],m-2,m)%m;
}
inline ll Lucas(int x,int y,int m){
	if(!y) return 1; if(x > y) return 0;
	return Lucas(x/m,y/m,m)*C(x%m,y%m,m)%m;
}
inline ll CRT(){
	ll M = mod-1,ans = 0;
	for(int i=1;i<=4;i++)
		ans = (ans+M/p[i]*inv(M/p[i],p[i]-2,p[i])*a[i])%M;
	return ans;
}
int main(){
	cin >> n >> q;
	if(q == mod){
		cout << 0;
		return 0;
	}
	init();
	for(int i=1;i*i<=n;i++){
		if(n % i == 0){
			for(int j=1;j<=4;j++){
				a[j] = (a[j]+Lucas(i,n,p[j]))%p[j];
				if(i*i != n) a[j] = (a[j]+Lucas(n/i,n,p[j]))%p[j];
			}	
		}
	}
	ll x = CRT(),base = q,ans = 1;
	while(x){
		if(x & 1)
			ans = ans*base%mod;
		base = base*base %mod;
		x >>= 1;
	}
	cout << ans;
	return 0;
}