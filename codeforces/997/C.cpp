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

const int N = 1e6+10;
const int mod = 998244353;
int n;
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
ll fac[N],inv[N];
void init(int n = 1e6){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
inline void del(ll &x,ll y){
    x = x-y >= 0 ? x-y : x-y+mod;
}
signed main(){
	init();
    n = read();
    ll ans = fpow(3,1ll*n*n);
    for(int i=1;i<=n;i++) add(ans,2*((i & 1) ? mod-C(n,i) : C(n,i))*fpow(3,1ll*n*(n-i)+i)%mod);
    ll sum = 0;
    for(int i=1;i<=n;i++)
        add(sum,((i & 1) ? mod-C(n,i) : C(n,i))*(fpow((fpow(3,n-i)-1),n)-fpow(3,1ll*n*(n-i))+mod)%mod);
    sum = sum*3%mod;
    add(ans,sum);
    cout << (fpow(3,1ll*n*n)-ans+mod)%mod << "\n";
    return 0;
}
