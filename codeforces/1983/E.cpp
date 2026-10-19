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
const int N = 5e5+10;
const int mod = 1e9+7;
int n,k,a[N];
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
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) a[i] = read();
        ll sum1 = 0,sum2 = 0,ans = 0;
        for(int i=k+1;i<=n;i++) sum1 = (sum1+a[i])%mod;
        ans = (ans+sum1*((n-k+1)/2)%mod*fpow(n-k,mod-2)%mod)%mod;
        for(int i=1;i<=k;i++) sum2 = (sum2+a[i])%mod;
        // cout << sum2*(n-k+2)/2 << "\n";
        ans = (ans+sum2*((n-k+2)/2)%mod*fpow(n-k+1,mod-2)%mod)%mod;
        sum2 = (sum2+sum1)%mod;
        cout << ans << " " << (sum2-ans+mod)%mod << "\n";
    }
	return 0;
}
