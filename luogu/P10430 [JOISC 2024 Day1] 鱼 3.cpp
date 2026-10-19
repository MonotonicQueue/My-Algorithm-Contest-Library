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
const int N = 3e5+10;
int n,Q;
ll D,c[N];
vector<pii> q[N];
struct Segment_Tree{
    ll t[N<<2],tag[N<<2];
    #define ls rt<<1
    #define rs rt<<1|1
    inline void push_up(int rt){
        t[rt] = t[ls]+t[rs];
    }
    inline void change(int rt,int l,int r,ll d){
        t[rt] += (r-l+1)*d;
        tag[rt] += d;
    }
    inline void push_down(int rt,int l,int r){
        if(tag[rt]){
            int mid = (l+r) >> 1;
            change(ls,l,mid,tag[rt]);
            change(rs,mid+1,r,tag[rt]);
            tag[rt] = 0;
        }
    }
    void update(int rt,int l,int r,int ql,int qr,ll d){
        if(ql <= l && r <= qr) return change(rt,l,r,d);
        push_down(rt,l,r);
        int mid = (l+r) >> 1;
        if(ql <= mid) update(ls,l,mid,ql,qr,d);
        if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
        push_up(rt);
    }
    ll query(int rt,int l,int r,int ql,int qr){
        if(ql <= l && r <= qr) return t[rt];
        push_down(rt,l,r);
        int mid = (l+r) >> 1; ll res = 0;
        if(ql <= mid) res += query(ls,l,mid,ql,qr);
        if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
        return res;
    }
}T;
ll ans[N],sum[N];
int fa[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    fa[y] = x;
}
signed main(){
    n = read(); D = read();
    for(int i=1;i<=n;i++) c[i] = read(),sum[i] = sum[i-1]+c[i];
    for(int i=1;i<=n;i++) fa[i] = i;
    Q = read();
    for(int i=1;i<=Q;i++){
        int l = read(),r = read();
        q[r].push_back(mk(l,i));
    }
    for(int i=1;i<=n;i++){
        T.update(1,1,n,i,i,c[i]);
        int x = i-1;
        while(x){
            ll val1 = T.query(1,1,n,x,x),val2 = T.query(1,1,n,x+1,x+1);
            if(val1 <= val2) break;
            ll k = (val1-val2-1)/D+1;
            T.update(1,1,n,get(x),x,-k*D);
            merge(x,x+1);
            x = get(x)-1;
        }
        for(auto it : q[i]){
            ans[it.se] = T.query(1,1,n,it.fi,it.fi) < 0 ? -1 : (sum[i]-sum[it.fi-1]-T.query(1,1,n,it.fi,i))/D;
        }
    }
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
    return 0;
}