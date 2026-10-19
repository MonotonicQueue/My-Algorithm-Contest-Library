#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n,p,m,a[N];
char b[N];
int Z[N];
inline void exkmp(){
	Z[1] = m;
	for(int i=2,l=0,r=0;i<=m;i++){
		if(i <= r) Z[i] = min(Z[i-l+1],r-i+1);
		while(i+Z[i]-1 <= m && b[1+Z[i]] == b[i+Z[i]]) Z[i]++;
		if(i+Z[i]-1 > r) r = i+Z[i]-1,l = i;
	}
}
const int mod = 1e9+7;
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
inline void work(){
	exkmp();
	sort(a+1,a+1+p);
	int cnt = 0,r = 0;
	for(int i=1;i<=p;i++){
		if(a[i] <= r){
			if(Z[m-r+a[i]] != r-a[i]+1){
				puts("0");
				return ;
			}
		}else cnt += a[i]-r-1;
		r = a[i]+m-1;
	}
	if(r > n) puts("0");
	else cout << fpow(26,cnt+n-r) << "\n";
}
int main(){
	n = read(); p = read();
	scanf("%s",b+1); m = strlen(b+1);
	for(int i=1;i<=p;i++) a[i] = read();
	work();
	return 0;
}