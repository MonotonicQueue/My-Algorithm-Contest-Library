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
const int M = 5e5+10;
int n,m,Q;
struct node{
    int l,r,x;
    bool operator < (const node &d)const{
        return x < d.x;
    }
};
struct Ques{int l1,r1,l2,r2,id;};
bool cmp1(Ques x,Ques y){return x.l1 > y.l1;}
bool cmp2(Ques x,Ques y){return x.r1 < y.r1;}
vector<node> v[N];
ll ans[M];
struct Segment{
    ll mx,mxh,tag,mx_tag;
    bool flag;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].mx = max(t[ls].mx,t[rs].mx);
    t[rt].mxh = max(t[ls].mxh,t[rs].mxh);
}
inline void change(int rt,ll tag,ll mx_tag){
    t[rt].mx_tag = max(t[rt].mx_tag,t[rt].tag+mx_tag);
    t[rt].tag += tag;
    t[rt].mxh = max(t[rt].mxh,t[rt].mx+mx_tag);
    t[rt].mx += tag;
}
void clearh(int rt){
    change(ls,t[rt].tag,t[rt].mx_tag);
    change(rs,t[rt].tag,t[rt].mx_tag);
    t[rt].tag = t[rt].mx_tag = 0;
    t[rt].mxh = t[rt].mx;
    t[rt].flag = true;
}
inline void push_down(int rt){
    if(t[rt].flag){
        clearh(ls); clearh(rs);
        t[rt].flag = false;
    }
    change(ls,t[rt].tag,t[rt].mx_tag);
    change(rs,t[rt].tag,t[rt].mx_tag);
    t[rt].tag = t[rt].mx_tag = 0;
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr){
        change(rt,d,d);
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt].mxh;
    push_down(rt);
    int mid = (l+r) >> 1; ll res = 0;
    if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
    if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
    return res;
}
inline void add(int x){
    for(auto it : v[x]) update(1,1,n,it.l,it.r,it.x);
}
inline void del(int x){
    for(int i=v[x].size()-1;~i;i--)
        update(1,1,n,v[x][i].l,v[x][i].r,-v[x][i].x);
}
void solve(int l,int r,vector<Ques> q){
    if(l > r) return ;
    int mid = (l+r) >> 1;
    for(int i=l;i<=mid;i++) add(i);
    if(l == r){
        clearh(1);
        for(auto it : q) ans[it.id] = max(ans[it.id],query(1,1,n,it.l2,it.r2));
        del(l);
        return ;
    }
    vector<Ques> Ql,Qr,now;
    for(auto it : q)
        if(it.r1 <= mid) Ql.push_back(it);
        else if(it.l1 > mid) Qr.push_back(it);
        else now.push_back(it);
    sort(now.begin(),now.end(),cmp2);
    clearh(1);
    for(int i=mid+1,j=0;i<=r;i++){
        add(i);
        while(j < now.size() && now[j].r1 == i){
            ans[now[j].id] = max(ans[now[j].id],query(1,1,n,now[j].l2,now[j].r2));
            j++;
        }
    }
    for(int i=r;i>=mid+1;i--) del(i);
    solve(mid+1,r,Qr);
    sort(now.begin(),now.end(),cmp1);
    clearh(1);
    for(int i=mid,j=0;i>=l;i--){
        while(j < now.size() && now[j].l1 == i){
            ans[now[j].id] = max(ans[now[j].id],query(1,1,n,now[j].l2,now[j].r2));
            j++;
        }
        del(i);
    }
    solve(l,mid,Ql);
}
int main(){
    n = read(); m = read(); Q = read();
    for(int i=1;i<=m;i++){
        int l1 = read(),l2 = read(),
            r1 = read(),r2 = read(),x = read();
        v[l1].push_back(node{l2,r2,x});
        v[r1+1].push_back(node{l2,r2,-x});
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    vector<Ques> q;
    for(int i=1;i<=Q;i++){
        int l1 = read(),l2 = read(),
            r1 = read(),r2 = read();
        q.push_back(Ques{l1,r1,l2,r2,i});
    }
    solve(1,n,q);
    for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
    return 0;
}