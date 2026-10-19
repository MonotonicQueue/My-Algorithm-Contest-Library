#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int mod = 1e9+7;
const ll  rt2 = 59713600;
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
ll n;
int main(){
    char ch = getchar();
    while(isdigit(ch)) n = (n*10+ch-'0')%(mod-1),ch = getchar();
    ll ans = (fpow(1+rt2,n)-fpow(1-rt2,n)+mod)%mod*rt2%mod*fpow(4,mod-2)%mod;
    cout << ans;
    return 0;
}