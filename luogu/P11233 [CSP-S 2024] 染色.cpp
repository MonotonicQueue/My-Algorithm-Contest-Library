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
const int N = 2e5+10;
const int M = 1e6+10;
const ll inf = 1e18;
int n,a[N];
ll f[M];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    ll mx = 0,sum = 0;
    for(int i=1;i<=1000000;i++) f[i] = -inf;
    for(int i=1;i<=n;i++){
        if(a[i] == a[i-1]){
            sum += a[i];
            continue;
        }
        f[a[i-1]] = max(f[a[i-1]],max(mx,f[a[i]]+a[i]));
        mx = max(mx,f[a[i-1]]);
    }
    cout << mx+sum << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
