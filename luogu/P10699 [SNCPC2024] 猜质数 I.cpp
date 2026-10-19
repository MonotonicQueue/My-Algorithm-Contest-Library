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
const int N = 60;
int n,k;
ll a[N],b[N];
ll fpow(ll x,ll k,ll mod){
    ll res = 1;
    while(k){
        if(k & 1)
            res = (__int128)res*x%mod;
        x = (__int128)x*x%mod;
        k >>= 1;
    }
    return res;
}
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++){
        a[i] = 1ll<<i;
        cout << a[i] << endl;
        b[i] = read()%9;
    }
    cout << "36\n";
    for(int i=1;i<=n;i++){
        ll p = 36*a[i]; a[i] = a[i]*4;
        ll inv2 = fpow(a[i],5,9);
        ll inv9 = fpow(9,a[i]/2-1,a[i]);
        ll ans = (__int128)b[i]*a[i]%p*inv2%p+(__int128)9*inv9%p;
        ans %= p;
        cout << ans << " ";
    }
    cout << endl;
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}