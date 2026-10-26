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
const ll inf = 9e18;
int n;
ll x,y;
ll a[N],b[N];
// ll calc(ll num){
//     ll res = num*x,cnt = 0;
//     for(int i=1;i<=n;i++){
//         cnt = max(0ll,cnt-(a[i]-a[i-1]));
//         if(num+cnt < b[i]){
//             res += y*(b[i]-num-cnt);
//             cnt = b[i]-num;
//         }
//     }
//     return res;
// }
/*
设m值固定

*/
void solve(){
    n = read(); x = read(); y = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        b[i] = read();
    }
    ll ans = inf,mx = 0,sum = 0;
    vector<pair<ll,bool>> v;
    for(int i=1;i<=n;i++){
        ll k = max(mx-a[i],0ll);
        sum += max(b[i]-k,0ll)*y;
        mx = max(mx,a[i]+b[i]);
        if(k >= b[i]) continue;
        v.emplace_back(k,1);
        v.emplace_back(b[i],0);
    }
    sort(v.begin(),v.end());
    ans = sum;
    ll cnt = 0,lst = 0;
    for(auto &[s,op] : v){
        sum += x*(s-lst);
        sum -= y*cnt*(s-lst);
        lst = s;
        ans = min(ans,sum);
        if(op) cnt++;
        else cnt--;
    }
    cout << ans << "\n";
    // ll l = 0,r = 1e9,ans = 1e18;
    
    // while(l < r){
    //     ll mid1 = (l*2+r)/3,mid2=(l+r*2)/3;
    //     ll res1 = calc(mid1),res2 = calc(mid2);
    //     if(res1 <= res2) r = mid2-1;
    //     else             l = mid1+1;
    // }
    // // cout << 
    // for(int i=-100;i<=100;i++)
    //     ans = min(ans,calc(max(l+i,0ll)));
    // cout << ans << "\n";
}
int main(){
    // freopen("H.out","w",stdout);
    int T = read();
    while(T--) solve();
    return 0;
}
