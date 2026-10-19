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
const int N = 1e7+10;
const int mod = 1e9+7;
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
int vis[N],pr[N],cnt;
void init(int n = 1e7){
    vis[1] = 1;
    for(int i=2;i<=n;i++){
        if(!vis[i]) vis[i] = i,pr[++cnt] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
            vis[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
int l,r;
signed main(){
    init();
    l = read(); r = read();
    int k = 0,n = r-l+1;
    for(int i=l;i<=r;i++)
        if(i/vis[i] < l || i == 1) k++;
    ll ans = k;
    for(int i=1;i<=n+1;i++) ans = ans*i%mod;
    ans = ans*fpow(k+1,mod-2)%mod;
    cout << ans;
    return 0;
}
