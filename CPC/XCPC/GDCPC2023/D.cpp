#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<int,int>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 5e5+10;
int n,m;
pii a[N];
void solve(){
    n = read(); m = read();
    ll ans = 0;
    for(int i=1;i<=n;i++){
        a[i].se = read();
        a[i].fi = read();
        a[i].fi -= a[i].se;
        ans += a[i].se;
    }
    if(n == 1){
        cout << a[1].se+a[1].fi << "\n";
        return ;
    }
    sort(a+1,a+1+n,greater<pii>());
    int cnt = m-n,cnt1 = 0;
    for(int i=1;i<=n;i++)
        if(a[i].fi > 0) cnt1++;
    if(min(cnt1,cnt) <= n-2){
        for(int i=1;i<=min(cnt1,cnt);i++) ans += a[i].fi;
    }else{
        ll sum = ans;
        for(int i=1;i<=n;i++) sum += a[i].fi;
        ans = max(sum,sum-a[n].fi-a[n-1].fi);
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}