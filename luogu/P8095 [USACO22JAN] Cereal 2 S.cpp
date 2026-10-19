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
int n,m,f[N];
vector<pii> G[N];
bool vis[N],flag[N],vs[N];
int cntV[N],cntE[N],bel[N],tot,choose[N];
void dfs(int x,int fr){
    vis[x] = true; bel[x] = tot;
    cntV[tot]++;
    for(auto &[y,i] : G[x]){
        if(i == fr) continue;
        cntE[tot]++;
        if(!vis[y]) dfs(y,i),flag[i] = true;
    }
}
void dfs0(int x,int ft){
    for(auto [y,i] : G[x]){
        if(!flag[i] || y == ft) continue;
        vs[i] = true;
        cout << i << "\n";
        dfs0(y,x);
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        int x = read(),y = read();
        f[i] = x;
        G[x].emplace_back(y,i);
        G[y].emplace_back(x,i);
    }
    for(int i=1;i<=m;i++){
        if(vis[i]) continue;
        ++tot;
        dfs(i,0);
    }
    for(int i=1;i<=n;i++)
        if(!flag[i]) choose[bel[f[i]]] = i;
    int ans = m;
    for(int i=1;i<=tot;i++)
        if(cntV[i] == cntE[i]+1) ans--;
    for(int i=1;i<=m;i++)
        if(cntV[bel[i]] == cntE[bel[i]]+1) choose[bel[i]] = i;
    cout << n-ans << '\n';
    for(int i=1;i<=tot;i++){
        if(cntV[i] == cntE[i]+1) dfs0(choose[i],0);
        else{
            cout << choose[i] << "\n";
            vs[choose[i]] = true;
            dfs0(f[choose[i]],0);
        }
    }
    for(int i=1;i<=n;i++)
        if(!vs[i]) cout << i << "\n";
	return 0;
} 