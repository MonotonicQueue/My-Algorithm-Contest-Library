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
const int N = 3100;
int n,mod;
inline void add(ll &x,ll y){x = x+y >= mod ? x+y-mod : x+y;}
inline void del(ll &x,ll y){x = x-y < 0 ? x-y+mod : x-y;}
ll f[N][N][2],g[N][N],val[N],ans[N];
void clear(){
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++) f[i][j][0] = f[i][j][1] = g[i][j] = 0;
    for(int i=0;i<=n;i++) ans[i] = val[i] = 0;
}
void solve(){
    n = read(); mod = read();
    clear();
    for(int i=1;i<=n;i++){
        val[i] = 1;
        for(int j=1;j<=i;j++) val[i] = val[i]*(n-max(j,i-j+1)+1)%mod;
    }
    f[1][n][0] = 1;
    for(int len=n-1;len;len--)
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            ll w = n-len;
            if(i > 1)
                add(f[i][j][0],(f[i-1][j][0]+f[i-1][j][1])*w%mod);
            if(j < n){
                add(f[i][j][1],f[i][j+1][0]);
                add(f[i][j][1],w*f[i][j+1][1]%mod);
            }
        }
    for(int len=n;len;len--)
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            g[i][j] = (f[i][j][0]+f[i][j][1])*val[len]%mod;
        }
    for(int len=1;len<=n;len++)
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            del(g[i][j],(g[i-1][j]+g[i][j+1]+mod-g[i-1][j+1])%mod);
            add(ans[len],g[i][j]);
        }
    ans[0] = 1;
    for(int i=1;i<=n;i++) ans[0] = ans[0]*n%mod;
    for(int i=1;i<=n;i++) del(ans[0],ans[i]);
    for(int i=0;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 
/*
1
3 998244353
*/