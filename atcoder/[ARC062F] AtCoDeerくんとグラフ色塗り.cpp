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
const int N = 1e4;
const int M = 1e4;
const int mod = 1e9+7;
int n,m,k;
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
void init(int n = 10000){
    fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
    inv[n] = fpow(fac[n],mod-2);
    for(int i=n-1;i;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll C(int x,int y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
vector<int> G[N],V[N];
int dfn[N],low[N],tot,cnt,stk[N],top,sz[N],sum[N];
void tarjan(int x,int fa){
	dfn[x] = low[x] = ++tot;
	stk[++top] = x;
	for(int y : G[x]){
		if(!dfn[y]){
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if(low[y] >= dfn[x]){
				int z; cnt++;
				do{
					z = stk[top--];
					sz[cnt]++;
					V[z].push_back(cnt);
				}while(z != y);
				V[x].push_back(cnt);
				sz[cnt]++;
			}
		}else if(y != fa) low[x] = min(low[x],dfn[y]);
	}
}
int find(int x,int y){
	for(int a : V[x])
		for(int b : V[y])
			if(a == b) return a;
	return 0;
}
struct Edge{
	int u,v;
}e[N];
int phi(int x){
	int res = x;
	for(int i=2;i*i<=x;i++)
		if(x % i == 0){
			res = res/i*(i-1);
			while(x % i == 0) x /= i;
		}
	if(x > 1) res = res/x*(x-1);
	return res;
}
ll calc(int x){
	ll res = 0;
	for(int i=1;i<=x;i++){
		res = (res+fpow(k,__gcd(x,i)))%mod;
	}
	return res*fpow(x,mod-2)%mod;
}
int main(){
	init();
    n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		e[i] = Edge{u,v};
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i,i);
	for(int i=1;i<=m;i++){
		int u = e[i].u,v = e[i].v;
		sum[find(u,v)]++;
	}
	ll ans = 1;
	for(int i=1;i<=cnt;i++){
		if(sum[i] == 1 && sz[i] == 2) ans = ans*k%mod;
		else if(sum[i] == sz[i]) ans = ans*calc(sum[i])%mod;
		else ans = ans*C(sum[i]+k-1,k-1)%mod;
	}
	cout << ans;
    return 0;
}
