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
ll n,a[N];
ll sum,mx,pos;
bool chk(ll mid){
    a[pos] += mid; sum += mid;
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(a[i]*n*2 < sum) cnt++;
    
    a[pos] -= mid; sum -= mid;
    // cout << mid << " " << cnt << " " << sum << "\n";
    return cnt*2 > n;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sum = 0,mx = 0,pos = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
        if(a[i] > mx) mx = a[i],pos = i;
    }
    ll l = 0,r = 1e18,res = -1;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) r = mid-1,res = mid;
        else l = mid+1;
    }
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
