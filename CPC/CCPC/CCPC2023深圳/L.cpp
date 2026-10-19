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
const int mod = 1e9+9;
const int N = 1e7+10;
int m,k;
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
ll sum[N],inv[N],f[N],g[N];
void init(){
    sum[1] = 1;
    for(int i=2;i<=k;i++) sum[i] = sum[i-1]+m-1;
    f[0] = 1; g[k+1] = 1;
    for(int i=1;i<=k;i++) f[i] = f[i-1]*sum[i]%mod;
    for(int i=k;i>=1;i--) g[i] = g[i+1]*sum[i]%mod;
    ll mul = f[k]; mul = fpow(mul,mod-2);
    for(int i=1;i<=k;i++) inv[i] = mul*f[i-1]%mod*g[i+1]%mod;
    for(int i=0;i<=k+1;i++) f[i] = g[i] = 0;
}
int main(){
    m = read(); k = read()+1;
    init();
    f[1] = g[1] = 0;
    for(int i=2;i<=k;i++){
        f[i] = (f[i-1]+m*(g[i-1]+1)%mod)%mod;
        g[i] = (g[i-1]*(sum[i-1]-1)%mod+(g[i-1]+1)*m%mod)%mod*inv[i]%mod;
    }
    cout << f[k];
	return 0;
} 
