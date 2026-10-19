#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e6+10;
int m;
pii b[N];
int len[N],tmp[N],tot;
int mx[N<<2],cnt[N<<2],tag[N<<2];
vector<pii> v[N];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    if(mx[ls] > mx[rs]) mx[rt] = mx[ls],cnt[rt] = cnt[ls];
    else if(mx[ls] < mx[rs]) mx[rt] = mx[rs],cnt[rt] = cnt[rs];
    else mx[rt] = mx[ls],cnt[rt] = cnt[ls]+cnt[rs];
}
void build(int rt,int l,int r){
    mx[rt] = cnt[rt] = tag[rt] = 0;
    if(l == r){
        cnt[rt] = len[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void change(int rt,int d){
    tag[rt] += d;
    mx[rt] += d;
}
inline void push_down(int rt){
    if(tag[rt]){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql > qr) return ;
    if(ql <= l && r <= qr) return change(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int work(int n,vector<pii> a){
    tot = 0;
    for(int i=1;i<=m;i++){
        if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
        tmp[++tot] = a[i].fi;
        tmp[++tot] = a[i].se;
    }
    sort(tmp+1,tmp+1+tot);
    tot = unique(tmp+1,tmp+1+tot)-tmp-1;
    for(int i=1;i<=m;i++){
        a[i].fi = lower_bound(tmp+1,tmp+1+tot,a[i].fi)-tmp;
        a[i].se = lower_bound(tmp+1,tmp+1+tot,a[i].se)-tmp;
    }
    for(int i=1;i<tot;i++) len[i] = tmp[i+1]-tmp[i];
    len[tot] = tmp[1]+n-tmp[tot];
    for(int i=1;i<=tot;i++) v[i].clear();
    build(1,1,tot);
    auto ask = [&](){
        return mx[1] == m ? cnt[1] : 0;
    };
    for(int i=1;i<=m;i++){
        if(a[i].fi == 1){
            update(1,1,tot,a[i].fi,a[i].se-1,1);
            v[a[i].se].push_back(mk(i,0));
        }else{
            update(1,1,tot,1,a[i].fi-1,1);
            update(1,1,tot,a[i].se,tot,1);
            v[a[i].fi].push_back(mk(i,1));
            v[a[i].se].push_back(mk(i,0));
        }
    }
    int ans = ask();
    for(int i=1;i<=tot;i++){
        for(auto it : v[i]){
            int x = it.fi,op = it.se;
            if(op == 0){
                update(1,1,tot,a[x].fi,a[x].se-1,-1);
                update(1,1,tot,1,a[x].fi-1,1);
                update(1,1,tot,a[x].se,tot,1);
            }else{
                update(1,1,tot,a[x].fi,a[x].se-1,1);
                update(1,1,tot,1,a[x].fi-1,-1);
                update(1,1,tot,a[x].se,tot,-1);
            }
            ans = max(ans,ask());
        }
    }
    return ans;
}
vector<pii> xc,yc;
int main(){
    m = read();
    int X = read(),Y = read();
    xc.push_back(mk(0,0));
    yc.push_back(mk(0,0));
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),x = read(),y = read();
        xc.push_back(mk(u,x));
        yc.push_back(mk(v,y));
    }
    cout << 1ll*work(X,xc)*work(Y,yc);
    return 0;
}