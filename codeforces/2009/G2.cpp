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
const int N = 4e5+10;
int n,q,k,a[N];
ll cnt[N],f[N];
int stk[N],top;

multiset<int> s;
vector<pii> v[N];
ll ans[N];

ll sum[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
    tag[rt] = -1; sum[rt] = 0;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
inline void change(int rt,int l,int r,ll d){
    sum[rt] = d*(r-l+1);
    tag[rt] = d;
}
void push_down(int rt,int l,int r){
    if(~tag[rt]){
        int mid = (l+r) >> 1;
        change(ls,l,mid,tag[rt]);
        change(rs,mid+1,r,tag[rt]);
        tag[rt] = -1;
    }
}
inline void push_up(int rt){
    sum[rt] = sum[ls]+sum[rs];
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
    if(ql <= l && r <= qr) return sum[rt];
    push_down(rt,l,r);
    int mid = (l+r) >> 1;
    ll res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
void solve(){
    n = read(); k = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read(),v[i].clear();
    for(int i=1;i<=n;i++) a[i] = a[i]+n-i+1;
    for(int i=1;i<=2*n;i++) cnt[i] = 0;
    s.clear();
    for(int i=1;i<=n;i++){
        if(i > k){
            f[i-k] = k-*s.rbegin();
            s.erase(s.find(cnt[a[i-k]]));
            cnt[a[i-k]]--;
            if(cnt[a[i-k]]) s.insert(cnt[a[i-k]]);
        }
        if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
        cnt[a[i]]++;
        s.insert(cnt[a[i]]);
    }
    f[n-k+1] =  k-*s.rbegin();
    for(int i=1;i<=q;i++){
        int l = read(),r =  read();
        v[l].push_back(mk(r-k+1,i));
    }
    n = n-k+1; f[n+1] = 0;
    top = 1;
    stk[top] = n+1;
    build(1,1,n);
    for(int i=n;i;i--){
        while(top && f[i] < f[stk[top]]) top--;
        update(1,1,n,i,stk[top]-1,f[i]);
        for(auto it : v[i]){
            ans[it.se] = query(1,1,n,i,it.fi);
        }
        stk[++top] = i;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}