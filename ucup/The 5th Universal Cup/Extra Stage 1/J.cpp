#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 5e5+10;
int n,m;
int fa[N],siz[N];
vector<int> v[N];
ull hsh[N],t[N],pw[N],P=1331;
void add(int x,ull y){
    while(x <= n){
        t[x] += y;
        x += x&(-x);
    }
}
ull ask(int x){
    ull res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
ull query(int l,int r){
    return ask(r)-ask(l-1);
}
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    assert(x != y);
    if(siz[x] > siz[y]) swap(x,y);
    siz[y] += siz[x];
    fa[x] = y;
    for(int z : v[x]){
        v[y].push_back(z);
        add(z,-hsh[x]*pw[z]);
        add(z, hsh[y]*pw[z]);
    }
}
mt19937_64 rnd(time(0));
struct Edge{
    int u,v,l,c;
}e[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) t[i] = 0;
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    for(int i=1;i<=n;i++){
        fa[i] = i; siz[i] = 1;
        v[i].clear();
        v[i].push_back(i);
        hsh[i] = rnd();
        add(i,hsh[i]*pw[i]);
    }
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].l = read(); e[i].c = read();
    }
    sort(e+1,e+1+m,[](Edge x,Edge y){return x.c < y.c;});
    ll ans = 0;
    for(int i=1;i<=m;i++){
        auto &[u,v,L,c] = e[i];
        if(u > v) swap(u,v);
        while(true){
            int l = 0,r = L-1,res = -1;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(query(u,u+mid)*pw[v-u] == query(v,v+mid)) l = mid+1;
                else r = mid-1,res = mid;
            }
            if(res == -1) break;
            merge(u+res,v+res);
            ans += c;
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
