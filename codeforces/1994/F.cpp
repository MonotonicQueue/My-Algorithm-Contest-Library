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
int n,m;
vector<int> G[N];
int head[N],now[N],nxt[N<<1],to[N<<1],tot=1;
int deg[N],edge[N];
inline void add_edge(int u,int v){
    // cout << u << " " << v << "\n";
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
bool vis[N],vs[N];
void dfs1(int x){
    vis[x] = true;
    for(int i : G[x]){
        int y = edge[i] ^ x;
        if(edge[i] == -1 || vis[y]) continue;
        dfs1(y);
        if(deg[y]) deg[y] ^= 1,deg[x] ^= 1,edge[i] = -1;
    }
}
vector<int> ans;
void dfs2(int x){
    for(int i=now[x];i;i=now[x]){
        int y = to[i];
        now[x] = nxt[i];
        if(vs[i/2]) continue;
        vs[i/2] = true;
        dfs2(y);
    }
    ans.push_back(x);
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        auto clear = [&](){
            for(int i=1;i<=n;i++)
                head[i] = 0,G[i].clear(),deg[i] = 0;
            for(int i=1;i<=n;i++) vis[i] = false;
            for(int i=1;i<=m;i++) vs[i] = false;
            tot = 1;
        };
        clear();
        for(int i=1;i<=m;i++){
            int u = read(),v = read(),c = read();
            deg[u] ^= 1; deg[v] ^= 1;
            edge[i] = u^v;
            if(!c) G[u].push_back(i),G[v].push_back(i);
            else add_edge(u,v),add_edge(v,u);
        } 
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs1(i);
                flag |= deg[i];
            }
        }
        if(flag){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j : G[i]){
                if(edge[j] == -1) continue;
                int y = edge[j] ^ i;
                add_edge(i,y); add_edge(y,i);
                edge[j] = -1;
            }
        }
        for(int i=1;i<=n;i++) now[i] = head[i];
        ans.clear();
        dfs2(1);
        cout << ans.size()-1 << "\n";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
