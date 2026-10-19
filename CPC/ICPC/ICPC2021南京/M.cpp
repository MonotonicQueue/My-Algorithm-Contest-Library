#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
int n;
ll a[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(n == 1){
		cout << a[1] << "\n";
		return ;
	}
	bool flag1 = false,flag2 = false;
	for(int i=1;i<=n;i++) flag1 |= a[i] <= 0,flag2 |= a[i] >= 0;
	if(flag1 && flag2){
		ll ans = 0;
		for(int i=1;i<=n;i++) ans += abs(a[i]);
		cout << ans << "\n";
	}else if(flag2){
		ll mn = 1e18,ans = 0;
		for(int i=1;i<=n;i++) mn = min(mn,a[i]);
		for(int i=1;i<=n;i++) ans += a[i];
		cout << ans-2*mn << "\n";
	}else{
		ll mx = -1e18,ans = 0;
		for(int i=1;i<=n;i++) mx = max(mx,a[i]);
		for(int i=1;i<=n;i++) ans -= a[i];
		cout << ans+2*mx << "\n";
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
