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
    int L = read(),R = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int ans = 0,l = 1,r = 0;
    ll sum = 0;
    while(l <= n && r <= n){
        while(r <= n && sum < L) sum += a[++r];
        if(r > n) break;
        if(sum <= R) ans++,l = r+1,sum = 0;
        else sum -= a[l++];
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
