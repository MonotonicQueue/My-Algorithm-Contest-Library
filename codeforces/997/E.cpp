#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1.2e5+10;
int n,m,p[N];
vector<pii> q[N];
ll ans[N];
ll mn[N<<2],add[N<<2],sum[N<<2],sumh[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    mn[rt] = min(mn[ls],mn[rs]);
    sum[rt] = 0;
    if(mn[ls] == mn[rt]) sum[rt] += sum[ls];
    if(mn[rs] == mn[rt]) sum[rt] += sum[rs];
    sumh[rt] = sumh[ls]+sumh[rs];
}
inline void change_add(int rt,ll d){
    mn[rt] += d; add[rt] += d;
}
inline void change_tag(int rt,ll d){
    sumh[rt] += d*sum[rt];
    tag[rt] += d;
}
inline void push_down(int rt){
    if(add[rt]){
        change_add(ls,add[rt]);
        change_add(rs,add[rt]);
        add[rt] = 0;
    }
    if(tag[rt]){
        if(mn[ls] == mn[rt]) change_tag(ls,tag[rt]);
        if(mn[rs] == mn[rt]) change_tag(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void build(int rt,int l,int r){
    mn[rt] = l; sum[rt] = 1;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr) return change_add(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return sumh[rt];
    push_down(rt);
    int mid = (l+r) >> 1; ll res = 0;
    if(ql <= mid) res += query(ls,l,mid,ql,qr);
    if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
    return res;
}
int stk1[N],top1,stk2[N],top2;
int main(){
    n = read();
    for(int i=1;i<=n;i++) p[i] = read();
    m = read();
    for(int i=1;i<=m;i++){
        int l = read(),r = read();
        q[r].emplace_back(l,i);
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        update(1,1,n,1,n,-1);
        while(top1 && p[stk1[top1]] > p[i]){
            update(1,1,n,stk1[top1-1]+1,stk1[top1],p[stk1[top1]]-p[i]);
            top1--;
        }
        stk1[++top1] = i;
        while(top2 && p[stk2[top2]] < p[i]){
            update(1,1,n,stk2[top2-1]+1,stk2[top2],p[i]-p[stk2[top2]]);
            top2--;
        }
        stk2[++top2] = i;
        change_tag(1,1);
        for(auto [l,id] : q[i]) ans[id] = query(1,1,n,l,i);
    }
    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
	return 0;
}