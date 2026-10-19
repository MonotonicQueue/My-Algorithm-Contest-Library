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
const int mod = 1e9+9;
int n,p[N];
struct node{
    int mx;
    ull cnt;
    node(int x=0,int y=0){mx = x; cnt = y;}
    node operator *(const node &o)const{
        node res;
        res.mx = max(mx,o.mx);
        if(mx == res.mx) res.cnt += cnt;
        if(o.mx == res.mx) res.cnt += o.cnt;
        res.cnt %= mod;
        return res;
    }
};
struct Segment_Tree{
    int L,R;
    node t[N<<2];
    #define ls rt<<1
    #define rs rt<<1|1
    inline void push_up(int rt){
        t[rt].mx = max(t[ls].mx,t[rs].mx);
        t[rt].cnt = 0;
        if(t[ls].mx == t[rt].mx) t[rt].cnt += t[ls].cnt;
        if(t[rs].mx == t[rt].mx) t[rt].cnt += t[rs].cnt;
        t[rt].cnt %= mod;
    }
    void build(int rt,int l,int r){
        t[rt].mx = t[rt].cnt = 0;
        if(l == r){
            return ;
        }
        int mid = (l+r) >> 1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(rt);
    }
    void update(int rt,int l,int r,int pos,node d){
        if(l == r) return t[rt] = d,void();
        int mid = (l+r) >> 1;
        if(pos <= mid) update(ls,l,mid,pos,d);
        if(pos >  mid) update(rs,mid+1,r,pos,d);
        push_up(rt);
    }
    node query(int rt,int l,int r,int ql,int qr){
        if(ql <= l && r <= qr) return t[rt];
        int mid = (l+r) >> 1;
        if(mid < ql) return query(rs,mid+1,r,ql,qr);
        if(qr <= mid) return query(ls,l,mid,ql,qr);
        return query(ls,l,mid,ql,qr)*query(rs,mid+1,r,ql,qr);
    }
    void build(int l,int r){
        L = l; R = r;
        build(1,L,R);
    }
    void update(int pos,node d){
        update(1,L,R,pos,d);
    }
    node query(int l,int r){
        return query(1,L,R,l,r);
    }
}T1,T2;
int f[N],g[N],u[N],v[N];
ull F[N],G[N],U[N],V[N];
/*
f_i 以 i 结尾的 LIS，F_i 以 i 结尾的 LIS数量
u_i 以 i 开头的 LIS，U_i 以 i 开头的 LIS数量
g_i 以 i 结尾的 LDS，G_i 以 i 结尾的 LDS数量
v_i 以 i 开头的 LDS，V_i 以 i 开头的 LDS数量
*/
void solve(){
    n = read();
    for(int i=1;i<=n;i++) p[i] = read();
    T1.build(0,n);
    T1.update(0,node(0,1));
    for(int i=1;i<=n;i++){
        node res = T1.query(0,p[i]-1);
        res.mx++;
        T1.update(p[i],res);
        f[i] = res.mx,F[i] = res.cnt;
    }
    T2.build(1,n+1);
    T2.update(n+1,node(0,1));
    for(int i=1;i<=n;i++){
        node res = T2.query(p[i]+1,n+1);
        res.mx++;
        T2.update(p[i],res);
        g[i] = res.mx,G[i] = res.cnt;
    }
    int LIS = T1.query(0,n).mx,LDS = T2.query(1,n+1).mx;
    ull ct1 = 0,ct2 = 0;
    for(int i=1;i<=n;i++){
        if(f[i] == LIS) (ct1 += F[i]) %= mod;
        if(g[i] == LDS) (ct2 += G[i]) %= mod;
    }
    // 
    ull sum1 = ct1*ct2%mod;
    T2.build(1,n+1);
    T2.update(n+1,node(0,1));
    for(int i=n;i;i--){
        node res = T2.query(p[i]+1,n+1);
        res.mx++;
        T2.update(p[i],res);
        u[i] = res.mx; U[i] = res.cnt;
    }
    T1.build(0,n);
    T1.update(0,node(0,1));
    for(int i=n;i;i--){
        node res = T1.query(0,p[i]-1);
        res.mx++;
        T1.update(p[i],res);
        v[i] = res.mx,V[i] = res.cnt;
    }
    ull sum2 = 0;
    for(int i=1;i<=n;i++){
        if(f[i]+u[i]-1 == LIS && g[i]+v[i]-1 == LDS){
            (sum2 += F[i]*U[i]%mod*G[i]%mod*V[i]%mod)%=mod;
        }
    }
    if(sum1 == sum2) cout << LIS+LDS-1 << "\n";
    else cout << LIS+LDS << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    
	return 0;
}
