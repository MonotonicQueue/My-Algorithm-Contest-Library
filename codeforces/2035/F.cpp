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
const int N = 2100;
int n,rt;
ll a[N],b[N],f[N];
vector<int> G[N];
void dfs(int x,int fa){
    f[x] = a[x]-b[x];
    for(int &y : G[x]){
        if(y == fa) continue;
        dfs(y,x);
        f[x] += f[y];
    }
    if(f[x] < 0) f[x] = (-f[x])&1;
}
int main(){
    int T = read();
    while(T--){
        n = read(); rt = read();
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=2;i<=n;i++){
            int u = read(),v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ll ans = 1e18;
        for(int i=0;i<2*n;i++){
            ll l = 0,r = 1e9,res = -1;
            while(l <= r){
                ll mid = (l+r) >> 1;
                for(int j=1;j<=n;j++)
                    if(i > n) b[j] = 2*mid+1+(j <= (i-n));
                    else b[j] = 2*mid+(j <= i);
                dfs(rt,0);
                if(!f[rt]) res = mid,r = mid-1;
                else l = mid+1;
            }
            if(res != -1) ans = min(ans,res*2*n+i);
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
2 1
1 2
1 2
*/