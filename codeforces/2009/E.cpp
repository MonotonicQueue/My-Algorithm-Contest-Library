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
ll n,k;
ll calc(ll x){
    return abs((2*k+x-1)*x/2-(2*k+n+x-1)*(n-x)/2);
}
void solve(){
    n = read(); k = read();
    ll l = 1,r = n,res = 1e18;
    while(l <= r){
        ll mid1 = (2*l+r)/3,mid2 = (l+2*r)/3;
        if(calc(mid1) < calc(mid2)) r = mid2-1;
        else l = mid1+1;
    }
    for(ll i=max(1ll,l-10);i<=min(n,l+10);i++) res = min(res,calc(i));
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
