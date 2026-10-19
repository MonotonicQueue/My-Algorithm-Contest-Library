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
const int N = 2e6+10;
int n,mod;
int pr[N],cnt,vis[N];
inline void init(){
    for(int i=2;i<=2*n;i++){
        if(!vis[i]) pr[++cnt] = i,vis[i] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=2*n;j++){
            vis[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
ll fpow(ll x,ll k){
    ll res = 1;
    assert(k >= 0);
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
int sum[N];
int main(){
    n = read(); mod = read();
    init();
    ll ans = 1;
    for(int i=1;i<=n;i++) sum[i] = -1;
    for(int i=n+2;i<=2*n;i++) sum[i] = 1;
    for(int i=2*n;i>=2;i--)
        if(vis[i] != i) sum[i/vis[i]] += sum[i],sum[vis[i]] += sum[i],sum[i] = 0;
    for(int i=2;i<=2*n;i++)
        if(vis[i] == i) ans = ans*fpow(i,sum[i])%mod;
    cout << ans;
    return 0;
}
