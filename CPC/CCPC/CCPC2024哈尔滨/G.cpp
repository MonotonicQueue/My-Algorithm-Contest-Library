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
const int N = 5e5+10;
int n,m,k;
int a[N],fa[N];
bool flag[N];
vector<int> G[N];
vector<pair<int,vector<int>>>ans;
bool vis[N];
void dfs(int x){
    vector<int> v;
    for(int y : G[x]) if(!vis[y]) v.push_back(y),vis[y] = true;
    if(v.size()) ans.push_back(mk(x,v));
    for(int y : v){
        if(flag[y]) continue;
        dfs(y);
    }
}
void solve(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=k;i++) a[i] = read();
    for(int i=1;i<=k;i++) flag[a[i]] = 1;
    if(k == n){
        puts("No");
        return ;
    }
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=1;i<=m;i++){
        int x = read(),y = read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int x = 0;
    for(int i=1;i<=n;i++)
        if(!flag[i]) x = i;
    vis[x] = true;
    dfs(x);
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            puts("No");
            return ;
        }
    puts("Yes");
    cout << ans.size() << "\n";
    for(auto &it : ans){
        cout << it.fi << " ";
        cout << it.se.size() << " ";
        for(int y : it.se) cout << y << " ";
        cout << "\n";
    }
}
signed main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
