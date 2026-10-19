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
const int N = 1e5+10;
int n,m,fa[N][20],dep[N];
vector<int> G[N];
int now[N];
bool flag;
void dfs(int x,int ft){
    fa[x][0] = ft;
    dep[x] = dep[ft]+1;
    for(int i=1;i<=19;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    for(int y : G[x]){
        if(y == ft) continue;
        dfs(y,x);
    }
}
int get(int x,int y){
    for(int i=19;~i;i--)
        if((dep[x]-y) >= (1<<i)) x = fa[x][i];
    return x;
}
void dfs1(int x){
    now[x] = x <= m ? x%m+1 : 0;
    for(int y : G[x]){
        if(y == fa[x][0]) continue;
        dfs1(y);
        if(!now[x]) now[x] = get(now[y],dep[x]);
        else if(now[x] != get(now[y],dep[x])) flag = true;
    }
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    flag = false;
    dfs(n,0);
    dfs1(n);
    puts(flag ? "Tie" : "Doddle");
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 
