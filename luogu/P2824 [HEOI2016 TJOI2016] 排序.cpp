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
int n,a[N],m,q;
struct node{
    int op,l,r;
}b[N];
int t[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt] = t[ls]+t[rs];
}
void build(int rt,int l,int r,int x){
    tag[rt] = -1;
    if(l == r){
        t[rt] = a[l] >= x;
        return ;
    }
    int mid = (l+r)>>1;
    build(ls,l,mid,x);
    build(rs,mid+1,r,x);
    push_up(rt);
}
inline void push_down(int rt,int l,int r){
    int mid = (l+r)>>1;
    if(~tag[rt]){
        t[ls] = (mid-l+1)*tag[rt];
        t[rs] = (r-mid)*tag[rt];
        tag[ls] = tag[rs] = tag[rt];
        tag[rt] = -1;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql > qr) return ;
    if(ql <= l && r <= qr){
        t[rt] = (r-l+1)*d;
        tag[rt] = d;
        return ;
    }
    push_down(rt,l,r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    push_down(rt,l,r);
    int mid = (l+r)>>1,res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
bool chk(int x){
    build(1,1,n,x);
    for(int i=1;i<=m;i++){
        int l = b[i].l,r = b[i].r,op = b[i].op,cnt = query(1,1,n,l,r);
        if(op){
            update(1,1,n,l,l+cnt-1,1);
            update(1,1,n,l+cnt,r,0);
        }else{
            update(1,1,n,r-cnt+1,r,1);
            update(1,1,n,l,r-cnt,0);
        }
    }
    return query(1,1,n,q,q);
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++)
        b[i].op = read(),b[i].l = read(),b[i].r = read();
    q = read();
    int l = 1,r = n,res = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(chk(mid)) res = mid,l = mid+1;
        else r = mid-1;
    }
    cout << res;
	return 0;
}
