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
int n,m,q;
struct Edge{int u,v,id;}e[N];
vector<int> G[N];
int low[N],dfn[N],cnt;
int stk[N],top; bool ins[N];
int scc[N],num_scc;
void tarjan(int x){
    dfn[x] = low[x] = ++cnt;
    stk[++top] = x; ins[x] = true;
    for(int y : G[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }else if(ins[y]) low[x] = min(low[x],dfn[y]);
    }
    if(low[x] == dfn[x]){
        num_scc++;
        int z = stk[top];
        do{
            z = stk[top--];
            ins[z] = false;
            scc[z] = num_scc;
        }while(z != x);
    }
}
vector<int> A[N];
void solve(int l,int r,vector<Edge> E){
    cnt = 0; num_scc = 0;
    for(auto it : E){
        low[it.u] = low[it.v] = dfn[it.u] = dfn[it.v] = 0;
        G[it.u].clear(); G[it.v].clear();
    }
    int mid = (l+r) >> 1;
    for(auto it : E)
        if(it.id <= mid) G[it.u].push_back(it.v);
    for(auto it : E){
        if(!dfn[it.u]) tarjan(it.u);
        if(!dfn[it.v]) tarjan(it.v);
    }
    if(l == r){
        for(auto it : E)
            if(scc[it.u] == scc[it.v]) A[mid].push_back(it.id);
        return ;
    }
    vector<Edge> El,Er;
    for(auto it : E){
        if(scc[it.u] == scc[it.v]){
            if(it.id <= mid) El.push_back(it);
        }else Er.push_back(Edge{scc[it.u],scc[it.v],it.id});
    }
    solve(l,mid,El); solve(mid+1,r,Er);
}
int fa[N],siz[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
ll ans;
ll squ(ll x){
    return x > 1 ? x*x : 0;
}
inline void merge(int u,int v){
    u = get(u); v = get(v);
    if(u == v) return ;
    ans -= squ(siz[u])+squ(siz[v]);
    fa[v] = u;
    siz[u] += siz[v];
    ans += squ(siz[u]);
}
int main(){
    n = read(); m = read(); q = read();
    vector<Edge> E;
    for(int i=1;i<=q;i++){
        int u = read(),v = read();
        char ch; cin >> ch;
        if(ch == 'R') E.push_back(e[i] = Edge{v+n,u,i});
        else E.push_back(e[i] = Edge{u,v+n,i});
    }
    for(int i=1;i<=n+m;i++) fa[i] = i,siz[i] = 1;
    solve(1,q,E);
    for(int i=1;i<=q;i++){
        for(auto it : A[i])
            merge(e[it].u,e[it].v);
        cout << ans << "\n";
    }
	return 0;
}
