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
const int N = 510;
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
int n,m;
ll a[N],v[N],p[N];
vector<tuple<double,int,int>> vec;
ll f[N],g[N];
void del(int x){
    ll inv = fpow(mod+1-p[x],mod-2);
    for(int i=0;i<=m;i++){
        f[i] = f[i]*inv%mod;
        f[i+1] = (f[i+1]-f[i]*p[x]%mod+mod)%mod;
    }
}
void add(int x){
    if(!x) return ;
    for(int i=0;i<=m;i++) g[i] = 0;
    for(int i=0;i<=m;i++){
        g[i] = (g[i]+f[i]*(mod+1-p[x]))%mod;
        g[i+1] = (g[i+1]+f[i]*p[x])%mod;
    }
    for(int i=0;i<=m;i++) f[i] = g[i];
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = -read();
    for(int i=1;i<=m;i++) v[i] = read();
    ll invn = fpow(n,mod-2);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            vec.emplace_back(a[j]*1.0/v[i],i,j);
    sort(vec.begin(),vec.end());
    f[0] = 1;
    int lst = 0;
    ll ans = 0;
    for(auto &[t,x,y] : vec){
        del(x); add(lst);
        p[x] = (p[x]+invn)%mod;
        lst = x;
        ll ti = a[y]*fpow(v[x],mod-2)%mod;
        ans = (ans+f[m/2]*ti)%mod;
    }
    cout << ans*invn%mod;
	return 0;
} 


