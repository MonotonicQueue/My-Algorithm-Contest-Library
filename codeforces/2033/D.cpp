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
int n;
ll a[N],sum[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    map<ll,int> mp;
    int ans = 0,mx = 0;
    mp[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
        if(mp.count(sum[i])) mx = max(mx,mp[sum[i]]+1);
        ans = max(ans,mx);
        mp[sum[i]] = mx;
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
