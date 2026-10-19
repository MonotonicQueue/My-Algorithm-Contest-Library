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
const int N = 2e5+10;
const ll inf = 1e18;
int n,k;
ll a[N],b[N];
struct node{int i,to,w;};
vector<node> G[N];
map<int,int> mp[N];
vector<bool> vis[N];
vector<ll> f[N];
struct Line{
    ll k,b;
    ll calc(ll x){
        return x*k+b;
    }
}L[N*10]; int cnt;
struct Lichao_Segment{
    int n;
    vector<int> t,val;
    void build(int x){
        n = G[x].size();
        t.resize(4*n+10);
        for(auto [x,y,z] : G[x]) val.push_back(a[x]);
    }
    #define ls rt<<1
    #define rs rt<<1|1
    void insert(int rt,int l,int r,int pos){
        if(!t[rt]) return t[rt] = pos,void();
        int mid = (l+r) >> 1;
        if(L[t[rt]].calc(val[mid]) > L[pos].calc(val[mid]))
            swap(t[rt],pos);
        if(l == r) return ;
        if(L[t[rt]].calc(val[l]) > L[pos].calc(val[l])) insert(ls,l,mid,pos);
        else insert(rs,mid+1,r,pos);
    }
    ll query(int rt,int l,int r,int pos){
        ll res = t[rt] ? L[t[rt]].calc(val[pos]) : inf;
        if(l == r) return res;
        int mid = (l+r) >> 1;
        if(pos <= mid) return min(query(ls,l,mid,pos),res);
        return min(query(rs,mid+1,r,pos),res);
    }
    void insert(int pos){
        insert(1,0,n-1,pos);
    }
    ll query(int pos){
        return query(1,0,n-1,pos);
    }
}T[N];
int p[N];
void init(){
    for(int i=1;i<=n;i++)
        vis[i].resize(G[i].size()),f[i].resize(G[i].size());
    for(int i=2;i<=n;i++)
        for(auto &x : f[i]) x = inf;
    for(int i=1;i<=n;i++) T[i].build(i);
}
void dijkstra(){
    init();
    priority_queue<tuple<ll,int,int>> q;
    for(auto [x,y,z] : G[1]) q.push(make_tuple(0,1,x));
    while(!q.empty()){
        auto [w,x,id] = q.top(); q.pop();
        int i = mp[x][id];
        if(vis[x][i]) continue;
        vis[x][i] = true;
        {
            auto [idd,to,ww] = G[x][i];
            if(to){
                int j = mp[to][idd];
                if(f[x][i]+ww < f[to][j]){
                    f[to][j] = f[x][i]+ww;
                    q.push(make_tuple(-f[to][j],to,id));
                }    
            }
        }
        L[++cnt] = {b[id],-w};
        T[x].insert(cnt);
        {
            while(p[x] < int(G[x].size()) && vis[x][p[x]]) p[x]++;
            if(p[x] >= int(G[x].size())) continue;
            f[x][p[x]] = min(f[x][p[x]],T[x].query(p[x]));
            q.push(make_tuple(-f[x][p[x]],x,G[x][p[x]].i));
        }
    }
}
int main(){
    n = read(); k = read();
    for(int i=1;i<=k;i++) a[i] = read();
    for(int i=1;i<=k;i++) b[i] = read();
    for(int i=1;i<=k;i++){
        int p = read()-1,lst = read();
        while(p--){
            int w = read(),x = read();
            G[lst].emplace_back(node{i,x,w});
            lst = x;
        }
        G[lst].emplace_back(node{i,0,0});
    }
    for(int i=1;i<=n;i++)
        sort(G[i].begin(),G[i].end(),[](node x,node y){return a[x.i] < a[y.i];});
    for(int i=1;i<=n;i++)
        for(int j=0;j<int(G[i].size());j++)
            mp[i][G[i][j].i] = j;
    dijkstra();
    for(int i=2;i<=n;i++){
        ll ans = inf;
        for(ll x : f[i]) ans = min(ans,x);
        cout << ans << " ";
    }
	return 0;
}