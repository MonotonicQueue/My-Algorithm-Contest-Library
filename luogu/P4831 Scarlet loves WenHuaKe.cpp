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
const int mod = 998244353;
const int G = 3,Gi = (mod+1)/3;
const int N = 1<<20;
int n,m;
ll fac[N],ifac[N],pw[N];
ll C(int x,int y){
    if(x < y || y < 0 || x < 0) return 0;
    return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
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
int rev[N];
void NTT(ll *f,int n,int type){
    for(int i=0;i<n;i++)
        if(i < rev[i]) swap(f[i],f[rev[i]]);
    for(int mid=1;mid<n;mid<<=1){
        ll gn = fpow(type == 1 ? G : Gi,(mod-1)/(mid<<1));
        for(int j=0,len=mid<<1;j<n;j+=len){
            ll g0 = 1;
            for(int i=0;i<mid;i++){
                ll A0 = f[i+j],A1 = f[i+j+mid]*g0%mod;
                f[i+j] = (A0+A1)%mod;
                f[i+j+mid] = (A0-A1+mod)%mod;
                g0 = g0*gn%mod;
            }
        }
    }
    if(type != 1){
        ll iv = fpow(n,mod-2);
        for(int i=0;i<n;i++) f[i] = f[i]*iv%mod;
    }
}
inline void polymul(ll *f,ll *g){
    int limit = 1,l = 0;
    while(limit <= 2*n) limit <<= 1,l++;
    for(int i=1;i<limit;i++) rev[i] = rev[i>>1]>>1 | ((i & 1) <<(l-1));
    NTT(f,limit,1); NTT(g,limit,1);
    for(int i=0;i<limit;i++) f[i] = f[i]*g[i]%mod;
    NTT(f,limit,-1); 
}
ll f[N],g[N];
int main(){
    n = read(); m = read();
    auto init = [&](int M = 2e5){
        fac[0] = ifac[0] = pw[0] = 1;
        for(int i=1;i<=M;i++) fac[i] = fac[i-1]*i%mod;
        ifac[M] = fpow(fac[M],mod-2);
        for(int i=M-1;i;i--) ifac[i] = ifac[i+1]*(i+1)%mod;
        for(int i=1;i<=M;i++) pw[i] = pw[i-1]*2%mod;
    };
    init();
    for(int i=0;i<=n;i++) f[i] = ((i & 1) ? mod-1 :1)*C(n,i)%mod*pw[i]%mod*fac[2*n-2*i]%mod;
    for(int i=0;i<=n;i++) g[i] = ifac[i];
    polymul(f,g);
    for(int i=0;i<=n;i++) f[i] = f[i]*fac[i]%mod*fpow(pw[n+i],mod-2)%mod;
    ll ans = 0;
    for(int i=max(0,2*n-m);i<=n;i++)
        ans = (ans+f[i]*C(m,i)%mod*C(m-i,2*n-2*i)%mod)%mod;
    cout << ans;
    return 0;
}
