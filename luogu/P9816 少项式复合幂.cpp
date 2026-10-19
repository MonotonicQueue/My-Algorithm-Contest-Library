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
const int N = 3e5+10;
int n,m,q,mod;
ll fpow(ll x,ll k){
    if(x == 0) return k == 0;
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
struct poly{
    ll a[N],b[N];
    ll get(ll x){
        ll res = 0;
        for(int i=1;i<=m;i++) add(res,a[i]*fpow(x,b[i])%mod);
        return res;
    }
}WXB;
int f[N][28];
signed main(){
    m = read(); q = read(); mod = read();
    for(int i=1;i<=m;i++){
        WXB.a[i] = read();
        WXB.b[i] = read();
    }
    for(int i=0;i<mod;i++) f[i][0] = WXB.get(i);
    for(int j=1;j<=25;j++)
        for(int i=0;i<mod;i++) f[i][j] = f[f[i][j-1]][j-1];
    while(q--){
        int x = read(),k = read();
        x %= mod;
        for(int i=25;~i;i--)
            if((k >> i) & 1) x = f[x][i];
        cout << x << "\n";
    }
    return 0;
}