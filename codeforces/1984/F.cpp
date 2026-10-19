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
const int N = 2e3+10;
const int mod = 998244353;
int n,m,tot;
char ch[N];
ll b[N],ans;
ll dp[N][2];
inline void work(ll sum){
	for(int i=0;i<=n+1;i++) dp[i][0] = dp[i][1] = 0;
	dp[0][0] = 1;
	for(int i=1;i<=n+1;i++){
		if(ch[i] != 'S'){
			dp[i][0] = (dp[i][0]+(abs(b[i]-b[i-1]) <= m)*dp[i-1][0])%mod;
			dp[i][0] = (dp[i][0]+(abs(b[i]+b[i-1]-sum) <= 2*m)*dp[i-1][1])%mod;
		}
		if(ch[i] != 'P'){
			dp[i][1] = (dp[i][1]+(b[i]+b[i-1] == sum)*dp[i-1][0])%mod;
			dp[i][1] = (dp[i][1]+(abs(b[i-1]-b[i]) <= m)*dp[i-1][1])%mod;
		}
	}
	ans = (ans+dp[n+1][1])%mod;
}
ll sum[N];
int main(){
	int T = read();
	while(T--){
		n = read(); m = read();
		cin >> ch+1;
		for(int i=1;i<=n;i++) b[i] = read();
		b[0] = b[n+1] = 0;
		ch[0] = 'P'; ch[n+1] = 'S';
		tot = 0;
		for(int i=1;i<=n+1;i++) sum[++tot] = b[i]+b[i-1];
		sort(sum+1,sum+1+tot);
		tot = unique(sum+1,sum+1+tot)-sum-1;
		ans = 0;
		for(int i=1;i<=tot;i++) work(sum[i]);
		cout << ans << "\n";
	}
	return 0;
}
