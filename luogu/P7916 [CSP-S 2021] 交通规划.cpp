#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 1010;
const int M = 2e6+10;
const ll INF = 1e18;
int n,m,TTT,cnt,sum;
int a[N][N],b[N][N],pos[M];
inline int id(int x,int y){
    return (x-1)*(m-1)+y+2*(n+m);
}
int head[M],nxt[M],to[M],tot=1;
ll edge[M],w[M];
int k;
struct node{int p,x,t;}c[N];
inline void add_edge(int u,int v,ll w){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot; edge[tot] = w;
    to[++tot] = u; nxt[tot] = head[v];
    head[v] = tot; edge[tot] = w;
}
inline void clear(){
    tot = 1; cnt = n*m+2*(n+m);
    sum = 0;
    for(int i=1;i<=cnt;i++) head[i] = 0;
    for(int i=1;i<=2*(n+m);i++) w[i] = pos[i] = 0;
}
ll dis[M],f[N][N],g[N][N];
bool vis[M];
void dijkstra(int st){
    for(int i=1;i<=cnt;i++) dis[i] = INF,vis[i] = false;
    dis[st] = 0;
    priority_queue<pli> q;
    q.push(mk(-dis[st],st));
    while(!q.empty()){
        int x = q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        if(pos[x]) g[pos[st]][pos[x]] = dis[x];
        for(int i=head[x];i;i=nxt[i]){
            int y = to[i];
            if(dis[x]+edge[i] < dis[y]){
                dis[y] = dis[x]+edge[i];
                q.push(mk(-dis[y],y));
            }
        }
    }
}
int V[N];
void solve(){
    clear();
    k = read();
    for(int i=1;i<=k;i++){
        c[i].x = read(); c[i].p = read(); 
        c[i].t = read(); w[c[i].p] = c[i].x;
    }
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m;j++)
            add_edge(id(i,j),id(i+1,j),b[i+1][j]);
    for(int i=1;i<n;i++)
        for(int j=1;j<m-1;j++)
            add_edge(id(i,j),id(i,j+1),a[i][j+1]);
    for(int i=1;i<m;i++) add_edge(i,id(1,i),b[1][i]);
    for(int i=1;i<n;i++) add_edge(i+m,id(i,m-1),a[i][m]);
    for(int i=1;i<m;i++) add_edge(i+n+m,id(n-1,m-i),b[n][m-i]);
    for(int i=1;i<n;i++) add_edge(i+2*m+n,id(n-i,1),a[n-i][1]);
    for(int i=2;i<=2*(n+m);i++) add_edge(i-1,i,w[i]);
    add_edge(1,2*(n+m),w[1]);

    sort(c+1,c+1+k,[](node x,node y){return x.p < y.p;});
    for(int i=k+1;i<2*k;i++) c[i] = c[i-k];
    int pp = 0;
    for(int i=2;i<2*k;i++){
        if(c[i].t != c[i-1].t){
            pp = i;
            break;
        }
    }
    if(!pp){
        cout << "0\n";
        return ;
    }
    for(int i=pp;i<=pp+k-1;i++){
        if(c[i].t != c[i-1].t){
            V[++sum] = c[i-1].p;
            pos[c[i-1].p] = sum;
        }
    }
    for(int i=1;i<=sum;i++) dijkstra(V[i]);
    ll ans = INF;
    for(int i=1;i<=2*sum;i++) f[i][i] = INF;
    for(int len=2;len<=sum;len++)
        for(int i=1;i+len-1<=2*sum-1;i++){
            int j = i+len-1;
            f[i][j] = g[(i-1)%sum+1][(j-1)%sum+1]+f[i+1][j-1];
            for(int k=i;k<j;k++) f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
            if(len == sum) ans = min(ans,f[i][j]);
        }
    cout << ans << "\n";
}
signed main(){
    n = read(); m = read(); TTT = read();
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++) b[i][j] = read();
    while(TTT--) solve();
    return 0;
}