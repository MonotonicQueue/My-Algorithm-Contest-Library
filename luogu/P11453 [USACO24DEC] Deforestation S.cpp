#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 1e5+10;
int n,m,a[N],t[N];
void build(){
    for(int i=1;i<=n;i++) t[i] = 0;
}
void add(int x,int y){
    while(x <= n){
        t[x] += y;
        x += x&(-x);
    }
}
int ask(int x){
    int res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
int query(int l,int r){
    return ask(r)-ask(l-1);
}
int fa[N];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1,a+1+n);
    vector<tuple<int,int,int>> v;
    for(int i=1;i<=m;i++){
        int l = read(),r = read(),t = read();
        l = lower_bound(a+1,a+1+n,l)-a;
        r = upper_bound(a+1,a+1+n,r)-a-1;
        v.emplace_back(r,l,t);
    }
    sort(v.begin(),v.end());
    build();
    int ans = n;
    for(int i=1;i<=n;i++) fa[i] = i;
    for(auto [r,l,t] : v){
        if(l > r) continue;
        int k = t-query(l,r);
        while(k > 0){
            k--; ans--;
            int x = get(r);
            add(x,1);
            fa[x] = x-1;
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}