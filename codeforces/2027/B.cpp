#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n;
int a[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	ll ans = 1e18;
	for(int i=1;i<=n;i++){
		ll sum = i-1;
		for(int j=i+1;j<=n;j++)
			sum += a[i] < a[j];
		ans = min(ans,sum);
	}	
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 
