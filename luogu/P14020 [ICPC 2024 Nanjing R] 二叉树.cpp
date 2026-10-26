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
bool flag;
int ask(int x,int y){
    cout << "? " << x << " " << y << endl;
    return read();
}
void answer(int x){
    cout << "! " << x << endl;
}
const int N = 1e5+10;
int n,TTT;
vector<int> G[N],E[N];
int siz[N],rt,S,mn;
bool vis[N];
void getroot(int x,int ft){
    siz[x] = 1;
    int mxpart = 0;
    for(int y : E[x]){
        if(y == ft || vis[y]) continue;
        getroot(y,x);
        siz[x] += siz[y];
        mxpart = max(mxpart,siz[y]);
    }
    mxpart = max(mxpart,S-siz[x]);
    if(mxpart <= mn) rt = x,mn = mxpart;
}
void dfs(int x,int ft){
    siz[x] = 1;
    for(int y : E[x]){
        if(y == ft || vis[y]) continue;
        dfs(y,x);
        siz[x] += siz[y];
    }
}
void rebuild(){
    for(int i=1;i<=n;i++){
        E[i].clear();
        if(vis[i]) continue;
        for(int y : G[i]) if(!vis[y]) E[i].push_back(y);
    }
}
void solve(int x){
    // cout << x << "\n";
    rebuild();
    dfs(x,0);
    S = mn = siz[x]; rt = 0;
    getroot(x,0);
    x = rt;
    vis[x] = true;
    sort(E[x].begin(),E[x].end(),[](int x,int y){return siz[x] < siz[y];});
    if(E[x].size() == 3){
        int a = E[x][2],b = E[x][1],c = E[x][0];
        int t = ask(a,b);
        if(t == 0) return vis[b] = vis[c] = true,solve(a);
        if(t == 2) return vis[a] = vis[c] = true,solve(b);
        vis[x] = false;
        vis[a] = vis[b] = true;
        return solve(c);
    }
    if(E[x].size() == 1){
        int y = E[x][0];
        if(siz[y] == 1){
            int t = ask(x,y);
            if(t == 0) answer(x);
            else answer(y);
            return ;
        }
        vis[x] = false;
        return solve(y);
    }
    if(E[x].size() == 2){
        int a = E[x][0],b = E[x][1];
        int t = ask(a,b);
        if(t == 0) return vis[b] = true,solve(a);
        if(t == 2) return vis[a] = true,solve(b);
    }
    return answer(x);
}
void sol(){
    n = read();
    for(int i=1;i<=n;i++) G[i].clear(),vis[i] = false;
    for(int i=1;i<=n;i++){
        int u = read(),v = read();
        if(u) G[i].push_back(u),G[u].push_back(i);
        if(v) G[i].push_back(v),G[v].push_back(i);
    }
    rebuild();
    solve(1);
}
int main(){
    int T = read();
    while(T--) sol();
	return 0;
} 