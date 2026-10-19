#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 20;
const int M = 1<<15;
const int mod = 1e9+7;
ll fac[60],inv[60],pw[60][60];
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
void init(int n = 50){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++){
		pw[i][0] = 1;
		for(int j=1;j<=n;j++) pw[i][j] = pw[i][j-1]*i%mod;
	}
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m,K;
vector<int> E[N];
bool vis[N];
int t[M],mn[M];
ll h[M],g[M][N],f[N],tmp[N];
ll G[M][N],F[M][N];
inline void add(ll &x,ll y){
	x = x+y >= mod ? x+y-mod : x+y;
}
typedef vector<ll> poly;
poly operator*(poly x,poly y){
	int n = x.size(),m = y.size();
	poly res(n+m-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) res[i+j] = (res[i+j]+x[i]*y[j])%mod;
	return res;
}
void solve(){
	poly G = {1};
    for(int i=1;i<=n+1;i++){
        poly h = {-i,1};
        G = G*h;
    }
	for(int i=0;i<=n+1;i++) G[i] = (G[i]+mod)%mod;
    for(int i=1;i<=n+1;i++){
        ll t = 1;
        for(int j=1;j<=n+1;j++)
            if(i != j) t = t*(i-j)%mod;
        if(t < 0) t += mod;
        t = fpow(t,mod-2);
        t = t*F[(1<<n)-1][i]%mod;
        for(int j=1;j<=n+1;j++) tmp[j] = G[j];
        for(int j=n+1;j;j--){
            tmp[j-1] = (tmp[j-1]+tmp[j]*i)%mod;
            f[j-1] = (f[j-1]+tmp[j]*t)%mod;
        }
    }
}
void bfs(int st){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(st); vis[st] = true;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int y : E[x])
			if(!vis[y]) vis[y] = true,q.push(y);
	}
	for(int i=1;i<=n;i++) t[1<<(st-1)] |= vis[i] << (i-1);
}
int main(){
	init();
	n = read(); m = read(); K = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		E[u].push_back(v);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++) if((i >> j) & 1) t[i] |= t[1<<j];
	auto chk = [&](int S,int T)->bool{
		return !(t[S] & T);
	};
	auto lowbit = [&](int x){
		return x & (-x);
	};
	h[0] = 1;
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if((i >> j) & 1) add(h[i],chk(i^(1<<j),1<<j)*h[i^(1<<j)]);
	g[0][0] =  1;
	for(int i=1;i<(1<<n);i++)
		for(int j=i;j;j=(j-1)&i)
			if(chk(i^j,j) && chk(j,i^j) && lowbit(i) == lowbit(j))
				for(int k=1;k<=K+1;k++) add(g[i][k],g[i^j][k-1]*h[j]%mod);
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<=K+1;j++)
			for(int p=0;p<=n+1;p++) add(G[i][p],g[i][j]*((j & 1) ? pw[p][j] : mod-pw[p][j])%mod);
	for(int p=0;p<=n+1;p++) F[0][p] = 1;
	for(int i=1;i<(1<<n);i++)
		for(int j=i;j;j=(j-1)&i) if(chk(j,i^j))
			for(int p=0;p<=n+1;p++)
				add(F[i][p],F[i^j][p]*G[j][p]%mod);
	solve();
	ll ans = 0;
	for(int i=1;i<=K+1;i++){
		add(ans,f[i]*fac[i]%mod*fac[K]%mod*C(K+1,i)%mod);
	}
	ans = ans*inv[n+K]%mod;
	cout << (ans%mod+mod)%mod;
	return 0;
}