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
const int inf = 1e9;
int n,m,q;
int a[N],b[N];
int t[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt] = max(t[ls],t[rs]);
}
void build(int rt,int l,int r){
    t[rt] = -inf;
    tag[rt] = 0;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void change(int rt,int d){
    t[rt] += d;
    tag[rt] += d;
}
void push_down(int rt){
    if(tag[rt]){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr) return change(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
set<int> s[N];
int c[N];
void solve(){
    n = read(); m = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read(),c[a[i]] = i;
    for(int i=1;i<=m;i++) b[i] = read();
    for(int i=1;i<=n;i++) s[i].clear();
    build(1,1,m);
    for(int i=1;i<=m;i++) s[b[i]].insert(i);
    for(int i=1;i<=n;i++){
        if(s[i].empty()) continue;
        int x = *s[i].begin();
        update(1,1,m,x,m,-1);
        update(1,1,m,x,x,inf+c[i]);
    }
    puts(t[1] > 0 ? "TIDAK" : "YA");
    while(q--){
        int x = read(),y = read();
        int st = *s[b[x]].begin();
        s[b[x]].erase(x);
        if(st == x){
            update(1,1,m,st,m,1);
            update(1,1,m,st,st,-inf-c[b[x]]);
            if(!s[b[x]].empty()){
                st = *s[b[x]].begin();
                update(1,1,m,st,m,-1);
                update(1,1,m,st,st,inf+c[b[x]]);
            }
        }
        b[x] = y;
        if(!s[y].empty() && *s[y].begin() > x){
            st = *s[y].begin();
            update(1,1,m,st,m,1);
            update(1,1,m,st,st,-inf-c[y]);
        }
        s[y].insert(x);
        st = *s[y].begin();
        if(st == x){
            update(1,1,m,st,m,-1);
            update(1,1,m,st,st,inf+c[y]);    
        }
        puts(t[1] > 0 ? "TIDAK" : "YA");
    }
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
