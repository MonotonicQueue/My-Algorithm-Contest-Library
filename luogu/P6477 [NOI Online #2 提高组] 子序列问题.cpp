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
const int N = 1e6+10;
const int mod = 1e9+7;
int n,a[N],nxt[N],cnt[N];
map<int,int> lst;
struct Segment{
    ll sum1,sum2,tag;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].sum1 = (t[ls].sum1+t[rs].sum1)%mod;
    t[rt].sum2 = (t[ls].sum2+t[rs].sum2)%mod;
}
void build(int rt,int l,int r){
    if(l == r){
        t[rt].sum2 = cnt[l];
        t[rt].sum1 = 1ll*cnt[l]*cnt[l]%mod;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void change(int rt,int l,int r,ll tag){
    t[rt].tag = (t[rt].tag+tag)%mod;
    t[rt].sum1 = (t[rt].sum1+2*tag*t[rt].sum2%mod+(r-l+1)*tag%mod*tag%mod)%mod;
    t[rt].sum2 = (t[rt].sum2+(r-l+1)*tag%mod)%mod;
}
inline void push_down(int rt,int l,int r){
    int mid = (l+r) >> 1;
    if(t[rt].tag){
        change(ls,l,mid,t[rt].tag);
        change(rs,mid+1,r,t[rt].tag);
        t[rt].tag = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        change(rt,l,r,mod-1);
        return ;
    }
    push_down(rt,l,r);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr);
    if(qr >  mid) update(rs,mid+1,r,ql,qr);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].sum1;
    int mid = (l+r) >> 1; ll res = 0;
    push_down(rt,l,r);
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        if(lst[a[i]]) nxt[lst[a[i]]] = i;
        else cnt[i]++;
        cnt[i] += cnt[i-1];
        lst[a[i]] = i;
    }
    for(int i=1;i<=n;i++)
        if(!nxt[i]) nxt[i] = n+1;
    build(1,1,n);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans+query(1,1,n,i,n))%mod;
        update(1,1,n,i,nxt[i]-1);
    }
    cout << ans;
    return 0;
}
