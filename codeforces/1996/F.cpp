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
ll n,k;
ll a[N],b[N];
ll chk(ll x){
    ll res = 0;
    for(int i=1;i<=n;i++){
        if(a[i] < x) continue;
        res += (a[i]-x)/b[i]+1;
    }
    return res;
}
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[i] = read();
        ll l = 0,r = 1e9,pos = 0;
        while(l <= r){
            ll mid = (l+r) >> 1;
            if(chk(mid) >= k) pos = mid,l = mid+1;
            else r = mid-1;
        }
        // cout << pos << "\n";
        ll ans = (k-chk(pos+1))*pos;
        // cout << ans << "\n";
        pos++;
        for(int i=1;i<=n;i++){
            if(a[i] < pos) continue;
            ll x = (a[i]-pos)/b[i];
            ll y = a[i]-x*b[i];
            ans += (a[i]+y)*(x+1)/2;
        }
        cout << ans << "\n";
    }
	return 0;
}
