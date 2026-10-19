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
const int N = 2010;
const int mod = 666623333;
int n,q,m,s;
struct node{
    int l,r;
}a[N],b[N];
int pos[N];
bool cmp(node x,node y){
    return x.l != y.l ? x.l < y.l : x.r < y.r;
}
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
ll pw[N],iv[N],sum[N],f[N],g[N];
inline void work(int x){
    for(int i=0;i<=n;i++) f[i] = sum[i] = 0;
    ll p = x*fpow(s,mod-2)%mod,pp = (1-p+mod)%mod;
    pw[0] = iv[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*pp%mod;
    iv[n] = fpow(pw[n],mod-2);
    for(int i=n-1;i ;i--) iv[i] = iv[i+1]*pp%mod;
    f[0] = 1;
    // for(int i=1;i<=n;i++){
    //     if(pos[i]){
    //         for(int j=pos[i];j<=i;j++)
    //             f[i] = (f[i]+p*pw[i-j]%mod*f[j-1]%mod)%mod;
    //     }else f[i] = f[i-1];
    // }
    for(int i=1;i<=n;i++){
        sum[i] = (sum[i-1]+f[i-1]*iv[i])%mod;
        if(pos[i]) f[i] = p*pw[i]%mod*(sum[i]-sum[pos[i]-1]+mod)%mod;
        else       f[i] = f[i-1];
    }
    g[x] = f[n];
}
int main(){
    n = read(); s = read(); q = read();
    for(int i=1;i<=q;i++)
        a[i].l = read(),a[i].r = read();
    sort(a+1,a+1+q,cmp);
    for(int i=1;i<=q;i++){
        while(b[m].r > a[i].r) m--;
        b[++m] = a[i];
    }
    for(int i=1;i<=m;i++) pos[b[i].r] = b[i].l;
    for(int i=1;i<s;i++) work(i);
    g[s] = 1;
    ll ans = 0;
    for(int i=1;i<=s;i++) ans = (ans+(g[i]-g[i-1]+mod)%mod*i%mod)%mod;
    cout << ans;
	return 0;
}
