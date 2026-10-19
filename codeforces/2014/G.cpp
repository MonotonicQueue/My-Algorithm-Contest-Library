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
const int N = 1e5+10;
int n,m,k;
void solve(){
    n = read(); m = read(); k = read();
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        a[i].fi = read();
        a[i].se = read();
    }
    vector<pair<ll,pii>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(a[i].fi, pii(i, 1));
        v.emplace_back(a[i].fi + k, pii(i, 0));
    }
    sort(v.begin(),v.end());
    set<int,greater<int>> s;
    ll t = 0,ans = 0;
    for (auto it : v) {
        ll nt = it.fi;
        pii eve = it.se;
        if (t < nt) {
            ll rest = 1ll*(nt-t)*m,tot = 0;
            while (!s.empty()) {
                int id = *s.begin();
                if(rest >= a[id].se){
                    rest -= a[id].se;
                    tot += a[id].se;
                    a[id].se = 0;
                    s.erase(id);
                }else{
                    tot += rest;
                    a[id].se -= rest;
                    rest = 0;
                    break;
                }
            }
            ans += tot / m;
        }
        t = nt;
        if(eve.se == 1) s.insert(eve.fi);
        else s.erase(eve.fi);
    }
    cout << ans << '\n';
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
