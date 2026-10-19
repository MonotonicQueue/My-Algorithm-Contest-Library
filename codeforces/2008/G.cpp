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
int n,k,a[N];
void solve(){
    n = read(); k = read();
    int d = 0;
    for(int i=1;i<=n;i++) a[i] = read(),d = __gcd(a[i],d);
    if(d == 0){
        cout << k << "\n";
        return ;
    }
    if(n == 1){
        cout << k-1+(k > a[1]) << "\n";
        return ;
    }
    int l = 0,r = n+k,res = 0;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(mid+1-min(mid/d+1,n) >= k) r = mid-1,res = mid;
        else l = mid+1;
    }
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
