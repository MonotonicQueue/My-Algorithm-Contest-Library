#include<bits/stdc++.h>
#define ll __int128
#define LL long long
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
const ll inf = 1e18;
ll n,k;
__int128 fpow1(__int128 x,ll k){
    __int128 res = 1;
	if(x > inf) return inf+1;
    while(k){
        if(k & 1)
            res = res*x;
        x = x*x;
		x = min(x,inf+1);
		res = min(res,inf+1);
        k >>= 1;
    }
    return res;
}
__int128 fpow(__int128 x,ll k){
    __int128 res = 1;
    while(k){
        if(k & 1)
            res = res*x;
        x = x*x;
        k >>= 1;
    }
    return res;
}
ll get(){
    ll l = 1,r = n,res = 1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(fpow1(mid,k) >= n) res = mid,r = mid-1;
        else l = mid+1;
    }
    return res;
}
bool get2(ll x,ll n,ll k){
    ll l = 1,r = x,res = -1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(fpow1(mid,k) <= n) res = mid,l = mid+1;
        else r = mid-1;
    }
    return fpow1(res,k) == n;
}
void solve(){
    n = read(); k = read();
    long long ans = 0;
	for(LL i=1;fpow(i,k)<=n;i++){
		if(n % i != 0) continue;
		ll l = 1,r = ceil(pow((LL)n,1.0/(k-1))),res = 1;
		while(l <= r){
			ll mid = (l+r) >> 1;
			if(fpow(i+mid,k)-fpow(mid,k) >= n) res = mid,r = mid-1;
			else l = mid+1;
		}
		if(fpow(i+res,k)-fpow(res,k) == n) ans++;
	}
	cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
	return 0;
}