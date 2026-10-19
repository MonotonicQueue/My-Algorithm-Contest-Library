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
const int mod = 1e9+7;
const ll inv2 = (mod+1)/2;
int n,q;
ll a[N];
inline void add(ll &x,ll y){
    x = x+y >= mod ? x+y-mod : x+y;
}
ll sum[N<<2];
ll s2[N<<2],s1[N<<2],s0[N<<2];
struct Tag{
    ll t2,t1,t0;
    bool chk(){return t0 || t1 || t2;}
}tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    sum[rt] = (sum[ls]+sum[rs])%mod;
}
void build(int rt,int l,int r){
    if(l == r){
        sum[rt] = a[l];
        s2[rt] = 1ll*l*l%mod;
        s1[rt] = l; s0[rt] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
    s2[rt] = (s2[ls]+s2[rs])%mod;
    s1[rt] = (s1[ls]+s1[rs])%mod;
    s0[rt] = (s0[ls]+s0[rs])%mod;
}
void change(int rt,Tag d){
    add(sum[rt],(s2[rt]*d.t2%mod+s1[rt]*d.t1%mod+s0[rt]*d.t0%mod)%mod);
    add(tag[rt].t0,d.t0);
    add(tag[rt].t1,d.t1);
    add(tag[rt].t2,d.t2);
}
inline void push_down(int rt){
    if(tag[rt].chk()){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = {0,0,0};
    }
}
void update(int rt,int l,int r,int ql,int qr,Tag d){
    if(ql > qr) return ;
    if(ql <= l && r <= qr) return change(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1; 
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql == 0) ql = 1;
    if(ql > qr) return 0;
    if(ql <= l && r <= qr) return sum[rt];
    push_down(rt);
    int mid = (l+r) >> 1; ll res = 0;
    if(ql <= mid) add(res,query(ls,l,mid,ql,qr));
    if(qr >  mid) add(res,query(rs,mid+1,r,ql,qr));
    return res;
}
int main(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) add(a[i],a[i-1]);
    for(int i=1;i<=n;i++) add(a[i],a[i-1]);
    build(1,1,n);
    while(q--){
        int op = read(),l = read(),r = read();
        if(l > r) swap(l,r);
        if(op == 1){
            ll d = read();
            update(1,1,n,l,r,Tag{inv2*d%mod,(3-2*l+mod)%mod*inv2%mod*d%mod,(1ll*l*l-3*l+2)%mod*inv2%mod*d%mod});
            update(1,1,n,r+1,n,Tag{0,(r-l+1)*d%mod,(1ll*(r-l+1)*(r-l+2)/2%mod*d%mod-1ll*r*(r-l+1)%mod*d%mod+mod)%mod});
        }else{
            ll res = (r-l+1)*query(1,1,n,n,n)%mod;
            res = (res-query(1,1,n,l-1,r-1)-query(1,1,n,n-r,n-l)+2*mod)%mod;
            cout << res << "\n";
        }
    }
    return 0;
}