#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
const int C = 30;
const int mod = 1e9+7;
int n,m,k,q,fa[N],cnt;
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    if(x != y) fa[x] = y,cnt--;
}
ll pw[N],ans[N];
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
struct Edge{int v,z,t;};
vector<Edge> G[N];
int val[N];
void clear(){
    for(int i=1;i<=n+m;i++) fa[i] = i;
    for(int i=1;i<=n+m;i++) G[i].clear();
    pw[0] = 1; ll p = (1<<30)%mod;
    for(int i=1;i<=n+m;i++) pw[i] = pw[i-1]*p%mod;
}
bool flag;
void dfs(int x,int mid){
    for(auto it : G[x]){
        if(it.t > mid) continue;
        int y = it.v,z = it.z;
        if(val[y] == -1){
            val[y] = val[x]^z;
            dfs(y,mid);
        }else flag &= (val[x]^val[y]) == z;
    }
}
bool chk(int mid){
    flag = true;
    for(int i=1;i<=n+m;i++) val[i] = -1;
    for(int i=1;i<=n+m;i++){
        if(~val[i]) continue;
        val[i] = 0; dfs(i,mid);
    }
    return flag;
}
void solve(){
    n = read(); m = read();
    k = read(); q = read();
    clear();
    cnt = n+m-1;
    for(int i=1;i<=k;i++){
        int x = read(),y = read(),z = read();
        G[x].push_back(Edge{y+n,z,0});
        G[y+n].push_back(Edge{x,z,0});
        merge(x,y+n);
    }
    ans[0] = cnt;
    for(int i=1;i<=q;i++){
        int x = read(),y = read(),z = read();
        G[x].push_back(Edge{y+n,z,i});
        G[y+n].push_back(Edge{x,z,i});
        merge(x,y+n); ans[i] = cnt;
    }
    int l = 0,r = q,res = q+1;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) l = mid+1;
        else r = mid-1,res = mid;
    }
    for(int i=0;i<=q;i++) cout << (i < res)*pw[ans[i]] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}