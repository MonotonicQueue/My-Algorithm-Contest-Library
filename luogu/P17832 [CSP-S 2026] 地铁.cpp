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
const int M = 5e5+10;
const int N = 510;
int n,m,Q;
ll w[M],d[N][N];
vector<pair<int,ll>> v[M]; 
void solve(){
    read(); n = read(); m = read(); read(); Q = read();
    for(int i=1;i<=m;i++) w[i] = read();
    for(int i=1;i<=n;i++){
        int k = read();
        while(k--){
            int a = read(),t = read();
            v[a].emplace_back(i,t);
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;i++)
        for(auto &[x,u] : v[i])
            for(auto &[y,v] : v[i])
                d[x][y] = min(d[x][y],u+v);
    for(int i=1;i<=n;i++) d[i][i] = 0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    while(Q--){
        int i = read(),j = read();
        ll ans = 9e18;
        for(auto &[x,u] : v[i])
            for(auto &[y,v] : v[j]){
                ans = min(ans,d[x][y]+u+v);
            }
        cout << ans+w[i]+w[j] << "\n";
    }
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
