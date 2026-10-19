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
const int N = 5e4+10;
const int M = 1e5+10;
int n,m,need;
int fa[N];
struct Edge{
    int u,v,col,val,raw;
    bool operator < (const Edge x)const{
        return val != x.val ? val < x.val : col < x.col;
    }
}e[M];
int ans;
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int kruskal(int mid){
    for(int i=1;i<=m;i++)
        e[i].val = e[i].raw+mid*(e[i].col^1);
    sort(e+1,e+1+m);
    for(int i=1;i<=n;i++) fa[i] = i;
    int cnt = 0; ans = 0;
    for(int i=1;i<=m;i++){
        int u = get(e[i].u),v = get(e[i].v);
        if(u == v) continue;
        cnt += e[i].col^1;
        ans += e[i].val;
        fa[u] = v;
    }
    return cnt;
}
int main(){
    n = read(); m = read(); need = read();
    for(int i=1;i<=m;i++){
        e[i].u = read()+1; e[i].v = read()+1;
        e[i].raw = read(); e[i].col = read();
    }
    int l = -100,r = 100,res = 0;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(kruskal(mid) >= need) res = mid,l = mid+1;
        else r = mid-1;
    }
    // cout << res << " " << ans << "\n";
    kruskal(res);
    cout << ans-res*need;
    return 0;
}