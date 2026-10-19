#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
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
int n,m,a[N],b[N];
bool chk(int mid){
    for(int i=1;i<=n;i++) b[i] = a[i] >= mid;
    for(int i=n,j=1e9;i;i--){
        if(b[i]) j = i;
        else if(j-i > m && i <= n-m) return false;
    }
    return true;
}
signed main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int l = 1,r = 1e9,res = 0;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) res = mid,l = mid+1;
        else r = mid-1;
    }
    cout << res;
    return 0;
}
