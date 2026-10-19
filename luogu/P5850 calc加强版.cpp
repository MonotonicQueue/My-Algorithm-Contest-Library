#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
void write(int x){
    if(!x) return ;
    write(x/10);
    putchar((x%10)+'0');
}
const int N = 1<<22;
const int mod = 998244353;
int fpow(int x,int k){
	int res = 1;
	while(k){
		if(k & 1)
			res = 1ll*res*x%mod;
		x = 1ll*x*x%mod;
		k >>= 1;
	}
	return res;
}
int fac[N],inv[N];
void init(int n = 5e5){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = 1ll*fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = 1ll*inv[i+1]*(i+1)%mod;
}
int C(int x,int y){
    return 1ll*fac[x]*inv[y]%mod*1ll*inv[x-y]%mod;
}
namespace polynomial{
	const int gg = 3,ig = (mod+1)/gg;
	typedef vector<int> poly;
	int rev[N];
	inline void NTT(poly &F,int type){
		int n = F.size();
		for(int i=0;i<n;i++)
			if(i < rev[i]) swap(F[i],F[rev[i]]);
		for(int mid=1;mid<n;mid<<=1){
			int gn = fpow(type == 1 ? gg : ig,(mod-1)/(mid << 1));
			for(int j=0,len=mid<<1;j<n;j+=len){
				int g0 = 1;
				for(int i=0;i<mid;i++){
					int x = F[i+j],y = 1ll*F[i+j+mid]*g0%mod;
					F[i+j] = (x+y)%mod;
					F[i+j+mid] = (x-y+mod)%mod;
					g0 = 1ll*g0*gn%mod;
				}
			}
		}
		if(type != 1){
			int inv = fpow(n,mod-2);
			for(int i=0;i<n;i++) F[i] = 1ll*F[i]*inv%mod;	
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
		for(int i=0;i<(1<<l);i++) f[i] = 1ll*f[i]*g[i]%mod;
		NTT(f,-1);
		f.resize(n+m-1);
		return f;
	}
	poly operator * (const int &x,const poly &y){
		int n = y.size();
        poly res(n);
        for(int i=0;i<n;i++) res[i] = 1ll*y[i]*x%mod;
        return res;
	}
	poly operator * (const poly &y,const int &x){
		int n = y.size();
        poly res(n);
        for(int i=0;i<n;i++) res[i] = 1ll*y[i]*x%mod;
        return res;
	}
	poly operator + (const int &x,const poly &y){
        poly res = y; res[0] = (res[0]+x)%mod;
        return res;
	}
	poly operator + (const poly &y,const int &x){
        poly res = y; res[0] = (res[0]+x)%mod;
        return res;
	}
	poly operator - (const int &x,const poly &y){
		int n = y.size();
        poly res(n); res[0] = x;
		for(int i=0;i<n;i++) res[i] = (res[i]-y[i]+mod)%mod;
        return res;
	}
	poly operator - (const poly &y,const int &x){
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
			return {1};
		}
		poly&& g = polysqrt(f,(len+1) >> 1);
		poly tmp(len); int inv2 = (mod+1)/2;
        for(int i=0;i<len;i++) tmp[i] = f[i];
        g.resize(len);
        g = 1ll*(tmp*polyinv(g)+g)*inv2;
		g.resize(len);
		return g;
	}
	inline poly polysqrt(const poly &f){
		return polysqrt(f,f.size());
	}
    inline poly polydev(const poly &f){
        int n = f.size(); poly res(n);
        for(int i=1;i<n;i++) res[i-1] = 1ll*f[i]*i%mod;
        return res;
    }
    inline poly polyint(const poly &f){
        int n = f.size(); poly res(n);
        for(int i=1;i<n;i++) res[i] = 1ll*f[i-1]*fpow(i,mod-2)%mod;
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
int m,k;
int main(){
    init();
    k = read(); m = read();
    poly f(m+1),g(m+1);
    for(int i=0;i<=m;i++) f[i] = 1ll*(1+mod-fpow(k+1,i+1))*inv[i+1]%mod;
    for(int i=0;i<=m;i++) g[i] = 1ll*(mod-1)*inv[i+1]%mod;
    f = f*polyinv(g);
    g[0] = 0;
    for(int i=0;i<=m;i++) f[i] = 1ll*f[i]*fac[i]%mod;
    for(int i=1;i<=m;i++)
        g[i] = 1ll*((i & 1) ? fpow(i,mod-2) : mod-fpow(i,mod-2))*f[i]%mod;
    g = polyexp(g);
    for(int i=1;i<=m;i++) write(1ll*g[i]*fac[i]%mod),putchar('\n');
    return 0;
}