#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int mod = 1e9+7;
const int N = 370;
int n;
ll a[N],k,b[N],d[N];
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    map<vector<ll>,vector<pair<ll,ll>>> mp;
    for(int c=60;~c;c--){
        for(int i=1;i<=n;i++) b[i] = a[i] % (1ll<<c);
        b[0] = -1;
        sort(b+1,b+1+n);
        for(int i=1;i<=n&&a[1]>=b[i];i++){
            auto get = [&](ll l,ll r){
                if(l > r) return -1;
                if(l == 0) return 0;
                l--;
                int res = 0;
                for(int i=60;~i;i--){
                    if(((l >> i) & 1) == ((r >> i) & 1))
                        res += (l >> i) & 1;
                    else return res+1;
                }
                assert(false);
                return -1;
            };
            ll t = get(b[i-1]+1,b[i]);
            if(t == -1 || k-c-t < 0) continue;
            for(int j=1;j<=n;j++) d[j] = (a[j]-b[i]) >> c;
            vector<ll> v;
            for(int j=2;j<=n;j++) v.push_back(d[j]-d[j-1]);
            mp[v].push_back(mk(max(d[1]-(k-c-t),0ll),d[1]));
        }
    }
    ll ans = 0;
    for(auto &[U,V] : mp){
        vector<pair<ll,ll>> v = V;
        sort(v.begin(),v.end());
        int len = v.size();
        ll l = 0,r = -1;
        for(int i=0;i<len;i++){
            if(v[i].fi > r){
                ans = (ans+r-l+1)%mod;
                l = v[i].fi; r = v[i].se;
                
            }else r = max(v[i].se,r);
        }
        ans = (ans+r-l+1)%mod;
    }
    cout << ans << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}