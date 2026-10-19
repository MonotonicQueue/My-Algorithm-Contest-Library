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
const int N = 4e5+10;
const int M = 2e6+10;
const int inf = 1e9;
int S,T;
int n1,n2,m,Q;
struct Graph{
    int head[N],to[M],nxt[M],edge[M],tot=1;
    inline void add_edge(int u,int v,int w){
        to[++tot] = v; nxt[tot] = head[u];
        edge[tot] = w; head[u] = tot;
        to[++tot] = u; nxt[tot] = head[v];
        edge[tot] = 0; head[v] = tot; 
    }
    int dep[N],now[N];
    bool bfs(){
        for(int i=0;i<=T;i++) dep[i] = 0;
        dep[S] = 1;
        queue<int> q;
        q.push(S); now[S] = head[S];
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int i=head[x];i;i=nxt[i]){
                int y = to[i];
                if(dep[y] || !edge[i]) continue;
                dep[y] = dep[x]+1;
                now[y] = head[y];
                if(y == T) return true;
                q.push(y);
            }
        }
        return false;
    }
    int dinic(int x,int flow){
        if(x == T) return flow;
        int rest = flow;
        for(int i=now[x];i && rest;i=nxt[i]){
            int y = to[i]; now[x] = i;
            if(dep[y] != dep[x]+1 || !edge[i]) continue;
            int k = dinic(y,min(edge[i],rest));
            if(!k) dep[y] = 0;
            edge[i] -= k;
            edge[i^1] += k;
            rest -= k;
        }
        return flow-rest;
    }
    int maxflow(){
        int flow = 0;
        while(bfs()) flow += dinic(S,inf);
        return flow; 
    }
}G1,G2;
struct Edge{
    int u,v;
}e[N];
int I,IC,L[N],R[N],bel[N];
int sgn(int x){
    if(x > 0) return 1;
    if(x == 0) return 0;
    return -1;
}
map<pii,int> mp;
int eid[N]; ll sum[N];
int main(){
    n1 = read(); n2 = read();
    m = read(); Q = read();
    S = 0; T = n1+n2+1;
    for(int i=1;i<=n1;i++) G1.add_edge(S,i,1);
    for(int i=1;i<=n2;i++) G1.add_edge(i+n1,T,1);
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        e[i] = {u,v+n1};
        G1.add_edge(u,v+n1,1);
    }
    int maxflow = G1.maxflow();
    for(int i=1;i<=n1;i++){
        if(G1.dep[i] == 0) L[++IC] = i,bel[i] = IC;
        else R[++I] = i,bel[i] = -I;
    }
    for(int i=1;i<=n2;i++){
        if(G1.dep[i+n1] == 0) R[++I] = -i,bel[i+n1] = -I;
        else L[++IC] = -i,bel[i+n1] = IC;
    }
    for(int i=1;i<=IC;i++) G2.add_edge(S,i,1);
    for(int i=1;i<=I;i++) G2.add_edge(i+IC,T,1);
    for(int i=1;i<=m;i++){
        if(sgn(bel[e[i].u]) == sgn(bel[e[i].v])) continue;
        e[i].u = bel[e[i].u]; e[i].v = bel[e[i].v];
        if(e[i].u < 0) swap(e[i].u,e[i].v);
        G2.add_edge(e[i].u,IC-e[i].v,1);
        mp[mk(e[i].u,IC-e[i].v)] = i;
    }
    int flow = G2.maxflow();
    for(int i=1;i<=IC;i++){
        for(int j=G2.head[i];j;j=G2.nxt[j]){
            int y = G2.to[j];
            if(G2.edge[j]) continue;
            eid[i] = mp[mk(i,y)];
            sum[i] = sum[i-1]+eid[i];
        }
    }

    while(Q--){
        int op = read();
        if(op == 1){
            cout << "1\n";
            cout << L[flow] << "\n";
            cout << sum[--flow] << endl;
        }else{
            cout << flow << "\n";
            for(int i=1;i<=flow;i++)
                cout << eid[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
