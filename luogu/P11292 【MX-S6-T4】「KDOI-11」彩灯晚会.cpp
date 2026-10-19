#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 310;
const int M = 22;
const int mod = 998244353;
ll fpow(ll x,ll k){
    if(k < 0) k += mod-1;
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
int id,n,K,L,m;
vector<pii> G[N];
int deg[N],ord[N];
void topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!deg[i]) q.push(i);
    int tot = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        ord[++tot] = x;
        for(auto [y,w] : G[x]){
            deg[y]--;
            if(!deg[y]) q.push(y);
        }
    }
}
ll g[N][N][M],st[N][M],ed[N][M],f[N][M][M],h[N][M][M];
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
double str = clock();
int main(){
    // freopen("party.in","r",stdin);
    // freopen("party.out","w",stdout);
    id = read(); n = read(); K = read(); L = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),w = read();
        G[u].emplace_back(v,w);
        deg[v]++;
    }
    topsort();
    for(int i=1;i<=n;i++){
        int x = ord[i];
        g[x][x][1] = 1;
        for(int j=i;j<=n;j++){
            int y = ord[j];
            for(int k=1;k<L;k++) if(g[x][y][k])
                for(auto [t,w] : G[y])
                    add(g[x][t][k+1],g[x][y][k]*w%mod);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=L;k++){
                add(st[i][k],g[i][j][k]);
                add(ed[j][k],g[i][j][k]);
            }
    for(int i=1;i<=n;i++){
        int x = ord[i];
        for(int l1=1;l1<=L;l1++) if(ed[x][l1])
            for(int l2=1;l2<=L;l2++) add(f[x][l1][l2],ed[x][l1]*ed[x][l2]%mod*(K-1)%mod);
        memset(h,0,sizeof(h));
        for(int j=i+1;j<=n;j++){
            int y = ord[j];
            for(int l1=1;l1<=L;l1++) for(int l2=1;l2<=L;l2++) if(f[x][l1][l2])
            for(int t=1;t+l1<=L;t++) add(h[y][l1+t][l2],f[x][l1][l2]*g[x][y][t+1]%mod);
        }
        for(int j=i+1;j<=n;j++){
            int y = ord[j];
            for(int l1=1;l1<=L;l1++) for(int l2=1;l2<=L;l2++) if(h[y][l1][l2])
            for(int t=1;t+l2<=L;t++) add(f[y][l1][l2+t],h[y][l1][l2]*g[x][y][t+1]%mod*(K-1)%mod);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) add(ans,g[i][j][L]);
    ans = ans*ans%mod;
    for(int i=1;i<=n;i++) 
        for(int l1=1;l1<=L;l1++) if(st[i][L-l1+1])
            for(int l2=1;l2<=L;l2++) add(ans,f[i][l1][l2]*st[i][L-l1+1]%mod*st[i][L-l2+1]%mod);
    cout << ans*fpow(K,n-2*L+1)%mod;
    return 0;
}