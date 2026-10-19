#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 2e5+10;
const int M = 2010;
const ll inf = 1e18;
int n,m,V;
struct BIT{
    ll t[M];
    void init(){
        for(int i=0;i<=V;i++) t[i] = -inf;
    }
    void add(int x,ll y){
        if(!x) t[x] = max(t[x],y);
        else while(x <= V){
            t[x] = max(t[x],y);
            x += x&(-x);
        }
    }
    ll ask(int x){
        ll res = t[0];
        while(x){
            res = max(res,t[x]);
            x -= x&(-x);
        }
        return res;
    }
}T[2][M];
ll f[M<<1][M];
void solve(){
    n = read(); m = read(); V = read();
    vector<ll> a(n+2),c(n+2);
    for(int i=1;i<=n;i++) c[i] = read();
    for(int i=1;i<=m;i++){
        char op; cin >> op;
        int x = read();
        if(op == 'L') a[1]++,a[x+1]--;
        else a[x]++;
    }
    for(int i=1;i<=n;i++) a[i] += a[i-1];
    
    vector<ll> b(n+1),val(n+1);
    int tot = 0;
    for(int i=1;i<=n;i++)
        if(a[i] <= V){
            if(tot && b[tot] == a[i]) val[tot] += c[i];
            else ++tot,b[tot] = a[i],val[tot] = c[i];
        }
    
    n = tot;
    for(int i=0;i<=V;i++) T[0][i].init(),T[1][i].init();
    for(int i=0;i<=n;i++) for(int j=0;j<=V;j++) f[i][j] = -inf;
    f[0][0] = 0;
    T[0][0].add(V,0);
    T[1][0].add(0,0);
    for(int i=1;i<=n;i++){
        for(int j=b[i];j<=V;j++)
            f[i][j] = max(T[0][j].ask(V-b[i]),T[1][j-b[i]].ask(b[i]))+val[i];
        for(int j=b[i];j<=V;j++){
            T[0][j].add(V-b[i],f[i][j]);
            T[1][j-b[i]].add(b[i],f[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=V;j++) f[i][j] = max(max(f[i][j],f[i][j-1]),max(f[i-1][j],f[i-1][j-1]));
    for(int i=1;i<=V;i++) cout << max(f[n][i],0ll) << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}