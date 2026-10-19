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
int n,m,a[N],pos[N];
struct Segment{
    int lmx,rmx,sum;
    #define ls rt<<1
    #define rs rt<<1|1
}t[N<<2];
bool cmp(int x,int y){
    return a[x] < a[y];
}
Segment merge(Segment x,Segment y){
    Segment res = {0,0,0};
    res.sum = x.sum+y.sum;
    res.lmx = max(x.lmx,x.sum+y.lmx);
    res.rmx = max(y.rmx,y.sum+x.rmx);
    return res;
}
void build(int rt,int l,int r){
    if(l == r){
        t[rt].lmx = t[rt].rmx = t[rt].sum = -1;
        return ;
    }
    int mid = (l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[rt] = merge(t[ls],t[rs]);
}
void update(int rt,int l,int r,int pos){
    if(l == r){
        t[rt].sum = t[rt].lmx = t[rt].rmx = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos);
    else           update(rs,mid+1,r,pos);
    t[rt] = merge(t[ls],t[rs]);
}
Segment query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    int mid = (l+r) >> 1;
    if(ql > mid) return query(rs,mid+1,r,ql,qr);
    if(qr <= mid) return query(ls,l,mid,ql,qr);
    return merge(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
int ans[N];
void calc(int flag){
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int j = i;
        while(j < n && a[pos[j+1]] == a[pos[i]]) ++j;
        for(int k=i;k<=j;k++) update(1,1,n,pos[k]);
        for(int k=i;k<=j;k++){
            int lmx = query(1,1,n,1,pos[k]).rmx,rmx = query(1,1,n,pos[k],n).lmx;
            ans[pos[k]] = max(ans[pos[k]],lmx+rmx-1-flag);
        }
        i = j;
    }
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) pos[i] = i;
    sort(pos+1,pos+1+n,cmp);
    calc(1);
    reverse(pos+1,pos+1+n);
    calc(0);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]/2);
	return 0;
}
/*
50
9 2 36 40 5 48 12 7 18 27 15 24 41 39 35 4 38 44 17 37 46 25 42 23 10 19 22 8 34 20 3 28 1 11 31 14 45 6 30 33 47 21 43 13 32 49 29 26 16 50
*/