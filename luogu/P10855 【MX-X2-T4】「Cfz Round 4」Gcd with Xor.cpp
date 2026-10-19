#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
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
const int N = 4e5+10;
const int mod = 1e9+7;
int n,k,l;
int t[N*30][2],cnt,sum[N*30];
void insert(int x,int d){
	int p = 1;
	for(int i=l;~i;i--){
		int c = (x >> i) & 1;
		if(!t[p][c]) t[p][c] = ++cnt;
		p = t[p][c]; sum[p] += d;
	}
}
int get(int p,int i,int x){
	int s = (1 << i),res = 0;
	// cout << i << " " << x << "\n";
	// cout<< x << " " << i << " ";
	for(i--;~i;i--){
		int c = (x >> i) & 1;
		if((n >> i) & 1){
			s += (1<<i);
			res += sum[t[p][c]];
			p = t[p][c^1];
		}else p = t[p][c];
	}
	res += sum[p];
	// cout << res << "\n";
	return res;
}
int get(int x){
	int p = 1,res = 0;
	for(int i=l;~i;i--){
		int c = (x >> i) & 1,d = (n >> i) & 1;
		if(!d){
			res += sum[t[p][c^1]];
			p = t[p][c];
		}else p = t[p][c^1];
	}
	return res;
}
int ask(int x){
	int p = 1,res = 0;
	int sss = 0;
	for(int i=l;~i;i--){
		int c = (x >> i) & 1;
		if(c == 0) res += sum[t[p][1]];
		p = t[p][0];
	}
	res += sum[p];
	return res;
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
ll s[N];
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		auto clear = [&](){
			for(int i=1;i<=cnt;i++)
				t[i][0] = t[i][1] = sum[i] = 0;
			cnt = 1;
			for(int i=1;i<=n;i++) s[i] = 0;
		};
		clear();
		l = 0;
		while((1 << l) <= n) l++;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<l);j+=i) insert(j,1);
			for(int j=i;j<=n;j+=i)
				s[i] = (s[i]+ask(j)-get(j))%mod;
			for(int j=0;j<(1<<l);j+=i) insert(j,-1);
		}
		for(int i=n;i;i--)
			for(int j=i+i;j<=n;j+=i) s[i] = (s[i]-s[j]+mod)%mod;
		ll ans = 0;
		for(int i=1;i<=n;i++) ans = (ans+fpow(i,k)*s[i]%mod)%mod;
		cout << ans << "\n";
	}
	return 0;
}
/*
1
10 1

*/