#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
void solve(){
    ll w = read(),b = read();
    ll l = 0,r = 1e5,res = 0;
    auto chk = [&](ll mid){
        ll x = w,y = b;
        for(int i=mid;i;i--){
            if(x < y) swap(x,y);
            if(x < i) return false;
            x -= i;
        }
        return true;
    };
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) res = mid,l = mid+1;
        else r = mid-1;
    }
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}
