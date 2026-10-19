#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
int n;
pii a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i].fi = read();
        a[i].se = read();
    }
    sort(a+1,a+1+n);
    ll sum = 0;
    for(int i=1;i<=n;i++) sum += a[i].se;
    ll now = sum/2,ans = 0;
    for(int i=1;i<=n;i++){
        ans -= min(now,a[i].se)*a[i].fi;
        if(a[i].se <= now) now -= a[i].se,a[i].se = 0;
        else a[i].se -= now,now = 0;
    }
    now = sum/2;
    for(int i=n;i>=1;i--){
        ans += min(now,a[i].se)*a[i].fi;
        if(a[i].se <= now) now -= a[i].se,a[i].se = 0;
        else a[i].se -= now,now = 0;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}