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
const int M = 1e6+10;
const int inf = 1e9;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
const char str[4] = {'U','L','D','R'};
int n,m,a[N],b[N];
char op[N];
int S,T,SS,TT;
int head[N],to[M],nxt[M],edge[M],tot=1;
inline int id(int x,int y){
    return (x-1)*m+y;
}
inline void add_edge(int u,int v,int w){
    to[++tot] = v; nxt[tot] = head[u];
    edge[tot] = w; head[u] = tot;
    to[++tot] = u; nxt[tot] = head[v];
    edge[tot] = 0; head[v] = tot;  
}
int dep[N],now[N];
inline bool bfs(){
    for(int i=1;i<=TT;i++) dep[i] = 0;
    queue<int> q; 
    q.push(SS); dep[SS] = 1; now[SS] = head[SS];
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=head[x];i;i=nxt[i]){
            int y = to[i];
            if(dep[y] || !edge[i]) continue;
            dep[y] = dep[x]+1; now[y] = head[y];
            if(y == TT) return true;
            q.push(y);
        }
    }
    return false;
}
int dinic(int x,int flow){
    if(x == TT) return flow;
    int rest = flow;
    for(int i=now[x];i;i=nxt[i]){
        now[x] = i;
        int y = to[i];
        if(!edge[i] || dep[y] != dep[x]+1) continue;
        int k = dinic(y,min(rest,edge[i]));
        if(!k) dep[y] = 0;
        edge[i] -= k;
        edge[i^1] += k;
        rest -= k;
        if(!rest) return flow;
    }
    return flow-rest;
}
inline void clear(){
    for(int i=1;i<=TT;i++) head[i] = 0;
    for(int i=1;i<=n*m;i++) b[i] = 0;
    tot = 1;
}
bool vis[N];
inline void solve(){
    n = read(); m = read();
    for(int i=1;i<=n*m;i++) a[i] = read();
    S = n*m+1; T = n*m+2; SS = n*m+3; TT = n*m+4;
    int sum = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        vis[id(i,j)] = true;
        for(int k=0;k<4;k++){
            int x = i+dx[k],y = j+dy[k];
            if(x < 1 || y < 1 || x > n || y > m) continue;
            if(a[id(x,y)] < a[id(i,j)]) vis[id(i,j)] = false;
        }
        sum += vis[id(i,j)];
    }
    // cout << sum << "\n";
    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=m;j++) cout << vis[id(i,j)];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if((i+j) & 1){
            if(vis[id(i,j)]) add_edge(SS,id(i,j),1),add_edge(S,TT,1);
            else add_edge(S,id(i,j),1);
            for(int k=0;k<4;k++){
                int x = i+dx[k],y = j+dy[k];
                if(x < 1 || y < 1 || x > n || y > m) continue;
                if(a[id(x,y)] == a[id(i,j)]) add_edge(id(i,j),id(x,y),1);
            }
        }else{
            if(vis[id(i,j)]) add_edge(id(i,j),TT,1),add_edge(SS,T,1);
            else add_edge(id(i,j),T,1);
        }
    }
    add_edge(T,S,inf);
    int flow = 0;
    while(bfs()) flow += dinic(SS,inf);
    if(flow != sum) return puts("NO"),void();
    puts("YES");
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if((i+j) & 1){
            int u = id(i,j);
            for(int I=head[id(i,j)];I;I=nxt[I]){
                int v = to[I];
                if(v > n*m || edge[I]) continue;
                b[u] = 1; b[v] = a[u]-1;
                for(int k=0;k<4;k++){
                    int x = i+dx[k],y = j+dy[k];
                    if(id(x,y) == v){
                        op[u] = str[k];
                        op[v] = str[k^2];
                        break;
                    }
                }
            }
        }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(!b[(id(i,j))]){
            for(int k=0;k<4;k++){
                int x = i+dx[k],y = j+dy[k];
                if(x < 1 || y < 1 || x > n || y > m) continue;
                if(a[id(x,y)] < a[id(i,j)]){
                    b[id(i,j)] = a[id(i,j)]-a[id(x,y)];
                    op[id(i,j)] = str[k];
                    break;
                }
            }
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",b[id(i,j)]);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c ",op[id(i,j)]);
        putchar('\n');
    }
    clear();
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}
