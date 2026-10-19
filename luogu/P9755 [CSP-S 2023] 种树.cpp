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
const int N = 1e5+10;
int n,fa[N];
ll a[N],b[N],c[N];
vector<int> G[N];
void dfs(int x,int fr){
    fa[x] = fr;
    for(int y : G[x]){
        if(y == fr) continue;
        dfs(y,x);
    }
}
int p[N],t[N];
bool vis[N];
bool cmp(int x,int y){
    return t[x] < t[y];
}
__int128 calc(ll b,__int128 c,ll l,ll r){
    if(c >= 0) return b*(r-l+1)+c*(l+r)*(r-l+1)/2;
    ll k = (1-b)/c;
    if(k < l) return r-l+1;
    if(k >= r) return b*(r-l+1)+c*(l+r)*(r-l+1)/2;
    return b*(k-l+1)+c*(l+k)*(k-l+1)/2+r-k;
}
int stk[N],top;
bool chk(int md){
    for(int i=1;i<=n;i++){
        int l = 1,r = md;
        if(calc(b[i],c[i],1,r) < a[i]) return false;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(calc(b[i],c[i],mid,md) >= a[i]) l = mid+1,t[i] = mid;
            else r = mid-1;
        }
    }
    for(int i=1;i<=n;i++) p[i] = i,vis[i] = false;
    sort(p+1,p+1+n,cmp);
    vis[1] = true;
    top = 0;
    int ti = 1;
    for(int i=1;i<=n;i++){
        int x = p[i];
        while(!vis[x]) stk[++top] = x,x = fa[x];
        while(top){
            vis[stk[top]] = true;
            if(++ti > t[stk[top--]]) return false;
        }
    }
    return true;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        b[i] = read();
        c[i] = read();
    }
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    int l = 1,r = 1e9,res = 0;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(chk(mid)) res = mid,r = mid-1;
        else l = mid+1;
    }
    cout << res;
    return 0;
}
