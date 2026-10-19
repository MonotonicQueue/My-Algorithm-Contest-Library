#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;;
int n,k,a[N],b[N],mx[N];
void solve(){
	n = read(); k = read();
	for(int i=1;i<=k;i++) mx[i] = 0;
	for(int i=1;i<=k;i++){
		a[i] = read(); b[i] = read();
		mx[a[i]] += b[i];
	}
	ll ans = 0;
	sort(mx+1,mx+1+k);
	for(int i=k;i>=max(1,k-n+1);i--) ans += mx[i];
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}