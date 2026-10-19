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
const int N = 1e5+10;
const int inf = -(1ll<<31);
int n,a[N];
struct Segment{
    int mx,mxh;
    int add,tag;
    int mx_add,mx_tag;
    bool flag,fff;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].mx = max(t[ls].mx,t[rs].mx);
    t[rt].mxh = max(t[ls].mxh,t[rs].mxh);
}
void build(int rt,int l,int r){
    t[rt].mx_tag = inf;
    if(l == r){
        t[rt].fff = true;
        t[rt].mx = t[rt].mxh = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void change_add(int rt,int d,int dh){
    if(t[rt].flag){
        t[rt].mx_tag = max(t[rt].mx_tag,t[rt].tag+dh);
        t[rt].tag += d;
        t[rt].mxh = max(t[rt].mxh,t[rt].mx+dh);
        t[rt].mx += d;
    }else{
        t[rt].mx_add = max(t[rt].mx_add,t[rt].add+dh);
        t[rt].add += d;
        t[rt].mxh = max(t[rt].mxh,t[rt].mx+dh);
        t[rt].mx += d;
    }
}
void change_tag(int rt,int d,int dh){
    if(!t[rt].fff){
        change_add(ls,t[rt].add,t[rt].mx_add);
        change_add(rs,t[rt].add,t[rt].mx_add);
        t[rt].add = t[rt].mx_add = 0;
    }
    t[rt].mx_tag = max(t[rt].mx_tag,dh);
    t[rt].tag = t[rt].mx = d;
    t[rt].mxh = max(t[rt].mxh,dh);
    t[rt].flag = true;
}
inline void push_down(int rt){
    if(t[rt].flag){
        change_tag(ls,t[rt].tag,t[rt].mx_tag);
        change_tag(rs,t[rt].tag,t[rt].mx_tag);
        t[rt].flag = false;
        t[rt].mx_tag = inf; 
    }else{
        change_add(ls,t[rt].add,t[rt].mx_add);
        change_add(rs,t[rt].add,t[rt].mx_add);
        t[rt].add = t[rt].mx_add = 0;
    }
}
void update_add(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        change_add(rt,d,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update_add(ls,l,mid,ql,qr,d);
    if(qr >  mid) update_add(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
void update_tag(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        change_tag(rt,d,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update_tag(ls,l,mid,ql,qr,d);
    if(qr >  mid) update_tag(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].mx;
    push_down(rt);
    int mid = (l+r) >> 1,res = inf;
    if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
    if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
    return res;
}
int queryh(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].mxh;
    push_down(rt);
    int mid = (l+r) >> 1,res = inf;
    if(ql <= mid) res = max(res,queryh(ls,l,mid,ql,qr));
    if(qr >  mid) res = max(res,queryh(rs,mid+1,r,ql,qr));
    return res;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    build(1,1,n);
    int Q = read();
    while(Q--){
        char op; cin >> op;
        int l = read(),r = read();
        if(op == 'Q') printf("%d\n",query(1,1,n,l,r));
        else if(op == 'A') printf("%d\n",queryh(1,1,n,l,r));
        else if(op == 'P'){
            int d = read();
            update_add(1,1,n,l,r,d);
        }else{
            int d = read();
            update_tag(1,1,n,l,r,d);
        }
    }
    return 0;
}
/*
2
0 0
3
P 1 2 4
C 1 2 1
A 2 2
*/