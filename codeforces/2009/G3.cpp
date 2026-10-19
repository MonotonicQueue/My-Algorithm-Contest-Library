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
const int N = 4e5+10;
int n,q,k,a[N];
ll cnt[N],f[N];
int stk[N],top;
multiset<int> s;
vector<pii> v[N];
ll ans[N];
struct Segment{
    ll sum,tag,mul;
    ll psum,ptag;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].sum = t[ls].sum+t[rs].sum;
    t[rt].psum = t[ls].psum+t[rs].psum;
}
void build(int rt,int l,int r){
    t[rt].sum = t[rt].psum = 0;
    t[rt].tag = -1;
    t[rt].ptag = t[rt].mul = 0;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void change2(int rt,ll mul){
    t[rt].psum += t[rt].sum*mul;
    t[rt].mul += mul;
}
void change1(int rt,int l,int r,ll tag,ll mul){
    if(~t[rt].tag){
        t[rt].ptag += t[rt].tag*t[rt].mul;
        t[rt].tag = -1;
        t[rt].mul = 0;
    }else if(t[rt].mul){
        if(l != r) change2(ls,t[rt].mul),change2(rs,t[rt].mul);
        t[rt].mul = 0;
    }
    t[rt].sum = (r-l+1)*tag;
    t[rt].tag = tag; t[rt].mul = mul;
    t[rt].psum += t[rt].sum*mul;
}
inline void push_down(int rt,int l,int r){
    int mid = (l+r) >> 1,llen = (mid-l+1),rlen = (r-mid);
    if(t[rt].ptag){
        t[ls].psum += llen*t[rt].ptag;
        t[ls].ptag += t[rt].ptag;
        t[rs].psum += rlen*t[rt].ptag;
        t[rs].ptag += t[rt].ptag;
        t[rt].ptag = 0;
    }
    if(~t[rt].tag){
        change1(ls,l,mid,t[rt].tag,t[rt].mul);
        change1(rs,l,mid,t[rt].tag,t[rt].mul);
        t[rt].tag = -1;
        t[rt].mul = 0;
    }else{
        change2(ls,t[rt].mul);
        change2(rs,t[rt].mul);
        t[rt].mul = 0;
    }
}
void update1(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr) return change1(rt,l,r,d,1);
    push_down(rt,l,r);
    int mid = (l+r) >> 1;
    if(ql <= mid) update1(ls,l,mid,ql,qr,d);
    if(qr >  mid) update1(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
void update2(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return change2(rt,1);
    push_down(rt,l,r);
    int mid = (l+r) >> 1;
    if(ql <= mid) update2(ls,l,mid,ql,qr);
    if(qr >  mid) update2(rs,mid+1,r,ql,qr);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].psum;
    push_down(rt,l,r);
    int mid = (l+r) >> 1; ll res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
void solve(){
    n = read(); k = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read(),v[i].clear();
    for(int i=1;i<=n;i++) a[i] = a[i]+n-i+1;
    for(int i=1;i<=2*n;i++) cnt[i] = 0;
    s.clear();
    for(int i=1;i<=n;i++){
        if(i > k){
            f[i-k] = k-*s.rbegin();
            s.erase(s.find(cnt[a[i-k]]));
            cnt[a[i-k]]--;
            if(cnt[a[i-k]]) s.insert(cnt[a[i-k]]);
        }
        if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
        cnt[a[i]]++;
        s.insert(cnt[a[i]]);
    }
    f[n-k+1] =  k-*s.rbegin();
    for(int i=1;i<=q;i++){
        int l = read(),r =  read();
        v[l].push_back(mk(r-k+1,i));
    }
    n = n-k+1; f[n+1] = 0;
    top = 1;
    stk[top] = n+1;
    build(1,1,n);
    for(int i=n;i;i--){
        while(top && f[i] < f[stk[top]]) top--;
        update1(1,1,n,i,stk[top]-1,f[i]);
        if(stk[top] <= n) update2(1,1,n,stk[top],n);
        for(auto it : v[i])
            ans[it.se] = query(1,1,n,i,it.fi);
        stk[++top] = i;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}