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
const int N = 2020;
int n;
ll a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll ans = 1e18;
    sort(a+1,a+1+n);
    ll mx = 0;
    if(n & 1){
        for(int i=1;i<=n;i+=2){
            mx = 0;
            if(i & 1){
                for(int j=1;j<i;j+=2) mx = max(mx,a[j+1]-a[j]);
                for(int j=i+1;j<=n;j+=2) mx = max(mx,a[j+1]-a[j]);
            }
            ans = min(ans,mx);
        }    
    }else{
        for(int i=1;i<=n;i+=2)
            mx = max(mx,a[i+1]-a[i]);
        ans = mx;
    }
    ans = max(ans,1ll);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
