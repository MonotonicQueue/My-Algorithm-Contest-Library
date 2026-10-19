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
const int N = 3e5+10;
int n,f[N];
vector<int> G[N];
vector<pii> ans;
void dfs(int x,int ft){
    f[x] = x;
    vector<int> v;
    for(int y : G[x]){
        if(y == ft) continue;
        dfs(y,x);
        v.push_back(f[y]);
    }
    if(v.size() & 1){
        f[x] = v.back();
        v.pop_back();
    }
    for(int i=0;i<(int)v.size();i+=2)
        ans.emplace_back(v[i],v[i+1]);
}
void solve(){
    n = read();
    ans.clear();
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=2;i<=n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int rt = 0;
    for(int i=1;i<=n;i++)
        if(G[i].size() % 2 == 0) rt = i;
    if(!rt) return puts("-1"),void();
    dfs(rt,0);
    cout << ans.size() << "\n";
    for(auto [x,y] : ans) cout << x << " " << y << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}