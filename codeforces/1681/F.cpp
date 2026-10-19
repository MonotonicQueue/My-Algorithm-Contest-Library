#include<bits/stdc++.h>
#define ll long long
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
const int N = 5e5+10;
int n;
struct node{
    int u,v;
}e[N];
vector<int> v[N<<2],vv[N];
#define ls rt<<1
#define rs rt<<1|1
void insert(int rt,int l,int r,int ql,int qr,int id){
    if(ql > qr) return ;
    if(ql <= l && r <= qr) {
        // cout << l <<" " << r << " " << id << "\n";
        return v[rt].push_back(id),void();
    }
    int mid = (l+r) >> 1;
    if(ql <= mid) insert(ls,l,mid,ql,qr,id);
    if(qr >  mid) insert(rs,mid+1,r,ql,qr,id);
}
int fa[N],siz[N];
ll ans;
int get(int x){
    return fa[x] == x ? x : get(fa[x]);
}
void solve(int rt,int l,int r){
    vector<pii> st;
    for(int i : v[rt]){
        int x = e[i].u,y = e[i].v;
        x = get(x); y = get(y);
        if(siz[x] < siz[y]) swap(x,y);
        fa[y] = x; siz[x] += siz[y];
        st.push_back(mk(x,y));
    }
    int mid = (l+r) >> 1;
    if(l != r) solve(ls,l,mid),solve(rs,mid+1,r);
    else for(int i : vv[l]) ans += 1ll*siz[get(e[i].u)]*siz[get(e[i].v)];
    reverse(st.begin(),st.end());
    for(auto it : st){
        int x = it.fi,y = it.se;
        fa[y] = y;
        siz[x] -= siz[y];
    }
}
int main() {
	n = read();
    for(int i=1;i<n;i++){
        e[i].u = read(); e[i].v = read();
        int col = read();
        vv[col].push_back(i);
        insert(1,1,n,1,col-1,i);
        insert(1,1,n,col+1,n,i); 
    }
    for(int i=1;i<=n;i++) siz[i] = 1,fa[i] = i;
    solve(1,1,n);
    cout << ans;
	return 0;
}
