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
int n;
int a[N];
namespace Segment{
    struct Tree{
        int ls,rs;
        int mn;
    }t[N*20]; int cnt,root[N];
    #define lc t[rt].ls
    #define rc t[rt].rs
    inline void push_up(int rt){
        t[rt].mn = min(t[lc].mn,t[rc].mn);
    }
    int build(int l,int r){
        int rt = ++cnt;
        if(l == r) return rt;
        int mid = (l+r) >> 1;
        t[rt].ls = build(l,mid);
        t[rt].rs = build(mid+1,r);
        return rt;
    }
    int update(int u,int l,int r,int pos,int d){
        int rt = ++cnt;
        t[rt] = t[u];
        if(l == r){
            t[rt].mn = d;
            return rt;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid) t[rt].ls = update(lc,l,mid,pos,d);
        else           t[rt].rs = update(rc,mid+1,r,pos,d);
        push_up(rt);
        return rt;
    }
    int query(int rt,int l,int r,int d){
        if(l == r) return l;
        int mid = (l+r) >> 1;
        if(t[lc].mn < d) return query(lc,l,mid,d);
        return query(rc,mid+1,r,d);
    }
    void init(){
        root[0] = build(0,n);
        for(int i=1;i<=n;i++) root[i] = update(root[i-1],0,n,a[i],i);
    }
}
int mex(int l,int r){
    return Segment::query(Segment::root[r],0,n,l);
}
vector<int> v[N],add[N],del[N];
vector<pii> h[N];
int cnt[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    Segment::init();
    for(int i=0;i<=n;i++) v[i].push_back(0);
    for(int i=1;i<=n;i++) v[a[i]].push_back(i);
    for(int i=0;i<=n;i++) v[i].push_back(n+1);
    for(int i=1;i<=n;i++) a[i] ? h[0].push_back(mk(i,i)) : h[1].push_back(mk(i,i));
    for(int i=1;i<=n;i++){
        for(auto it : h[i-1]){
            int l = it.fi,r = it.se;
            int L = *(--lower_bound(v[i-1].begin(),v[i-1].end(),l));
            int R = *upper_bound(v[i-1].begin(),v[i-1].end(),r);
            if(L) h[mex(L,r)].push_back(mk(L,r));
            if(R <= n) h[mex(l,R)].push_back(mk(l,R));
        }
        vector<pii> G = h[i]; h[i].clear();
        sort(G.begin(),G.end(),[](pii x,pii y){return x.fi == y.fi ? x.se < y.se : x.fi > y.fi;});
        int R = 1e9;
        for(auto it : G)
            if(R > it.se) h[i].push_back(it),R = it.se;
    }
    for(int i=0;i<=n;i++){
        for(auto it : h[i]){
            int l = it.fi,r = it.se;
            int L = *(--lower_bound(v[i].begin(),v[i].end(),l))+1;
            int R = *upper_bound(v[i].begin(),v[i].end(),r)-1;
            add[r-l+1].push_back(i);
            del[R-L+2].push_back(-i);

        }
    }
    set<int> s;
    for(int i=0;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++){
        for(int x : add[i]){
            cnt[x]++;
            if(cnt[x] == 1) s.erase(x);
        }
        for(int x : del[i]){
            cnt[-x]--;
            if(cnt[-x] == 0) s.insert(-x);
        }
        cout << *s.begin() << " ";
    }
	return 0;
} 


