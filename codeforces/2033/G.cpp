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
const int N = 2e5+10;
int n;
vector<int> G[N];
int dep[N],mxdep[N],secdep[N],pos[N];
int fa[N][20],mx[N][20];
void dfs0(int x,int ft){
    dep[x] = mxdep[x] = dep[ft]+1;
    secdep[x] = 0;
    pos[x] = x;
    for(int y : G[x]){
        if(y == ft) continue;
        dfs0(y,x);
        if(mxdep[y] > mxdep[x]) secdep[x] = mxdep[x],mxdep[x] = mxdep[y],pos[x] = y;
        else if(mxdep[y] > secdep[x]) secdep[x] = mxdep[y];
    }
}
void dfs1(int x,int ft){
    fa[x][0] = ft;
    for(int i=1;i<19;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    if(pos[ft] != x) mx[x][0] = mxdep[ft]-dep[ft]+1;
    else mx[x][0] = secdep[ft]-dep[ft]+1;
    for(int i=1;i<19;i++) mx[x][i] = max(mx[x][i-1],mx[fa[x][i-1]][i-1]+(1 << (i-1)));
    for(int y : G[x]){
        if(y == ft) continue;
        dfs1(y,x);
    }
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1,0); dfs1(1,0);
    int Q = read();
    while(Q--){
        int u = read(),k = read();
        int ans = mxdep[u]-dep[u],sum = 0;
        k = min(k,dep[u]-1);
        for(int i=19;~i;i--){
            if((k >> i) & 1){
                ans = max(ans,mx[u][i]+sum);
                u = fa[u][i];
                sum += 1 << i;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
5
1 2
2 3
3 4
3 5
3
5 1
3 1
2 0
*/
