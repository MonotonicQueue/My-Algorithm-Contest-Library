#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
namespace fastio{
    char ibuf[1 << 20],*p1 = ibuf, *p2 = ibuf;
    #define get() p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = get();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = get();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = get();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args&... args){
        read(t);
        read(args...);
    }
    template<typename T> void write(T t){
        if(t < 0) putchar('-'), t = -t;
        if(t >= 10) write(t / 10);
        putchar(t % 10 + '0');
    }
    template<typename T, typename ... Args> void write(T t, Args... args){
        write(t), putchar(' '), write(args...);
    }
    template<typename T> void writeln(T t){
        write(t);
        puts("");
    }
    template<typename T> void writes(T t){
        write(t), putchar(' ');
    }
    #undef get
};
using namespace fastio;
const int N = 1e5+10;
const int mod = 1e9+7;
int n,k,deg[N];
bool flag[N];
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
inline void init(int n = 1e5){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[1] = 1;
	for(int i=2;i<=n;i++) inv[i] = inv[mod%i]*(mod-mod/i)%mod;
}
vector<pii> G[N];
ll f[N],a[N],ans;
void dfs(int x,int fa,bool flg){
	f[x] = -flg;
	ll s = -flg; ans = (ans+flg)%mod;
	for(auto [y,id] : G[x]){
		if(y == fa) continue;
		dfs(y,x,flag[id]);
		ans = (ans-s*f[y]%mod*a[x]%mod+mod)%mod;
		s = (s+f[y])%mod;
		if(!flg) f[x] = (f[x]+a[x]*f[y])%mod;
	}
}
void clear(){
	for(int i=1;i<=n;i++){
		deg[i] = 0;
		G[i].clear();
		flag[i] = 0;
	}
}
void solve(){
	read(n,k);
	clear();
	for(int i=1;i<n;i++){
		int u,v; read(u,v);
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		deg[u]++; deg[v]++;
	}
	for(int i=1;i<=n;i++) a[i] = inv[deg[i]-1];
	for(int i=1;i<=k;i++){
		int id; read(id);
		flag[id] = true;
	}
	ans = 0;
	dfs(1,0,0);
	for(int i=1;i<=n;i++) ans = ans*fac[deg[i]-1]%mod;
	cout << ans << "\n";
}
int main(){
	init();
	int c,T; read(c,T);
	while(T--) solve();
	return 0;
}