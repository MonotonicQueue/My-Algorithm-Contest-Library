// LUOGU_RID: 165142403
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
int n,m;
int deg[N];
vector<int> G[N],to[N];
bool vis[N],ins[N];
void dfs(int x){
    vis[x] = ins[x] = true;
    for(int y : G[x]){
        if(!ins[y]) to[x].push_back(y),deg[y]++;
        if(!vis[y]) dfs(y);
    }
    ins[x] = false;
}
vector<int> q;
bool ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    return read();
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    for(int i=1;i<=n;i++) if(!deg[i]) q.push_back(i);
    while(q.size() > 1){
        int u = q.back(); q.pop_back();
        int v = q.back(); q.pop_back();
        if(!ask(u,v)) swap(u,v);
        q.push_back(u);
        for(int t : to[v])
            if(!--deg[t]) q.push_back(t);
    }
    printf("! %d",q.back());
	return 0;
}