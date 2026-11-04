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
const int N = 2e5+10;
int n,a[N];
char c[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++)
		cin >> a[i] >> c[i];
	int l = 1,r = n;
	ll ans = 0;
	while(l < r){
		int mn = min(a[l],a[r]);
		if(c[l] != c[r]) ans += mn;
		a[l] -= mn; a[r] -= mn;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout << ans << "\n";
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
