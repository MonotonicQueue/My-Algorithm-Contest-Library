#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
ll n,a,b,c;
ll sum[N];
int l,r;
ll q[N],dp[N];
ll calc(int x){
	return dp[x]+a*sum[x]*sum[x];
}
int main(){
	n = read();
	a = read(); b = read(); c = read();
	for(int i=1;i<=n;i++){
		int x = read();
		sum[i] = sum[i-1]+x;
	}
	l = r = 1; q[1] = 0;
	for(int i=1;i<=n;i++){
		ll k = 2*a*sum[i]+b;
		while(l < r && (calc(q[l])-calc(q[l+1]))*1.0/(sum[q[l]]-sum[q[l+1]]) >= k) l++;
		dp[i] = calc(q[l])-k*sum[q[l]]+a*sum[i]*sum[i]+b*sum[i]+c;
		while(l < r && (calc(q[r])-calc(q[r-1]))*1.0/(sum[q[r]]-sum[q[r-1]]) <= (calc(i)-calc(q[r]))*1.0/(sum[i]-sum[q[r]])) r--;
		q[++r] = i;
	}
	cout << dp[n]; 
	return 0;
}