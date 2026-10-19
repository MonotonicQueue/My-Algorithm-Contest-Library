#include<bits/stdc++.h>
#define int long long
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
const int N = 2e6+11010;
const int mod = 998244353;
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
int n,Q;
int cnt[N];
struct node{
    ll l,r;
}a[N];
ll ans[N];
struct Ques{
    ll x; int id;
}q[N];
bool cmp(Ques x,Ques y){
    return x.x < y.x;
}
signed main(){
    n = read(); Q = read();
    ll sum = 0,psum = 0;
    ll mx = 0;
    for(int i=1;i<=n;i++){
        a[i].l = read();
        a[i].r = read();
        mx = max(mx,a[i].r);
        sum += a[i].l;
        psum = (psum+1ll*a[i].l*a[i].l)%mod;
        cnt[a[i].l+1]++; cnt[a[i].r+1]--;
    }
    for(int i=1;i<=Q;i++){
        q[i].x = read();
        q[i].id = i;
    }
    sort(q+1,q+1+Q,cmp);
    ll c = 0,inv = fpow(n,mod-2);
    int j = 1;
    while(q[j].x == sum){
        ll xxx = q[j].x%mod*inv%mod;
        ans[q[j].id] = inv*psum%mod-xxx*xxx%mod;
        j++;
    }
    for(int i=0;i<=mx+1;i++){
        c += cnt[i];
        ll nsum = sum+c,npsum = (psum-c*(i-1)*(i-1)+c*i*i)%mod;
        npsum = (npsum%mod+mod)%mod;
        while(sum < q[j].x && q[j].x <= nsum && j <= Q){
            ll num = (q[j].x-sum+mod)%mod;
            ll sss = (psum-num*(i-1)%mod*(i-1)%mod+num*i%mod*i%mod)%mod;
            sss = (sss%mod+mod)%mod;
            ll xxx = q[j].x%mod*inv%mod;
            ans[q[j].id] = inv*sss%mod-xxx*xxx%mod;
            j++;
        }
        sum = nsum; psum = npsum;
    }
    assert(j > Q);
    for(int i=1;i<=Q;i++){
        cout << (ans[i]%mod+mod)%mod << "\n";
    }
    return 0;
}
