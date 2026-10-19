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
const int N = 1e6+10;

void solve(){
    ll x = read(),m = read(),ans = 0;
    for(ll i=1;i<=min(2*x,m);i++){
        ll z = i^x;
        ans += (i != x && ((x % z == 0) || (i % z == 0)));
    }
    cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}