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

void solve(){
	ll n = read(),d = 0,ans = 0;
	ll m = n;
	while(m >= 10) m /= 10,d++;
	ll t = 0,k = 0;
	for(int i=1;i<=d;i++){
		ans += t;
		t = t*10+5; k = k*10+4;
	}
	k = k*10+4;
	if(m >= 5) ans += t;
	else if(m == 4) ans += max(n-k,0ll);
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
