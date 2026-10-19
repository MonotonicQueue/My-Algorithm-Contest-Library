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
const int N = 1<<22;
const int mod = 998244353;
int n,m,k,a[N];
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
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
inline void del(ll &x,ll y){
    x = x-y >= 0 ? x-y : x-y+mod;
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
}
using namespace polynomial;
int cnt[N];
ll inv[N];
signed main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read()-2;
    for(int i=1;i<=n;i++)
        if(a[i] == -1) m++,cnt[1]++;
        else if(a[i] == 0) k++;
        else cnt[a[i]]++;
    m -= 2;
    if(m < 0) return puts("0"),0;
    for(int i=1;i<=m;i++) inv[i] = fpow(i,mod-2);
    poly f(m+1);
    for(int i=1;i<=m;i++){
        if(!cnt[i]) continue;
        for(int j=1;j*i<=m;j++) add(f[i*j],((j & 1) ? inv[j] : mod-inv[j])*cnt[i]%mod);
    }
    f = polyexp(f);
    cout << f[m]*fpow(2,k)%mod;
    return 0;
}
