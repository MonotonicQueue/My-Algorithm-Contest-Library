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
const int N = 2e6+10;
int n,p,mod;
int a[N];
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
    n = read(); mod = p = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int cnt0 = 0,ans = 0;
    for(int i=1;i<=n;i++)
        if(fpow(a[i],(p-1)/2) == 1) cnt0++;
    int cnt1 = n-cnt0;
    if(cnt0 & 1){
        ans = 1+cnt1/2;
    }else{
        ans = -cnt1/2;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
