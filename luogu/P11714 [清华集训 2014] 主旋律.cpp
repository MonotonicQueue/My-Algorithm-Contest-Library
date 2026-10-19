#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 20;
const int S = 1<<15;
const int mod = 1e9+7;
int n,m,G[N];
ll f[S],g[S],pw[N*N];
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u-1] |= 1<< (v-1);
	}
	pw[0] = 1;
	for(int i=1;i<=m;i++) pw[i] = pw[i-1]*2%mod;
	auto E = [&](int S,int T){
		int cnt = 0;
		for(int i=0;i<n;i++)
			if((S >> i) & 1) cnt += __builtin_popcount(T&G[i]);
		return cnt;
	};
	for(int s=0;s<(1<<n);s++){
		g[s] = pw[E(s,s)];
		for(int t=(s-1)&s;t;t=(t-1)&s)
			g[s] = (g[s]+mod-g[t]*pw[E(s,s^t)]%mod)%mod;
	}
	for(int s=0;s<(1<<n);s++){
		f[s] = g[s];
		for(int t=(s-1)&s;t;t=(t-1)&s)
			if((t & (-t)) == (s & (-s)))
				f[s] = (f[s]+f[t]*g[s^t])%mod;
	}
	cout << f[(1<<n)-1];
	return 0;
}