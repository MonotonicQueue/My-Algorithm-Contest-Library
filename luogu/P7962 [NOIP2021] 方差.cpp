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
const int N = 1e4+10;
const ll inf = 1e14;
int n;
ll a[N],b[N],sum[N],mx;
ll f[N*55],g[N*55];
signed main(){
    // freopen("variance.in","r",stdin);
    // freopen("variance.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    mx = a[n];
    for(int i=1;i<=n-1;i++) b[i] = a[i+1]-a[i];
    for(int i=1;i<=n*mx;i++) f[i] = inf;
    sort(b+1,b+n);
    ll sum = 0;
    for(int i=1;i<n;i++){
        sum += b[i];
        if(b[i] == 0) continue;
        for(int j=0;j<=mx*n;j++) g[j] = inf;
        for(int j=mx*n;~j;j--){
            if(f[j] == inf) continue;
            g[j+i*b[i]] = min(g[j+i*b[i]],f[j]+i*b[i]*b[i]+2*j*b[i]);
            g[j+sum] = min(g[j+sum],f[j]+sum*sum);
        }
        for(int j=0;j<=mx*n;j++) f[j] = g[j];
    }
    ll ans = inf;
    for(int j=0;j<=mx*n;j++) ans = min(ans,n*f[j]-1ll*j*j);
    cout << ans;
    return 0;
}