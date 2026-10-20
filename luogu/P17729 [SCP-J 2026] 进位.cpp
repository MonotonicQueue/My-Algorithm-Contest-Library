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
const int N = 5e5+10;
const int mod = 998244353;
int n,m;
ll a[N],f[N],c[N],d[N];
inline void add(ll &x,ll y){
    x = (x+y) >= mod ? x+y-mod : x+y;
}
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
void solve(){
    n = read(); m = 0;
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) d[i] = 1;
    a[0] = -1;
    for(int i=1;i<=n;i++){
        if(a[i]) c[++m] = a[i];
        else{
            if(a[i] != a[i-1]) c[++m] = a[i];
            else d[m]++;
        }
    }
    swap(n,m);
    for(int i=1;i<=n;i++) a[i] = c[i];
    for(int i=0;i<=n;i++) f[i] = 1;
    for(int i=1;i<=n;i++){
        ll cnt = 0; ll sum = a[i];
        for(int j=i+1;j<=n;j++){
            ll t = (sum & a[j]);
            ll c = __builtin_popcountll(t);
            cnt += c;
            if(cnt >= 2) break;
            if(c == 1){
                t <<= 1;
                if((sum|a[j]) & t) break;
            }
            sum += a[j];
            if(cnt == 1) add(f[j],f[i]*d[i]%mod);
        }
    }
    // for(int i=1;i<=n;i++) cout << f[i] << " ";
    // cout << "\n";
    ll ans = 0;
    for(int i=1;i<=n;i++) add(ans,f[i]*d[i]%mod);
    // ans = (ans+1)*fpow(2,m-n)-1;
    ans = (ans%mod+mod)%mod;
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
