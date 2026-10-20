#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int mod = 1e9+7;
ll fpow(ll x,ll k){
    ll res = 1;
    x %= mod;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
void solve(){
    ll n = read();
    cout << fpow(n+1,n-1) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}