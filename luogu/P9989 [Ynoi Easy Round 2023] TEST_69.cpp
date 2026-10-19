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
const ll inf = 1e18+1;
int n,m;
ll a[N],lm[N<<2];
unsigned int sum[N<<2];
#define ls rt<<1
#define rs rt<<1|1
ll get(ll x,ll y){
    if(x == inf || y == inf) return inf;
    __int128 d = (__int128)x*y/__gcd(x,y);
    if(d > inf) d = inf+1;
    return d;
}
inline void push_up(int rt){
    sum[rt] = sum[ls]+sum[rs];
    lm[rt] = get(lm[ls],lm[rs]);
}
void build(int rt,int l,int r){
    if(l == r){
        sum[rt] = a[l];
        lm[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(d % lm[rt] == 0) return ;
    if(l == r){
        a[l] = __gcd(d,a[l]);
        sum[rt] = a[l]; lm[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
unsigned int query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return sum[rt];
    int mid = (l+r) >> 1; unsigned int res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    build(1,1,n);
    while(m--){
        int op = read(),l = read(),r = read();
        if(op == 1){
            ll d = read();
            update(1,1,n,l,r,d);
        }else cout << query(1,1,n,l,r) << "\n";
    }
    return 0;
}