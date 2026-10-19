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
int n,k,a[N];
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n,greater<int>());
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i & 1) ans += a[i];
        else{
            if(a[i]+k <= a[i-1]) ans -= a[i]+k,k = 0;
            else ans -= a[i-1],k -= a[i-1]-a[i];
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
