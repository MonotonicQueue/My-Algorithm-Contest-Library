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
const int N = 1e5+10;
int n,m,a[N];
void solve(){
    n = read(); m = 0;
    for(int i=1;i*i<=n;i++){
        if(n % i == 0){
            a[++m] = i;
            if(i*i != n) a[++m] = n/i;
        }
    }
    sort(a+1,a+1+m);
    ll ans = 1;
    for(int i=1;i<m;i++)
        ans += 1ll*(n/a[i])*(a[i+1]-a[i]);
    cout << ans << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
