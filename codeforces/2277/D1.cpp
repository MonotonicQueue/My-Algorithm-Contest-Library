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
const int N = 10100;
const int mod = 998244353;
ll sss[101000];
ll calc(ll x){
    ll ans = 9e18;
    int sum = 0,cnt = 0,c = 0;
    for(int i=61;~i;i--){
        bool flag = true;
        if((x >> i) & 1){
            if(i == 0) sum += 1;
            if(i == 1) sum += 3;
            if(i >= 2) sum += i+1,cnt += 2;
            x ^= (1ll<<i);
        }
        ll y = (1ll<<i)-x-1-cnt;
        // cerr << x << " " << y << "\n";
        if(y >= 0) ans = min(ans,sum+y+i);
        else ans = min(ans,sum+sss[-y+1]+1+i);
    }
    return ans;
}
void solve(){
    ll l = read(),r = read();
    ll ans = 0;
    for(ll i=l;i<=r;i++){
        ans += calc(i);
    }
    cout << ans%mod << "\n";
}
int main(){
    // freopen("1.out","w",stdout);
    for(int i=1;i<=300;i++) sss[i] = calc(i);
    int T = read();
    while(T--) solve();
    
    return 0;
}