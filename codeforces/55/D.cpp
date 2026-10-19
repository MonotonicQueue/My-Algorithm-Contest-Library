#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
int gcd(int x,int y){
	return y ? gcd(y,x%y) : x;
}
ll dp[20][2525][50];
int mp[2525],cnt;
int a[20];
ll dfs(int x,int y,int z,bool limit){
	if(!x) return y % z == 0;
	if(!limit && dp[x][y][mp[z]] != -1) return dp[x][y][mp[z]];
	int num = limit ? a[x] : 9;
	ll res = 0;
	for(int i=0;i<=num;i++)
		res += dfs(x-1,(y*10+i)%2520,i ? i*z/gcd(i,z) : z,limit&&(i==num));
	if(!limit) dp[x][y][mp[z]] = res;
	return res;
}
ll calc(ll x){
	int len = 0;
	while(x) a[++len] = x%10,x /= 10;
	return dfs(len,0,1,1);
}
signed main(){
	int T = read();
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=2520;i++) if(2520 % i == 0) mp[i] = ++cnt;
	while(T--){
		ll l = read(),r = read();
		cout << calc(r)-calc(l-1) << "\n"; 
	}
	return 0;
}
