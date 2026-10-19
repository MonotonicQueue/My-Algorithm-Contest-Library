#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
const int mod = 998244353;
ll fac[N],inv[N],pw[N];
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
void init(int n = 2e5){
    fac[0] = inv[0] = pw[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*2%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m,a[N];
ll cnt[N];
void clear(){
    for(int i=0;i<=n;i++) cnt[i] = 0;
}
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
int main(){
    init();
	int T = read();
    while(T--){
        n = read();
        clear();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        vector<vector<ll>>f(n);
        for(int i=0;i<n;i++) f[i].resize(cnt[i]+1);
        for(int i=0;i<=cnt[0];i++) f[0][i] = C(cnt[0],i);
        for(int i=1;i<n;i++){
            vector<ll> suf(max(cnt[i-1],cnt[i])+2),sumC(cnt[i]+1);
            for(int j=0;j<=cnt[i-1];j++) suf[j] = f[i-1][j];
            for(int j=cnt[i-1]-1;~j;j--) add(suf[j],suf[j+1]);
            for(int j=0;j<=cnt[i];j++) sumC[j] = C(cnt[i],j);
            for(int j=cnt[i]-1;~j;j--) add(sumC[j],sumC[j+1]);
            for(int j=0;j<=cnt[i];j++)
                add(f[i][j],C(cnt[i],j)*suf[j+1]%mod);
            for(int j=0;j<=min(cnt[i-1],cnt[i]);j++) add(f[i][j],sumC[j]*f[i-1][j]%mod);
        }
        for(int i=n-1;i;i--) add(cnt[i],cnt[i+1]);
        ll ans = 0;
        for(int i=0;i<n;i++)
            for(int j=1;j<int(f[i].size());j++) add(ans,j*f[i][j]%mod*pw[cnt[i+1]]%mod);
        cout << ans << "\n";
    }
    return 0;
}

