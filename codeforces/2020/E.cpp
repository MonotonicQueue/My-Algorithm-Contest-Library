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
const int mod = 1e9+7;
int n,a[N],p[N];
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
ll f[1024],g[1024];
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) p[i] = read();
    f[0] = 1;
    for(int i=1;i<=1023;i++) f[i] = 0;
    ll inv10000 = fpow(10000,mod-2);
    for(int i=1;i<=n;i++) p[i] = p[i]*inv10000%mod;
    for(int i=1;i<=n;i++){
        for(int j=0;j<1024;j++) g[j] = 0;
        for(int j=0;j<1024;j++){
            add(g[j^a[i]],f[j]*p[i]%mod);
            add(g[j],f[j]*(mod+1-p[i])%mod);
        }
        for(int j=0;j<1024;j++) f[j] = g[j];
    }
    ll ans = 0;
    for(int i=0;i<=1023;i++)
        add(ans,1ll*i*i*f[i]%mod);
    cout << ans%mod << "\n";   
}
/*
1
2
1 1
1000 2000
*/
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
