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
const int N = 5e5+10;
const int inf = 1e9;
int n,k,a[N],b[N];
struct Segment{
    struct node{
        int x,y;
        node operator+(const node &o)const{
            return a[x]+b[y] < a[o.x]+b[o.y] ? node{x,y} : o;
        }
    }va,vb,vc;
    /*
    va -> 最小的从左到右点对
    vb -> 最小的可行从右到左点对
    vc -> 最小的从右到左点对
    */
    int mnfl,tag;
    int mna,mnb,ca,cb;
    /*
    mnfl -> 从右到左最小流量
    mna/b -> 最小的a/b
    ca -> 能向左流的最小a
    cb -> 能向右流的最大b
    */
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline int mina(int x,int y){return a[x] < a[y] ? x : y;}
inline int minb(int x,int y){return b[x] < b[y] ? x : y;}
inline void push_up(int rt){
    t[rt].mnfl = min(t[ls].mnfl,t[rs].mnfl);
    t[rt].mna = mina(t[ls].mna,t[rs].mna);
    t[rt].mnb = minb(t[ls].mnb,t[rs].mnb);
    t[rt].va = t[ls].va+t[rs].va+Segment::node{t[ls].mna,t[rs].mnb};
    t[rt].vc = t[ls].vc+t[rs].vc+Segment::node{t[rs].mna,t[ls].mnb};
    if(t[ls].mnfl > t[rs].mnfl){
        t[rt].vb = t[ls].vc+t[rs].vb+Segment::node{t[rs].ca,t[ls].mnb};
        t[rt].ca = mina(t[ls].mna,t[rs].ca);
        t[rt].cb = t[rs].cb;
    }else if(t[ls].mnfl < t[rs].mnfl){
        t[rt].vb = t[rs].vc+t[ls].vb+Segment::node{t[rs].mna,t[ls].cb};
        t[rt].ca = t[ls].ca;
        t[rt].cb = minb(t[ls].cb,t[rs].mnb);
    }else{
        t[rt].vb = t[rs].vb+t[ls].vb+Segment::node{t[rs].ca,t[ls].cb};
        t[rt].ca = t[ls].ca;
        t[rt].cb = t[rs].cb;
    }
}
void build(int rt,int l,int r){
    if(l == r){
        t[rt].mna = t[rt].mnb = t[rt].ca = l;
        t[rt].va = t[rt].vc = Segment::node{l,l};
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void push_down(int rt){
    if(t[rt].tag){
        t[ls].tag += t[rt].tag;
        t[rs].tag += t[rt].tag;
        t[ls].mnfl += t[rt].tag;
        t[rs].mnfl += t[rt].tag;
        t[rt].tag = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr){
        t[rt].mnfl += d;
        t[rt].tag += d;
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
void push(int rt,int l,int r,int pos){
    if(l == r) return ;
    push_down(rt);
    int mid = (l+r) >> 1;
    if(pos <= mid) push(ls,l,mid,pos);
    else           push(rs,mid+1,r,pos);
    push_up(rt);
}
int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    a[0] = b[0] = inf;
    build(1,0,n);
    ll ans = 0;
    while(k--){
        Segment::node res = t[1].va+t[1].vb;
        int x = res.x,y = res.y;
        ans += a[x]+b[y];
        a[x] = b[y] = inf;
        if(x < y) update(1,0,n,x,y-1,1);
        if(x > y) update(1,0,n,y,x-1,-1);
        push(1,0,n,x); push(1,0,n,y);
    }
    cout << ans;
    return 0;
}