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
int n,a[N],p[N],b[N],m;
vector<int> G[N];
struct Segment{
    int ls,rs;
    int sum;
}t[N*20];
int root[N];
int cnt;
int merge(int u,int v,int l=1,int r=m){
    if(!u || !v) return u+v;
    t[u].sum += t[v].sum;
    if(l == r) return u;
    int mid = (l+r) >> 1;
    t[u].ls = merge(t[u].ls,t[v].ls,l,mid);
    t[u].rs = merge(t[u].rs,t[v].rs,mid+1,r);
    return u;
}
void update(int &rt,int l,int r,int pos){
    if(!rt) rt = ++cnt;
    t[rt].sum++;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    if(pos <= mid) update(t[rt].ls,l,mid,pos);
    else update(t[rt].rs,mid+1,r,pos);
}
int query(int rt,int l,int r,int ql,int qr){
    if(!rt || ql > qr) return 0;
    if(ql <= l && r <= qr) return t[rt].sum;
    int mid = (l+r) >> 1,res = 0;
    if(ql <= mid) res += query(t[rt].ls,l,mid,ql,qr);
    if(qr >  mid) res += query(t[rt].rs,mid+1,r,ql,qr);
    return res;
}
int ans[N];
void dfs(int x){
    for(int y : G[x]){
        dfs(y);
        root[x] = merge(root[x],root[y]);
    }
    ans[x] = query(root[x],1,m,a[x]+1,m);
    update(root[x],1,m,a[x]);
}
signed main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=2;i<=n;i++) p[i] = read(),G[p[i]].push_back(i);
    for(int i=1;i<=n;i++) b[i] = a[i];
    sort(b+1,b+1+n);
    m = unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++) a[i] = lower_bound(b+1,b+1+m,a[i])-b;
    dfs(1);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}