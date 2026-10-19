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

void solve(){
    ll x = read(),y = read(),z = read(),k = read();
    ll ans = 9e18;
    for(ll t=0;t*(1+t)/2*k<=z;t++){
        ll s = z-t*(1+t)/2*k;
        for(ll l,r=min((t+1)*k,s),d;r>t*k;r=l-1){
            d = (s+r-1)/r; l = max((s+d-1)/d,t*k+1);
            ans = min(ans,l*x+d*y+y*t);
        }
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
