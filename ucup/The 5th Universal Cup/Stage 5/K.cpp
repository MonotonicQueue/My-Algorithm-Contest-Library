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
int n;
ll a[N],b[N];
bool chk(ll x){
    ll l1 = a[1]-x,r1 = a[1]-x,l2 = a[1]-x,r2 = a[1]+x;
    for(int i=2;i<=n;i++){
        ll r = r2-b[i],l = l1+b[i];
        ll L = a[i]-x,R = a[i]+x;
        if(L > r && R < l) return false;
        if(R < l){
            r1 = l2 = r2 = min(r,R);
            l1 = L;
        }else if(L > r){
            l1 = r1 = l2 = max(L,l);
            r2 = R;
        }else{
            l1 = L; r1 = r;
            l2 = l; r2 = R;
        }
    }
    return true;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=2;i<=n;i++) b[i] = read();
    ll l = 0,r = 1e16,res = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) res = mid,r = mid-1;
        else l = mid+1;
    }
    cout << res << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
