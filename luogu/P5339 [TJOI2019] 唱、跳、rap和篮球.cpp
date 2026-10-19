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
const int N = 1<<11;
const int mod = 998244353;
const int gg = 3,ig = (mod+1)/gg;
int n,num[5];
ll fac[N],inv[N];
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
ll a[N],b[N],c[N],d[N];
int rev[N];
void NTT(ll *f,int n,int type){
    for(int i=0;i<n;i++)
        if(i < rev[i]) swap(f[i],f[rev[i]]);
    for(int mid=1;mid<n;mid<<=1){
        ll gn = fpow(type == 1 ? gg : ig,(mod-1)/(mid << 1));
        for(int j=0,len=mid<<1;j<n;j+=len){
            ll g0 = 1;
            for(int i=0;i<mid;i++){
                ll x = f[i+j],y = f[i+j+mid]*g0%mod;
                f[i+j] = (x+y)%mod;
                f[i+j+mid] = (x-y+mod)%mod;
                g0 = g0*gn%mod;
            }
        }
    }
    if(type != 1){
        ll iv = fpow(n,mod-2);
        for(int i=0;i<n;i++) f[i] = f[i]*iv%mod;
    }
}
ll calc(int x,int n1,int n2,int n3,int n4){
    int lim = 0;
    while((1<<lim) < (n1+n2+n3+n4)) lim++;
    for(int i=0;i<(1<<lim);i++) rev[i] = rev[i>>1]>>1 | ((i & 1) << (lim-1));
    for(int i=0;i<(1<<lim);i++) a[i] = (i <= n1) ? inv[i] : 0;
    for(int i=0;i<(1<<lim);i++) b[i] = (i <= n2) ? inv[i] : 0;
    for(int i=0;i<(1<<lim);i++) c[i] = (i <= n3) ? inv[i] : 0;
    for(int i=0;i<(1<<lim);i++) d[i] = (i <= n4) ? inv[i] : 0;
    NTT(a,1<<lim,1); NTT(b,1<<lim,1); NTT(c,1<<lim,1); NTT(d,1<<lim,1);
    for(int i=0;i<(1<<lim);i++) a[i] = a[i]*b[i]%mod*c[i]%mod*d[i]%mod;
    NTT(a,1<<lim,-1);
    return fac[x]*a[x]%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void init(int n = 2000){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
int main(){
    init();
    n = read();
    for(int i=1;i<=4;i++) num[i] = read();
    int mn = num[1];
    for(int i=2;i<=4;i++) mn = min(mn,num[i]);
    ll ans = 0;
    for(int i=0;i<=min(n/4,mn);i++){
        ans = (ans+((i & 1) ? mod-1 : 1)*C(n-3*i,i)%mod
        *calc(n-4*i,num[1]-i,num[2]-i,num[3]-i,num[4]-i)%mod)%mod;
    }
    cout << ans;
    return 0;
}