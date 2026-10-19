#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,a[N];
void solve(){
	n = read();
	int ans = 0;
	for(int i=1;i<=n;i++){
		a[i] = read();
		ans = max(ans,a[i]);
	}
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}