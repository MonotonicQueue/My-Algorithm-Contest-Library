#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 510;
const int mod = 998244353;
int n,m;
ll f[N][N],g[N][N],tmp[N][N],h[N][N],a[N];
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
void init(int n = 500){
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
int main(){
    init();
    n = read(); m = read();
    f[0][0] = 1;
    for(int i=0;i<m;i++)
        for(int j=0;j<=i;j++){
            add(f[i+1][j+1],f[i][j]);
            if(j >= i+1-j) add(f[i+1][j],f[i][j]);
        }
    //f_{m,i}一种牌选 i 张能赢的方案数
    g[0][0] = 1;
    for(int i=0;i<m;i++){
        memcpy(tmp,g,sizeof(tmp));
        memset(g,0,sizeof(g));
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i;k++){
                add(g[j+1][k],tmp[j][k]);
                if(j >= i+1-j-k) add(g[j][k],tmp[j][k]);
                else add(g[j][k+1],tmp[j][k]);
            }
        }
    }
    //g_{i,j}拿了 i 张，对面有 j 张打不过的方案数
    for(int j=0;j<=m;j++)
        for(int k=0;k<=m;k++) if(j == m-j-k) add(a[k],g[j][k]);
    //a_i 一种牌有 i 张打不过对面且没有未匹配牌的方案数
    h[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=m;j++)
            for(int k=0;k+j<=m;k++) add(h[i][k+j],a[k]*h[i-1][j]%mod);
    }
    //h_{i,j}考虑了 i 种颜色，共有 j 张打不过对面的方案数（多项式幂函数）
    ll ans = 0;
    for(int i=m/2;i<=m;i++){
        int x = i-(m-i);
        add(ans,h[n-1][x]*f[m][i]%mod);
    }
    cout << ans;
    return 0;
}