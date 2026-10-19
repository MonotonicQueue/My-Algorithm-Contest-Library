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
int n; ll m,ans;
struct node{
    ll w,l,r;
}a[N];
ll suf[N],valsuf[N],pre[N],valpre[N];
ll s1[N],s2[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        ll w = read(),l = read(),r = read();
        a[i] = node{w,l,r};
    }
    sort(a+1,a+1+n,[](node x,node y){return x.w == y.w ? x.l < y.l : x.w > y.w;});
    
    for(int i=n;i;i--){
        suf[i] += a[i].l+suf[i+1];
        valsuf[i] += a[i].l*a[i].w+valsuf[i+1];
    }
    for(int i=1;i<=n;i++){
        pre[i] += pre[i-1]+a[i].l;
        valpre[i] += valpre[i-1]+a[i].l*a[i].w;
    }
    // for(int i=1;i<=n;i++) cout << a[i].w << " " << a[i].l << " " << a[i].r << "\n";
    for(int i=1;i<=n;i++){
        ll rest = m-(pre[i-1]+suf[i+1]);
        int id = upper_bound(s1,s1+i,rest)-s1-1;
        // cout << id << " " << s1[id] << " " << s2[id] << "\n";
        rest -= s1[id];
        assert(rest >= 0 && (rest < s1[id+1] || id+1 == i) && id >= 0);
        ll now = valpre[i-1]+valsuf[i+1]+s2[id];
        now += rest*a[id+1].w;
        ans = max(ans,now);
        s1[i] = s1[i-1]+a[i].r-a[i].l;
        s2[i] = s2[i-1]+(a[i].r-a[i].l)*a[i].w;
    }
    cout << ans;
}
signed main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
