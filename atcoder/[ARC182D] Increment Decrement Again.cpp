#include<bits/stdc++.h>
#define int ll
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
int n,m;
ll a[N],b[N],c[N];
bool chk(){
    for(int i=1;i<=n;i++)
        if(a[i] != b[i]) return false;
    return true;
}
signed main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    if(m == 2) return puts(chk() ? "0" : "-1"),0;
    c[1] = b[1];
    for(int i=2;i<=n;i++){
        ll val = (b[i]-b[i-1]+m)%m;
        if(a[i] > a[i-1]) c[i] = c[i-1]+val;
        else c[i] = c[i-1]+val-m;
    }
    for(int i=1;i<=n;i++) c[i] = c[i]-a[i];
    sort(c+1,c+1+n);
    ll mid = c[(n+1)/2]/m,ans = 1e18;
    for(ll i=mid-3;i<=mid+3;i++){
        ll sum = 0;
        for(int j=1;j<=n;j++) sum += abs(c[j]-i*m);
        ans = min(ans,sum);
    }
    cout << ans;
    return 0;
}
