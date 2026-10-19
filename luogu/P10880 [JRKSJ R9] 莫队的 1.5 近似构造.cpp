#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
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
const int mod = 998244353;
int n,m,a[N],tot;
struct Interval{
    int l,r;
    bool operator<(const Interval &o)const{
        return l == o.l ? r > o.r : l < o.l;
    }
}b[N],c[N];
int L[N],R[N];
int mx[N],tag[N];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    mx[rt] = max(mx[ls],mx[rs]);
}
void build(int rt,int l,int r){
    mx[rt] = tag[rt] = 0;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void change(int rt,int d){
    mx[rt] += d;
    tag[rt] += d;
}
inline void push_down(int rt){
    if(tag[rt]){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        change(rt,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int pos[N],lst[N][2];
struct node{
    double res;
    int cnt1,cnt2;
    bool operator < (const node &o)const{
        return res < o.res;
    }
    node operator + (const node &o)const{
        return node{res+o.res,cnt1+o.cnt1,cnt2+o.cnt2};
    }
}f[N],tmp2,tmp3;
signed main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++){
        b[i].l = read();
        b[i].r = read();
    }
    sort(b+1,b+m+1);
    c[++tot] = b[1];
    for(int i=2;i<=m;i++)
        if(b[i].r > c[tot].r) c[++tot] = b[i];
    m = tot;
    for(int i=1;i<=m;i++)
        L[i] = c[i].l,R[i] = c[i].r;
    for(int i=1;i<=n;i++) pos[a[i]] = i;
    build(1,1,m);
    for(int i=1,j=1;i<=n;i++){
        while(j <= n && mx[1] < 2){
            int l = lower_bound(R+1,R+1+m,pos[j])-R;
            int r = upper_bound(L+1,L+1+m,pos[j])-L-1;
            j++;
            if(l > r || l == m+1 || r == 0) continue;
            update(1,1,m,l,r,1);
        }
        if(mx[1] == 2) lst[j-1][0] = i;
        int l = lower_bound(R+1,R+1+m,pos[i])-R;
        int r = upper_bound(L+1,L+1+m,pos[i])-L-1;
        if(l > r || l == m+1 || r == 0) continue;
        update(1,1,m,l,r,-1);
    }
    build(1,1,m);
    for(int i=1,j=1;i<=n;i++){
        while(j <= n && mx[1] < 3){
            int l = lower_bound(R+1,R+1+m,pos[j])-R;
            int r = upper_bound(L+1,L+1+m,pos[j])-L-1;
            j++;
            if(l > r || l == m+1 || r == 0) continue;
            update(1,1,m,l,r,1);
        }
        if(mx[1] == 3) lst[j-1][1] = i;
        int l = lower_bound(R+1,R+1+m,pos[i])-R;
        int r = upper_bound(L+1,L+1+m,pos[i])-L-1;
        if(l > r || l == m+1 || r == 0) continue;
        update(1,1,m,l,r,-1);
    }
    tmp2 = node{1,1,0};
    tmp3 = node{log2(3),0,1};
    for(int i=1;i<=n;i++){
        f[i] = f[i-1];
        if(lst[i][0] && f[i] < f[lst[i][0]-1]+tmp2) f[i] = f[lst[i][0]-1]+tmp2;
        if(lst[i][1] && f[i] < f[lst[i][1]-1]+tmp3) f[i] = f[lst[i][1]-1]+tmp3;
    }
    ll res = 1;
    for(int i=1;i<=f[n].cnt1;i++) res = res*2%mod;
    for(int i=1;i<=f[n].cnt2;i++) res = res*3%mod;
    cout << res;
    return 0;
}
