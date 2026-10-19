#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
const ll inf = 1e18;
int n,m;
int p[N],q[N];
vector<tuple<int,int,int>> v[N];
struct Segment{
    ll t[N<<2],tag[N<<2];
    #define ls rt<<1
    #define rs rt<<1|1
    void build(int rt,int l,int r){
        t[rt] = inf;
        if(l == r) return ;
        int mid = (l+r) >> 1;
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
    inline void push_up(int rt){
        t[rt] = min(t[ls],t[rs]);
    }
    inline void change(int rt,ll d){
        t[rt] += d;
        tag[rt] += d;
    }
    void push_down(int rt){
        if(tag[rt]){
            change(ls,tag[rt]);
            change(rs,tag[rt]);
            tag[rt] = 0;
        }
    }
    void update(int rt,int l,int r,int ql,int qr,ll d){
        if(ql <= l && r <= qr) return change(rt,d);
        push_down(rt);
        int mid = (l+r) >> 1;
        if(ql <= mid) update(ls,l,mid,ql,qr,d);
        if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
        push_up(rt);
    }
    void modify(int rt,int l,int r,int pos,ll d){
        if(l == r) return t[rt] = d,void();
        push_down(rt);
        int mid = (l+r) >> 1;
        if(pos <= mid) modify(ls,l,mid,pos,d);
        else           modify(rs,mid+1,r,pos,d);
        push_up(rt);
    }
}T[2];
ll f[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        p[i] = read();
        q[i] = read();
    }
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1;i<=m;i++){
        int l = read(),r = read(),a = read(),b = read();
        v[r].emplace_back(l,a,b);
    }
    T[0].build(1,0,n); T[1].build(1,0,n);
    T[0].modify(1,0,n,0,0);
    T[1].modify(1,0,n,0,0);
    for(int i=1;i<=n;i++){
        int r = i;
        f[i] = min(T[0].t[1],T[1].t[1]);
        T[0].modify(1,0,n,i,f[i]);
        T[1].modify(1,0,n,i,f[i]);
        T[0].update(1,0,n,0,i,p[i]);
        T[1].update(1,0,n,0,i,q[i]);
        for(auto &[l,a,b] : v[r]){
            if(l < r) T[0].update(1,0,n,l+1,r,b),T[1].update(1,0,n,l+1,r,a);
            T[0].update(1,0,n,0,i,a);
            T[1].update(1,0,n,0,i,b);
        }
    }
    cout << min(T[0].t[1],T[1].t[1]) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
7 1
13 49
34 80
64 56
79 91
74 94
36 4
32 85
4 5 8 51

*/