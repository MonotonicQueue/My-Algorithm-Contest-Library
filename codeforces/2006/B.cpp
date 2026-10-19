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
const int N = 1e6+10;
int n,dep[N],fa[N];
vector<int> G[N],v[N];
void dfs(int x){
    for(int y : G[x]){
        dep[y] = dep[x]+1;
        dfs(y);
    }
}
int sz[N];
void work(int id,int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    while(x != y){
        if(dep[x] > dep[y]){
            sz[id]++;
            v[x].push_back(id);
            x = fa[x];
        }else{
            sz[id] += 2;
            v[x].push_back(id);
            x = fa[x];
            v[y].push_back(id);
            y = fa[y];
        }
    }
}
void solve(){
    n = read(); ll w = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
        v[i].clear();
    }
    for(int i=2;i<=n;i++){
        fa[i] = read();
        G[fa[i]].push_back(i);
    }
    dep[1] = 1;
    dfs(1);
    for(int i=1;i<=n;i++) sz[i] = 0;
    for(int i=1;i<=n;i++){
        work(i,i,i%n+1);
    }
    ll ans = 0,sum = n;
    for(int i=1;i<n;i++){
        int x = read(); ll y = read();
        ans += 2*y; w -= y;
        for(int z : v[x]){
            sz[z]--;
            if(sz[z] == 0) sum--;
        }
        cout << ans+sum*w << " ";
    }
    cout << "\n";

}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}