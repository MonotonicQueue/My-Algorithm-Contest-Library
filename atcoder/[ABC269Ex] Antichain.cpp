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
const int N = 4e5+10;
const int mod = 998244353;
const int gg = 3,ig = (mod+1)/gg;
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
typedef vector<ll> poly;
int rev[N];
inline poly NTT(poly F,int type){
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
	return F;
}
poly operator + (poly x,poly y){
	int n = x.size(),m = y.size();
	poly res(max(n,m));
	for(int i=0;i<n;i++) res[i] = x[i];
	for(int i=0;i<m;i++) res[i] = (res[i]+y[i])%mod;
	return res;
}
poly operator * (poly x,poly y){
	int n = x.size(),m = y.size();
	int l = 0;
	while((1 << l) < n+m-1) l++;
	for(int i=1;i<(1<<l);i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	poly f(1<<l),g(1<<l);
	for(int i=0;i<n;i++) f[i] = x[i];
	for(int i=0;i<m;i++) g[i] = y[i];
	f = NTT(f,1); g = NTT(g,1);
	for(int i=0;i<(1<<l);i++) f[i] = f[i]*g[i]%mod;
	f = NTT(f,-1);
	f.resize(n+m-1);
	return f;
}


int n,fa[N];
int siz[N],son[N],top[N];
vector<int> G[N];

void dfs1(int x){
	siz[x] = 1;
	for(int y : G[x]){
		dfs1(y);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	}
}
void dfs2(int x,int topx){
	top[x] = topx;
	if(!son[x]) return ;
	dfs2(son[x],x);
	for(int y : G[x])
		if(y != son[x]) dfs2(y,y);
}
poly f[N],a[N],b[N];
pair<poly,poly> calc(int l,int r){
	if(l == r) return mk(a[l],a[l]);
	int mid = (l+r) >> 1;
	auto L = calc(l,mid),R = calc(mid+1,r);
	return mk(L.fi+R.fi*L.se,L.se*R.se);
}
poly calc2(int l,int r){
	if(l == r) return b[l];
	int mid = (l+r) >> 1;
	return calc2(l,mid)*calc2(mid+1,r);
}
void dfs(int x){
	for(int y : G[x]) dfs(y);
	if(x == top[x]){
		int k = 0;
		for(int y=x;y;y=son[y]){
			if(G[y].size() <= 1){
				a[++k] = poly(1,1);
				continue;
			}
			int tot = 0;
			for(int z : G[y])
				if(z != son[y]) b[++tot] = f[z];
			a[++k] = calc2(1,tot);
		}
		auto res = calc(1,k);
		f[x].push_back(0);
		for(ll v : res.fi) f[x].push_back(v);
		for(int i=0;i<(int)res.se.size();i++){
			f[x][i+1] = (f[x][i+1]-res.se[i]+mod)%mod;
			f[x][i] = (f[x][i]+res.se[i])%mod;
		}
		f[x][1] = (f[x][1]+1)%mod;
	}
}
int main(){
    n = read();
	for(int i=2;i<=n;i++){
		fa[i] = read();
		G[fa[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	dfs(1);
	for(int i=1;i<=n;i++)
		cout << (i >= int(f[1].size()) ? 0 : f[1][i]) << "\n";
    return 0;
}