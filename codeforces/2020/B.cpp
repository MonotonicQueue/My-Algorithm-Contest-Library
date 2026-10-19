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
const int N = 1e6+10;
ll k;
void solve(){
    k = read();
    ll l = 1,r = 2e18,res = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        ll s = sqrt(mid);
        if(s*s > mid) s--;
        if(mid-s >= k) res = mid,r = mid-1;
        else l = mid+1;
    }
    cout << res << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
