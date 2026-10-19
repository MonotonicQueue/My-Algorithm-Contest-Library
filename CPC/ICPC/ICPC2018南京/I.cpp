#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1e3+10;
const int M = 1e6+10;
const ll inf = 1e18;
int S,T;
namespace MCMF{
    int n,tot=1;
    int head[N],nxt[M],to[M];
    ll edge[M];
    inline void add_edge(int u,int v,ll w){
        to[++tot] = v; nxt[tot] = head[u];
        head[u] = tot; edge[tot] = w;
        to[++tot] = u; nxt[tot] = head[v];
        head[v] = tot; edge[tot] = 0;
    }
    int dep[N],now[N];
    bool bfs(){
        memset(dep,0,sizeof(dep));
        queue<int> q;
        q.push(S); now[S] = head[S]; dep[S] = 1;
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
    ll dinic(int x,ll flow){
        if(x == T) return flow;
        ll rest = flow;
        for(int i=now[x];i && rest;i=nxt[i]){
            int y = to[i];
            now[x] = i;
            if(dep[y] != dep[x]+1 || !edge[i]) continue;
            ll k = dinic(y,min(edge[i],rest));
            if(!k) dep[y] = 0;
            edge[i] -= k;
            edge[i^1] += k;
            rest -= k;
        }
        return flow-rest;
    }
    ll MCMF(){
        ll ans = 0;
        while(bfs()) ans += dinic(S,inf);
        return ans;
    }
}
int n,m,k;
int main(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=n;i++){
        int t = read();
        while(t--){
            int x = read();
            MCMF::add_edge(i,x+n,1);
        }
    }
    S = n+m+1; T = n+m+2;
    int C = T+1;
    MCMF::add_edge(S,C,k);
    for(int i=1;i<=n;i++) MCMF::add_edge(S,i,1);
    for(int i=1;i<=n;i++) MCMF::add_edge(C,i,1);
    for(int i=1;i<=m;i++) MCMF::add_edge(i+n,T,1);
    cout << MCMF::MCMF();
	return 0;
}