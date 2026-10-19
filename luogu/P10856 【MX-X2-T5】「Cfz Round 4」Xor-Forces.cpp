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
int T,k,n,Q;
int a[N],now;
struct node{
    int lc,rc;
    int cnt;
};
vector<node> t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
node merge(node x,node y){
    node res;
    res.lc = x.lc; res.rc = y.rc;
    res.cnt = x.cnt+y.cnt-(x.rc==y.lc);
    return res;
}
void build(int rt,int l,int r,int d){
    t[rt].resize(1<<d);
    if(l == r){
        t[rt][0].lc = t[rt][0].rc = a[l];
        t[rt][0].cnt = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid,d-1);
    build(rs,mid+1,r,d-1);
    for(int i=0;i<(1<<(d-1));i++){
        t[rt][i] = merge(t[ls][i],t[rs][i]);
        t[rt][i^(1<<(d-1))] = merge(t[rs][i],t[ls][i]);
    }
}
node query(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr) return t[rt][now & ((1<<(d+1))-1)];
    int mid = (l+r) >> 1;
    if((now >> d) & 1){
        if(ql >  mid) return query(ls,l,mid,ql^(1<<d),qr^(1<<d),d-1);
        if(qr <= mid) return query(rs,mid+1,r,ql^(1<<d),qr^(1<<d),d-1);
        return merge(query(rs,mid+1,r,ql^(1<<d),r,d-1)
                    ,query(ls,l,mid,l,qr^(1<<d),d-1));
    }else{
        if(ql >  mid) return query(rs,mid+1,r,ql,qr,d-1);
        if(qr <= mid) return query(ls,l,mid,ql,qr,d-1);
        return merge(query(ls,l,mid,ql,mid,d-1),query(rs,mid+1,r,mid+1,qr,d-1));
    }
}
int main(){
    T = read(); k = read(); Q = read();
    n = (1<<k)-1;
    for(int i=0;i<=n;i++) a[i] = read();
    build(1,0,n,k);
    int lst_ans = 0;
    while(Q--){
        int op = read();
        if(op == 1){
            int x = read();
            x ^= T*lst_ans;
            now ^= x;
        }else{
            int l = read(),r = read();
            l ^= T*lst_ans; r ^= T*lst_ans;
            if(l > r) swap(l,r);
            printf("%d\n",lst_ans=query(1,0,n,l,r,k-1).cnt);
        }
    }
    return 0;
}