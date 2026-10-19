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
int n,a[N],b[N];
ll cnt[N],sum[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		a[n+1] = a[1];
		ll ans = 1e18;
		for(int i=1;i<=n;i++){
			if(a[i] < a[i+1]) b[i] = 0;
			else b[i] = 1;
		}
		for(int i=1;i<n;i++) b[i+n] = b[i];
		for(int i=1;i<2*n;i++)
			cnt[i] = cnt[i-1]+b[i],sum[i] = sum[i-1]+b[i]*i;
		int len = (n+1)/2;
		for(int i=1;i<=n;i++){
			ll sz1 = cnt[i+len-1]-cnt[i-1],sz2 = cnt[i+n-1]-cnt[i+len-1];
			ll ct1 = sum[i+len-1]-sum[i-1],ct2 = sum[i+n-1]-sum[i+len-1];
			sz1 = (i+i+sz1-1)*sz1/2; sz2 = (i+n-1-sz2+1+i+n-1)*sz2/2;
			ans = min(ans,ct1-sz1+sz2-ct2);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
