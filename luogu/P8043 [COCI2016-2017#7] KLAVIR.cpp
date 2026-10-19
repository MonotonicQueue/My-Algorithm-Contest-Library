#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 110;
const int mod = 1e9+7;
const int M = 1e6+10;
int n,m,a[M],fail[M];
ll f[M],g[M];
signed main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++) a[i] = read();
	for(int i=2,j=0;i<=m;i++){
		while(j && a[j+1] != a[i]) j = fail[j];
		if(a[j+1] == a[i]) j++;
		fail[i] = j;
	}
	// for(int i=1;i<=m;i++) cout << fail[i] << " ";
	// cout << "\n";
	f[1] = n;
	for(int i=2;i<=m;i++){
		g[i-1] = (g[fail[i-1]]-f[fail[i]]+f[fail[i-1]+1]+mod)%mod;
		f[i] = ((f[i-1]+1)*n-g[i-1]+mod)%mod;
	}
	for(int i=1;i<=m;i++) cout << f[i] << "\n";
	return 0;
}