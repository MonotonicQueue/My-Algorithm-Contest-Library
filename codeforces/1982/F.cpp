#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
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
int n,Q,a[N];
#define ls rt<<1
#define rs rt<<1|1
int mn[N<<2],mx[N<<2];
bool flag[N<<2];
inline void push_up(int rt){
    if(mx[ls] > mn[rs]) flag[rt] = 1;
    else flag[rt] = 0;
    flag[rt] |= flag[ls]|flag[rs];
    mn[rt] = min(mn[ls],mn[rs]);
    mx[rt] = max(mx[ls],mx[rs]);
}
void build(int rt,int l,int r){
    flag[rt] = false;
    if(l == r){
        mn[rt] = mx[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int pos){
    if(l == r){
        mn[rt] = mx[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos);
    else update(rs,mid+1,r,pos);
    push_up(rt);
}
int query1(int rt,int l,int r,int t){
    if(l == r) return l;
    int mid = (l+r) >> 1;
    if(flag[ls] || (mx[ls] > min(mn[rs],t))) return query1(ls,l,mid,min(mn[rs],t));
    return query1(rs,mid+1,r,t);
}
int query2(int rt,int l,int r,int t){
    if(l == r) return l;
    int mid = (l+r) >> 1;
    if(flag[rs] || (max(mx[ls],t) > mn[rs])) return query2(rs,mid+1,r,max(mx[ls],t));
    return query2(ls,l,mid,t);
}
void ask(){
    if(!flag[1]) puts("-1 -1");
    else cout << query1(1,1,n,1e9+1) << " " << query2(1,1,n,-1e9-1) << "\n";
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    build(1,1,n);
    ask();
    Q = read();
    while(Q--){
        int p = read();
        a[p] = read();
        update(1,1,n,p);
        ask();
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
5
1 1 3 1 5
0
*/