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
int n,q;
int ed[N];
ll a[N],sum[N];
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read(),ed[i] = i-1;
    ed[1] = n;
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    for(int i=n+1;i<=2*n;i++) sum[i] = sum[i-1]+a[i-n];
    while(q--){
        ll l = read(),r = read();
        ll x = (l-1)/n+1,y = (r-1)/n+1,ans = 0;
        ll i = (l-1+x-1)%n+1,j = (r-1+y-1)%n+1;
        if(y-x-1 > 0) ans += (y-x-1)*sum[n];
        if(x == y){
            if(i > j) j += n;
            ans += sum[j]-sum[i-1];
        }else{
            if(x-1 < i) ans += sum[x-1+n]-sum[i-1];
            else ans += sum[x-1]-sum[i-1];
            if(y > j) ans += sum[j+n]-sum[y-1];
            else ans += sum[j]-sum[y-1];
        }
        cout << ans << "\n";
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
3 3
1 2 3
1 9
*/