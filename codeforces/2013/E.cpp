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
int n,a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    int d = 0,g = 0;
    for(int i=1;i<=n;i++) d = __gcd(a[i],d);
    ll ans = 0;
    while(g != d){
        int mn = 1e9,pos = 0;
        for(int i=1;i<=n;i++)
            if(mn > a[i] && a[i]) mn = a[i],pos = i;
        g = __gcd(g,mn);
        a[pos] = 0;
        for(int i=1;i<=n;i++) if(a[i]) a[i] = __gcd(a[i],g);
        ans += g;
    }
    for(int i=1;i<=n;i++)
        if(a[i]) ans += d;
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
