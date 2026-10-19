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
const int N = 1e6+10;
int n;
ll a[N],sum[N],ans;
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	ll ave = 0;
	for(int i=1;i<=n;i++) ave += a[i];
	ave /= n;
	for(int i=1;i<=n;i++) a[i] -= ave;
	for(int i=2;i<=n;i++) sum[i] = sum[i-1]+a[i-1];
	sort(sum+1,sum+1+n);
	ll x = sum[(n+1)/2];
	for(int i=1;i<=n;i++) ans += abs(sum[i]-x);
	cout << ans;
	return 0;
}