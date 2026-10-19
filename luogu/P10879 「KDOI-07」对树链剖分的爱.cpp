#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
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
const int N = 5100;
const int mod = 998244353;
int n,m;
int l[N],r[N];
ll inv[N],g[N][N],ans[N];
void add(int lx,int rx,int ly,int ry,ll d){
    g[rx][ry] = (g[rx][ry]+d)%mod;
    g[lx-1][ry] = (g[lx-1][ry]+mod-d)%mod;
    g[rx][ly-1] = (g[rx][ly-1]+mod-d)%mod;
    g[lx-1][ly-1] = (g[lx-1][ly-1]+d)%mod;
}
signed main(){
    n = read();
    for(int i=2;i<=n;i++) l[i] = read(),r[i] = read();
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        if(u > v) swap(u,v);
        add(u,u,v,v,read());
    }
    for(int i=n;i;i--){
        for(int j=n;j;j--){
            g[i][j] = (g[i][j]+g[i+1][j]+g[i][j+1]+mod-g[i+1][j+1])%mod;
            if(i < j){
                add(i,i,max(i,l[j]),max(i,r[j]),g[i][j]*inv[r[j]-l[j]+1]%mod);
                add(min(l[j],i),min(r[j],i),i,i,g[i][j]*inv[r[j]-l[j]+1]%mod);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) ans[j] = (ans[j]+g[i][j])%mod;
    for(int i=2;i<=n;i++) cout << ans[i] << " ";
    return 0;
}
