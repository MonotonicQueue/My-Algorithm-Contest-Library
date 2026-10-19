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
const int N = 110;
const int M = 1e6+10;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,m,S,T,cnt;
int a[N][N],b[N][N],c[N][N];
int head[M],to[M],nxt[M],tot=1;
ll edge[M],sum;
inline void add_edge(int u,int v,int w){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot; edge[tot] = w;
    to[++tot] = u; nxt[tot] = head[v];
    head[v] = tot; edge[tot] = 0;
}
inline int id(int x,int y){
    return (x-1)*m+y;
}
int now[M],dep[M];
bool bfs(){
//	for(int i=S;i<=T;i++) cout << dep[i] << " ";
//	cout << "\n";
    for(int i=S;i<=T;i++) dep[i] = 0;
    dep[S] = 1;
    queue<int> q; q.push(S);
    while(!q.empty()){
        int x = q.front(); q.pop();
        now[x] = head[x];
        for(int i=head[x];i;i=nxt[i]){
            int y = to[i];
            if(dep[y] || !edge[i]) continue;
//            cout << x << " " << y << " " << edge[i] << "\n";
            dep[y] = dep[x]+1; 
            q.push(y);
        }
    }
//    cout << dep[T] << "\n";
    return dep[T] > 0;
}
ll dinic(int x,ll flow){
    if(x == T) return flow;
    ll rest = flow;
    for(int i=now[x];i && rest;i=nxt[i]){
        int y = to[i]; now[x] = i;
        if(dep[y] != dep[x]+1 || !edge[i]) continue;
        ll k = dinic(y,min(rest,edge[i]));
        if(!k) dep[y] = 0;
        rest -= k;
        edge[i] -= k;
        edge[i^1] += k;
    }
    return flow-rest;
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) c[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if((i+j) & 1) swap(a[i][j],b[i][j]);
    S = 0,T = n*m+1;
    cnt = T;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum += a[i][j]+b[i][j],
            add_edge(S,id(i,j),a[i][j]),
            add_edge(id(i,j),T,b[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<4;k++){
                int x = i+dx[k],y = j+dy[k];
                if(1 <= x && x <= n && 1 <= y && y <= m){
                    sum += c[i][j];
                    add_edge(id(i,j),id(x,y),c[i][j]+c[x][y]);
                }
                    
            }
    while(bfs()) sum -= dinic(S,1e18);
    cout << sum;
	return 0;
}
