#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int mod = 998244353;
int n,m,k;
int C[N],pw[N],f[N],inv[N];
int pr[N/10],cnt;
ll fpow(ll x,ll k){
    if(k == 0) return 1;
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
void init(int m = 1e7){
    C[0] = 1; C[1] = n;
    pw[1] =  inv[1] = 1;
    for(int i=2;i<=m;i++){
        inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
        C[i] = 1ll*C[i-1]*(n-i+1)%mod*inv[i]%mod;
        if(!pw[i]) pw[i] = fpow(i,k),pr[++cnt] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=m;j++){
            pw[i*pr[j]] = 1ll*pw[i]*pw[pr[j]]%mod;
            if(i % pr[j] == 0) break;
        }
    }
}
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
namespace work1{
    inline void solve(){
        ll ans = 0;
        ll p = fpow(m,mod-2),q = (mod+1-p)%mod;
        ll pwp = 1,qwq = fpow(q,n);
        q = fpow(q,mod-2);
        for(int i=0;i<=n;i++){
            add(ans,C[i]*pwp%mod*qwq%mod*pw[i]%mod);
            pwp = pwp*p%mod;
            qwq = qwq*q%mod;
        }
        cout << ans << "\n";
    }
}
namespace work2{
    void solve(){
        f[k] = 1;
        ll p = mod-fpow(m,mod-2),q = (1+p)%mod;
        ll pwp = p,c = 1;
        for(int i=k-1;i;i--){
            c = c*(n-i-1)%mod*inv[k-i]%mod;
            f[i] = (pwp*c%mod+q*f[i+1]%mod)%mod;
            pwp = pwp*p%mod;
        }
        p = fpow(m,mod-2);
        ll mul = p,ans = 0; 
        for(int i=1;i<=k;i++)
            add(ans,mul*pw[i]%mod*C[i]%mod*f[i]%mod),mul = mul*p%mod;
        cout << ans << "\n";
    }
}
int main(){
    n = read(); m = read(); k = read();
    if(n == 1){
        cout << fpow(m,k);
        return 0;
    }
    init();
    if(n <= k) work1::solve();
    else work2::solve();
    return 0;
}