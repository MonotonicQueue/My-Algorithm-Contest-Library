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
int n,Q;
ll a[N];
struct Segment{
    int l,r,ans;
    ll sum;
    vector<pair<ll,int> > pre,suf;
    Segment operator+(const Segment &z) const{
        Segment res;
        res.sum = sum+z.sum;
        res.ans = max(ans,z.ans);
        res.l = l; res.r = z.r;
        for(int i=0;i<suf.size();i++)
            for(int j=0;j<z.pre.size();j++){
                ll mx = max(a[suf[i].se],a[z.pre[j].se]);
                ll S = 0; int len = 1;
                if(i+1 < suf.size()){
                    S += suf[i+1].fi-a[suf[i+1].se];
                    len -= suf[i+1].se+1;
                }else S += sum,len -= l;
                if(j+1 < z.pre.size()){
                    S += z.pre[j+1].fi-a[z.pre[j+1].se];
                    len += z.pre[j+1].se-1;
                }else S += z.sum,len += z.r;
                if(2*mx < S) res.ans = max(res.ans,len);
            }
        res.pre = pre;
        for(int i=0;i<z.pre.size();i++){
            ll S = sum+z.pre[i].fi;
            if(a[z.pre[i].se]*2 >= S) res.pre.push_back(mk(S,z.pre[i].se));
        }
        res.suf = z.suf;
        for(int i=0;i<suf.size();i++){
            ll S = z.sum+suf[i].fi;
            if(a[suf[i].se]*2 >= S) res.suf.push_back(mk(S,suf[i].se));
        }
        return res;
    }
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
    t[rt].l = l; t[rt].r = r;
    if(l == r){
        t[rt].ans = -1;
        t[rt].sum = a[l];
        t[rt].pre.clear();
        t[rt].suf.clear();
        t[rt].pre.push_back(mk(a[l],l));
        t[rt].suf.push_back(mk(a[l],l));
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[rt] = t[ls]+t[rs];
}
void update(int rt,int l,int r,int pos){
    if(l == r){
        t[rt].ans = -1;
        t[rt].sum = a[l];
        t[rt].pre.clear();
        t[rt].suf.clear();
        t[rt].pre.push_back(mk(a[l],l));
        t[rt].suf.push_back(mk(a[l],l));
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos);
    else           update(rs,mid+1,r,pos);
    t[rt] = t[ls]+t[rs];
}
Segment query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    int mid = (l+r) >> 1;
    if(ql > mid) return query(rs,mid+1,r,ql,qr);
    else if(qr <= mid) return query(ls,l,mid,ql,qr);
    return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
int main(){
    int T = read();
    while(T--){
        n = read(); Q = read();
        for(int i=1;i<=n;i++) a[i] = read();
        build(1,1,n);
        while(Q--){
            int op = read();
            if(op == 1){
                int l = read(),r = read();
                printf("%d\n",query(1,1,n,l,r).ans);
            }else{
                int i = read(); ll x = read();
                a[i] = x;
                update(1,1,n,i);
            }
        }
    }
    return 0;
}