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
int n,m,a[N],b[N],c[N],val[N];
int f[N][32];
mt19937 rnd(time(0));
struct BIT{
    int t[N];
    inline void clear(){
        for(int i=1;i<=n;i++) t[i] = -1e9;
    }
    void add(int x,int y){
        while(x <= n){
            t[x] = max(t[x],y);
            x += x&(-x);
        }
    }
    int ask(int x){
        int res = -1e9;
        while(x){
            res = max(res,t[x]);
            x -= x&(-x);
        }
        return res;
    }
}T[32];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    for(int i=1;i<=n;i++) c[i] = read();
    int _ = 300,ans = -1;
    while(_--){
        for(int i=1;i<=n;i++) val[i] = rnd()%m;
        for(int i=0;i<(1<<m);i++) T[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=0;j<(1<<m);j++) f[i][j] = -1e9;
        f[0][0] = 0;
        T[0].add(1,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<m);j++)
                if((j >> val[b[i]]) & 1)
                    f[i][j] = T[j^(1<<val[b[i]])].ask(a[i])+c[i];
            for(int j=0;j<(1<<m);j++)
                if((j >> val[b[i]]) & 1) T[j].add(a[i],f[i][j]);
            ans = max(ans,f[i][(1<<m)-1]);
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
