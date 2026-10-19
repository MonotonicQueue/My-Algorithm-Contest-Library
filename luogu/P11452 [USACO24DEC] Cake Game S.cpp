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
const int N = 5e5+10;
int n;
ll a[N],sum[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1]+a[i];
	ll ans2 = 0; int len = n/2+1;
	for(int i=0;i+len<=n;i++) ans2 = max(ans2,sum[n]-(sum[i+len]-sum[i]));
	cout << sum[n]-ans2 << " " << ans2 << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
