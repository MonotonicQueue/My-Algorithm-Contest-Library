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
const int N = 1e6+10;
ll n,k,a[N];
int cnt[N];
bool chk(){
	for(int i=0;i<k;i++)
		if(cnt[i] && cnt[i+k]) return true;
	return false;
}
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		for(int i=0;i<=2*k;i++) cnt[i] = 0;
		ll x = 0;
		ll mx = 0;
		for(int i=1;i<=n;i++){
			a[i] = read();
			mx = max(mx,a[i]);
			x = max(x,a[i]/(2*k));
			a[i] %= 2*k;
			cnt[a[i]]++;
		}
		int sum = 0;
		if(chk()) puts("-1");
		else{
			ll ans = x*2*k;
			for(int i=0;i<=4*k;i++){
				sum += cnt[i%(2*k)];
				if(i >= k) sum -= cnt[(i-k)%(2*k)];
				if(sum == n){
					if(mx % (2*k) < k) ans = ans+i%(2*k);
					else ans = ans+i;
					break;
				}
			}
			if(sum == n) cout << ans << "\n";
			else cout << "-1\n";
		}
	}
	return 0;
}
