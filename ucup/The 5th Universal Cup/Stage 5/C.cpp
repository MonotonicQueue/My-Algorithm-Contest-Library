#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 110;
const int mod = 998244353;
int n,m;
ll f[N][N][N*N/2],pw[N];
inline void add(ll &x,ll y){
    x = (x+y) >= mod ? (x+y-mod) : x+y;
}
void init(int n = 100){
    f[0][0][0] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i*(i+1)/2;k++){
                add(f[i+1][j][k+j],f[i][j][k]);
                add(f[i+1][j+1][k+j+1],f[i][j][k]);
            }
        }
    }
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*2%mod;
}
pii op[N];
ll g[N],tmp[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=m;i++) op[i].fi = read(),op[i].se = read();
    ll ans = 0;
    op[0] = mk(1,0);
    for(int i=0;i<=n;i++) g[i] = 0;
    g[0] = 1;
    for(int _=1;_<=m;_++){
        auto &[p,v] = op[_];
        auto &[lp,lv] = op[_-1];
        if(v > p*(p+1)/2 || (p == 1 && v != 0)){
            puts("0");
            return ;
        }
        for(int i=0;i<=p;i++){
            tmp[i] = 0;
        }
        // cerr << p << " " << lp << "\n";
        for(int i=0;i<=lp;i++){
            for(int j=0;j<=p-lp;j++){
                if(v-lv-i*(p-lp) >= 0)
                    add(tmp[i+j],g[i]*f[p-lp][j][v-lv-i*(p-lp)]%mod);
            }
        }
        for(int i=0;i<=p;i++) g[i] = tmp[i];
    }
    int p = op[m].fi;
    for(int i=0;i<=p;i++) add(ans,g[i]);
    ans = ans*pw[n-p]%mod;
    cout << ans << "\n";
}
int main(){
    init();
    int T = read();
    while(T--) solve();
    return 0;
}
