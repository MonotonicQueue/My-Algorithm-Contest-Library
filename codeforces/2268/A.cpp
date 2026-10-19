#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
int n,k,a[N];
ll sum[N];
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int d = min(k-1,n-k+1);
    ll ans = 0;
    for(int i=1;i<=d;i++) ans += max(a[i],a[n-i+1]);
    if(n >= 2*k-2)
        for(int i=k;i<=n-k+1;i++) ans += a[i];
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

