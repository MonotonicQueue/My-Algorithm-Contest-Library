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
int n,c[N];
void solve(){
    n = read();
    int a = read(),b = read();
    int d = __gcd(a,b);
    for(int i=1;i<=n;i++){
        c[i] = read();
        c[i] %= d;
    }
    sort(c+1,c+1+n);
    n = unique(c+1,c+1+n)-c-1;
    int ans = c[n]-c[1];
    for(int i=1;i<n;i++)
        ans = min(ans,c[i]+d-c[i+1]);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
