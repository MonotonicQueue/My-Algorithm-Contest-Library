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
const int M = 5e5+10;
int n,m,s,k;
int fa[N],fa2[N];
struct Edge{
    int u,v,col,val,raw;
    bool operator < (const Edge x)const{
        return val != x.val ? val < x.val : col > x.col;
    }
}e[M];
int ans;
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
int get2(int x){
    return x == fa2[x] ? x : fa2[x] = get(fa2[x]);
}
int kruskal(int mid){
    for(int i=1;i<=m;i++)
        e[i].val = e[i].raw+mid*(e[i].col);
    sort(e+1,e+1+m);
    for(int i=1;i<=n;i++) fa[i] = i;
    int cnt = 0,sum = 0; ans = 0;
    int w = 0;
    for(int i=1;i<=m;i++){
        int u = get(e[i].u),v = get(e[i].v);
        if(u == v) continue;
        sum++;
        cnt += e[i].col;
        ans += e[i].val;
        fa[u] = v;
        if(sum == n-1){
            w = e[i].val;
            break;
        }
    }
    if(cnt > k){
        cnt = sum = 0;
        for(int i=1;i<=n;i++) fa[i] = fa2[i] = i;
        int i = 1;
        for(;i<=m && e[i].val < w;i++){
            int u = get(e[i].u),v = get(e[i].v);
            if(u == v) continue;
            cnt += e[i].col;
            fa[u] = v; fa2[u] = v;
        }
        int j = i;
        for(;i<=m && e[i].val == w;i++){
            int u = get(e[i].u),v = get(e[i].v);
            if(u == v) continue;
            cnt += e[i].col;
            fa[u] = v;
            if(e[i].col == 0) fa2[u] = v;
        }
        i = j;
        for(;i<=m && e[i].val == w && cnt > k;i++){
            if(e[i].col) continue;
            int uu = get2(e[i].u),vv = get2(e[i].v);
            if(uu == vv) continue;
            fa2[uu] = vv;
            cnt--;
        }
    }
    return cnt;
}
int main(){
    n = read(); m = read(); s = read(); k = read();
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].raw = read(); e[i].col = e[i].u == s || e[i].v == s;
    }
    int l = -3e4,r = 3e4,res = 0;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(kruskal(mid) >= k) l = mid+1,res = mid;
        else r = mid-1;
    }
    // cout << res << "\n";
    if(kruskal(res) == k) cout << ans-res*k;
    else cout << "Impossible";
    return 0;
}