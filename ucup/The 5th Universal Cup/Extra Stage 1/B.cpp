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
const int N = 1e6+10;
const int mod = 998244353;
int n,m;
int col[N],t[2];
vector<int> G[N];
bool FLAG;
ll pw2[N];
void dfs(int x,int now){
    if(!FLAG) return ;
    if(col[x] != -1){
        if(col[x] != now) FLAG = false;
        return ;
    }
    col[x] = now;
    t[now]++;
    for(int y : G[x]) dfs(y,now^1);
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) G[i].clear(),col[i] = -1;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = 1;
    FLAG = true;
    for(int x=1;x<=n;x++){
        if(col[x] != -1) continue;
        t[0] = t[1] = 0;
        dfs(x,0);
        ans = ans*(pw2[t[0]]+pw2[t[1]]-2)%mod;
    }
    ans *= FLAG;
    cout << ans << "\n";
}
int main(){
    pw2[0] = 1;
    for(int i=1;i<=1000000;i++) pw2[i] = pw2[i-1]*2%mod;
    int T = read();
    while(T--) solve();
    return 0;
}
