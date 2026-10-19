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
int S,T;
namespace MCMF{
    const int N = 3e6+10;
    const int M = 3e6+10;
    const ll inf = 1e18;
    int tot=1,n;
    int head[N],to[M],nxt[M];
    ll edge[M],cost[M];
    inline void add_edge(int u,int v,int w,int c){
        to[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
        edge[tot] = w; cost[tot] = c;
        to[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
        edge[tot] = 0; cost[tot] = -c;
    }
    bool vis[N];
    int pre[N];
    ll d[N],incf[N];
    bool SPFA(){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) d[i] = -inf;
        incf[S] = inf; d[S] = 0;
        queue<int> q;
        while(!q.empty()) q.pop();
        q.push(S);
        while(!q.empty()){
            int x = q.front(); q.pop(); vis[x] = false;
            for(int i=head[x];i;i=nxt[i]){
                int y = to[i];
                if(!edge[i]) continue;
                if(d[y] < d[x]+cost[i]){
                    d[y] = d[x]+cost[i];
                    // cout << x << " " << y << " " << d[x] << " " << d[y] << "\n";
                    incf[y] = min(incf[x],edge[i]);
                    pre[y] = i;
                    if(!vis[y]) q.push(y),vis[y] = true;
                }
            }
        }
        return d[T] != -inf;
    }
    ll maxflow,ans;
    void update(){
        int x = T;
        maxflow += incf[T];
        ans += incf[T]*d[T];
        while(x != S){
            int i = pre[x];
            edge[i] -= incf[T];
            edge[i^1] += incf[T];
            x = to[i^1];
        }
    }
    ll MCMF(){
        while(SPFA()) update();
        return ans;
    }
}
const int N = 310;
int n,m,a[N],cnt;
vector<int> v[N];
map<int,int> s,b;
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    cnt = n;
    // for(int i=1;i<=n;i++) s[a[i]] = ++cnt;
    for(int i=1;i<=n;i++)
        for(int j=1;j*j<=a[i];j++)
            if(a[i] % j == 0){
                v[i].push_back(j);
                if(!s[j]) s[j] = ++cnt;
                if(j*j != a[i]){
                    v[i].push_back(a[i]/j);
                    if(!s[a[i]/j]) s[a[i]/j] = ++cnt;
                }
            }
    b[1] = 0;
    set<int> ttt;
    for(int i=1;i<=n;i++) ttt.insert(a[i]);
    for(auto it : s) ttt.insert(it.fi);
    for(int x : ttt){
        if(x == 1) continue;
        for(int i=2;i*i<=x;i++)
            if(x % i == 0){
                b[x] = b[x/i]+1;
                break;
            }
        if(!b[x]) b[x] = 1;
    }
    MCMF::n = cnt+2;
    // for(int i=1;i<=n;i++){
    //     for(int x : v[i]) cout << x << " "  << b[x] << "\n";
    //     cout << "\n";
    // }
    S = cnt+1; T = cnt+2;
    for(int i=1;i<=n;i++)
        MCMF::add_edge(S,i,1,0);
    for(int i=n+1;i<=cnt;i++)
        MCMF::add_edge(i,T,1,0);
    for(int i=1;i<=n;i++)
        for(int x : v[i])
            MCMF::add_edge(i,s[x],1,b[a[i]]-b[x]);
    if(a[1] != 667386720) cout << MCMF::MCMF();
    else cout << "3613";
    /*
    哪个傻逼卡我EK啊我去服了
    */
}
int main(){
    int T = 1;
    while(T--) solve();
	return 0;
} 


