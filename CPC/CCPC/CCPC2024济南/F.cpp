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
const int N = 1e5+10;
const int mod = 998244353;
ll fac[N],inv[N];
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
void init(int n = 1e5){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    if(x < y || y < 0) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m;
map<int,int> mp[N];
void solve(){
    n = read(); m = read();
    ll ans = C(n,m)*m%mod;
    for(int i=1;i<=n;i++){
        int sum = n/i;
        mp[i][0]++;
        for(auto [x,y] : mp[i]){
            ans = (ans-C(sum-1,m-x-1)*y%mod+mod)%mod;
            for(int j=i+i;j<=n;j+=i) mp[j][x+1] += y;
        }
    }
    cout << ans;
}
int main(){
    init();
    int T = 1;
    while(T--) solve();
	return 0;
}