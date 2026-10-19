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
const int N = 1<<20;
const int mod = 998244353;
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
void init(int n = 2e5){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
namespace polynomial{
	const int gg = 3,ig = (mod+1)/gg;
	typedef vector<ll> poly;
	int rev[N];
	inline void NTT(poly &F,int type){
		int n = F.size();
		for(int i=0;i<n;i++)
			if(i < rev[i]) swap(F[i],F[rev[i]]);
		for(int mid=1;mid<n;mid<<=1){
			ll gn = fpow(type == 1 ? gg : ig,(mod-1)/(mid << 1));
			for(int j=0,len=mid<<1;j<n;j+=len){
				ll g0 = 1;
				for(int i=0;i<mid;i++){
					ll x = F[i+j],y = F[i+j+mid]*g0%mod;
					F[i+j] = (x+y)%mod;
					F[i+j+mid] = (x-y+mod)%mod;
					g0 = g0*gn%mod;
				}
			}
		}
		if(type != 1){
			int inv = fpow(n,mod-2);
			for(int i=0;i<n;i++) F[i] = F[i]*inv%mod;	
		}
	}
	poly operator + (const poly &x,const poly &y){
		int n = x.size(),m = y.size();
		poly res(max(n,m));
		for(int i=0;i<n;i++) res[i] = x[i];
		for(int i=0;i<m;i++) res[i] = (res[i]+y[i])%mod;
		return res;
	}
	poly operator - (const poly &x,const poly &y){
		int n = x.size(),m = y.size();
		poly res(max(n,m));
		for(int i=0;i<n;i++) res[i] = x[i];
		for(int i=0;i<m;i++) res[i] = (res[i]-y[i]+mod)%mod;
		return res;
	}
	poly operator * (const poly &x,const poly &y){
		int n = x.size(),m = y.size();
		int l = 0;
		while((1 << l) < n+m-1) l++;
		for(int i=1;i<(1<<l);i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
		poly f(1<<l),g(1<<l);
		for(int i=0;i<n;i++) f[i] = x[i];
		for(int i=0;i<m;i++) g[i] = y[i];
		NTT(f,1); NTT(g,1);
		for(int i=0;i<(1<<l);i++) f[i] = f[i]*g[i]%mod;
		NTT(f,-1);
		f.resize(n+m-1);
		return f;
	}
	poly operator * (const ll &x,const poly &y){
		int n = y.size();
        poly res(n);
        for(int i=0;i<n;i++) res[i] = y[i]*x%mod;
        return res;
	}
	poly operator * (const poly &y,const ll &x){
		int n = y.size();
        poly res(n);
        for(int i=0;i<n;i++) res[i] = y[i]*x%mod;
        return res;
	}
	poly operator + (const ll &x,const poly &y){
        poly res = y; res[0] = (res[0]+x)%mod;
        return res;
	}
	poly operator + (const poly &y,const ll &x){
        poly res = y; res[0] = (res[0]+x)%mod;
        return res;
	}
	poly operator - (const ll &x,const poly &y){
		int n = y.size();
        poly res(n); res[0] = x;
		for(int i=0;i<n;i++) res[i] = (res[i]+mod-y[i]);
        return res;
	}
	poly operator - (const poly &y,const ll &x){
        poly res = y; res[0] = (res[0]-x+mod)%mod;
        return res;
	}
	poly polyinv(const poly &f,int len){
		if(len == 1) return {fpow(f[0],mod-2)};
        poly&& g = polyinv(f,(len+1) >> 1);
        poly tmp(len);
        for(int i=0;i<len;i++) tmp[i] = f[i];
        g = 2*g-tmp*g*g;
        g.resize(len);
        return g;
	}
    inline poly polyinv(const poly &f){
        return polyinv(f,f.size());
    }
	poly polysqrt(const poly &f,int len){
		if(len == 1){
			assert(f[0] == 1);
			//二次剩余
			return {1};
		}
		poly&& g = polysqrt(f,(len+1) >> 1);
		poly tmp(len); ll inv2 = (mod+1)/2;
        for(int i=0;i<len;i++) tmp[i] = f[i];
        g.resize(len);
        g = (tmp*polyinv(g)+g)*inv2;
		g.resize(len);
		return g;
	}
	inline poly polysqrt(const poly &f){
		return polysqrt(f,f.size());
	}
    inline poly polydev(const poly &f){
        int n = f.size(); poly res(n);
        for(int i=1;i<n;i++) res[i-1] = f[i]*i%mod;
        return res;
    }
    inline poly polyint(const poly &f){
        int n = f.size(); poly res(n);
        for(int i=1;i<n;i++) res[i] = f[i-1]*fpow(i,mod-2)%mod;
        return res;
    }
    poly polyln(const poly &f){
        poly g = polydev(f)*polyinv(f);
        g.resize(f.size());
        return polyint(g);
    }
    poly polyexp(const poly &f,int len){
        if(len == 1) return {1};
        poly&& g = polyexp(f,(len+1) >> 1);
        poly tmp(len);
        for(int i=0;i<len;i++) tmp[i] = f[i];
        g.resize(len);
        g = g*(1-polyln(g)+tmp);
        g.resize(len);
        return g;
    }
    inline poly polyexp(const poly &f){
        return polyexp(f,f.size());
    }
	inline poly polypow(const poly &f,const ll &k){
		return polyexp(polyln(f)*k);
    }
}
using namespace polynomial;
int n,m,a[N];
ll f[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n*m;i++) a[i] = read();
    sort(a+1,a+1+n*m);
    poly F,G;
    for(int i=n*m;i>=1;i--) F.push_back(fac[i-1]*a[i]%mod);
    for(int i=1;i<=n*m;i++) G.push_back(inv[i-1]);
    F = F*G;
    for(int i=1;i<=n*m;i++) f[i] = F[m*n-i];
    for(int i=1;i<=n*m;i++) f[i] = f[i]*i%mod*fac[n*m-i]%mod;
    // for(int i=1;i<=n*m;i++) cout << f[i] << " ";
    // cout << "\n";
    ll ans = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){
        int c = i*m+j*n-i*j;
        ans = (ans+(((i+j-1) & 1) ? mod-f[c] : f[c])*C(n,i)%mod*C(m,j)%mod)%mod;
    }
    cout << ans << "\n";
}
int main(){
    init();
    int T = read();
    while(T--) solve();
	return 0;
}