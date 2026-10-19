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
const int M = 2e6+10;
const int inf = 1e9;
int n,m,a[N];
struct Segment{
    int mn,mx,val;
}t[M<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt].mn = min(t[ls].mn,t[rs].mn);
    t[rt].mx = max(t[ls].mx,t[rs].mx);
    t[rt].val = max(t[ls].val,t[rs].val);
    if(t[rs].mn != inf && t[ls].mx != 0) t[rt].val = max(t[rt].val,t[rs].mn-t[ls].mx);
}
void build(int rt,int l,int r){
	t[rt].mn = inf; t[rt].mx = 0;
    t[rt].val = -inf;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void update(int rt,int l,int r,int pos,bool op){
    if(l == r){
        if(op){
            t[rt].mn = t[rt].mx = l;
            t[rt].val = 0;
        }else{
            t[rt].mn = inf; t[rt].mx = 0;
            t[rt].val = -inf;
        }
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos,op);
    else update(rs,mid+1,r,pos,op);
    push_up(rt);
}
int query(int rt,int l,int r,int k){
//	cout << l << " " << r << " " << t[rt].val << " " << t[rt].mx << " " << t[rt].mn << "\n";
    if(t[rt].val <= k) return t[rt].mx+1;
    int mid = (l+r) >> 1;
    if(t[ls].val > k) return query(ls,l,mid,k);
    if(t[rs].mn-t[ls].mx > k) return query(ls,l,mid,k);
    return query(rs,mid+1,r,k);
}
set<int> s;
signed main(){
    int T = read();
    build(1,1,2e6);
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read(),s.insert(a[i]);
        for(int i=1;i<=n;i++) update(1,1,2e6,a[i],1);
        m = read();
        while(m--){
            char op; cin >> op;
            int x = read();
            if(op == '+'){
                update(1,1,2e6,x,1);
                s.insert(x);
            }else if(op == '-'){
                update(1,1,2e6,x,0);
                s.erase(x);
            }else{
            	if(t[1].mn > x) cout << "1 ";
                else cout << query(1,1,2e6,x) << " ";
            }
        }
        for(int x : s) update(1,1,2e6,x,0);
        s.clear();
    }
    return 0;
}
/*
1
5
1 2 5 905 2000000
6
- 2
- 1
? 1
+ 4
+ 2
? 2

*/
