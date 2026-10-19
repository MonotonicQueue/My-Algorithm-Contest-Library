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
const int mod1 = 998244353,mod2 = 1e9+7,mod3 = 1e9+9;
struct modint{
    ll x1,x2,x3;
    modint operator+(const ll &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x < mod1 ? res.x1+x : res.x1+x-mod1;
        res.x2 = res.x2+x < mod2 ? res.x2+x : res.x2+x-mod2;
        res.x3 = res.x3+x < mod3 ? res.x3+x : res.x3+x-mod3;
        return res;
    }
    modint operator-(const ll &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x > 0 ? res.x1-x : res.x1-x+mod1;
        res.x2 = res.x2-x > 0 ? res.x2-x : res.x2-x+mod2;
        res.x3 = res.x3-x > 0 ? res.x3-x : res.x3-x+mod3;
        return res;
    }
    modint operator*(const ll &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x%mod1;
        res.x2 = res.x2*x%mod2;
        res.x3 = res.x3*x%mod3;
        return res;
    }
    modint operator+(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1+x.x1 < mod1 ? res.x1+x.x1 : res.x1+x.x1-mod1;
        res.x2 = res.x2+x.x2 < mod2 ? res.x2+x.x2 : res.x2+x.x2-mod2;
        res.x3 = res.x3+x.x3 < mod3 ? res.x3+x.x3 : res.x3+x.x3-mod3;
        return res;
    }
    modint operator-(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1-x.x1 > 0 ? res.x1-x.x1 : res.x1-x.x1+mod1;
        res.x2 = res.x2-x.x2 > 0 ? res.x2-x.x2 : res.x2-x.x2+mod2;
        res.x3 = res.x3-x.x3 > 0 ? res.x3-x.x3 : res.x3-x.x3+mod3;
        return res;
    }
    modint operator*(const modint &x)const{
        modint res = {x1,x2,x3};
        res.x1 = res.x1*x.x1%mod1;
        res.x2 = res.x2*x.x2%mod2;
        res.x3 = res.x3*x.x3%mod3;
        return res;
    }
    bool operator<(const modint x)const{
        if(x1 != x.x1) return x1 < x.x1;
        if(x2 != x.x2) return x2 < x.x2;
        return x3 < x.x3;
    }
    bool operator == (const modint x)const{
        return x1 == x.x1 && x2 == x.x2 && x3 == x.x3;
    }
    bool operator != (const modint x)const{
        return x1 != x.x1 || x2 != x.x2 || x3 != x.x3;
    }
};
int n,Q,len[N<<2];
ll P = 13331;
modint t1[N<<2],t2[N<<2],pw[N];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    len[rt] = len[ls]+len[rs];
    t1[rt] = t1[ls]+pw[len[ls]]*t1[rs];
    t2[rt] = pw[len[rs]]*t2[ls]+t2[rs];
}
void build(int rt,int l,int r){
    if(l == r){
        len[rt] = 1;
        t1[rt] = t2[rt] = {l,l,l};
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
void update(int rt,int l,int r,int pos,int d){
    if(l == r){
        t1[rt] = t2[rt] = {d,d,d};
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos,d);
    else           update(rs,mid+1,r,pos,d);
    push_up(rt);
}
modint query1(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t1[rt];
    int mid = (l+r) >> 1;
    if(mid <  ql) return query1(rs,mid+1,r,ql,qr);
    if(mid >= qr) return query1(ls,l,mid,ql,qr);
    return query1(ls,l,mid,ql,mid)+query1(rs,mid+1,r,mid+1,qr)*pw[mid-ql+1];
}
modint query2(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t2[rt];
    int mid = (l+r) >> 1;
    if(mid <  ql) return query2(rs,mid+1,r,ql,qr);
    if(mid >= qr) return query2(ls,l,mid,ql,qr);
    return query2(ls,l,mid,ql,mid)*pw[qr-mid]+query2(rs,mid+1,r,mid+1,qr);
}
int fa[N];
vector<int> v[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    assert(x != y);
    if(v[x].size() < v[y].size()) swap(x,y);
    fa[y] = x;
    for(int z : v[y]){
        v[x].push_back(z);
        update(1,1,n,z,x);
    }
    v[y].clear();
}
inline void init(){
    pw[0] = modint{1,1,1};
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    for(int i=1;i<=n;i++) fa[i] = i,v[i].push_back(i);
    build(1,1,n);
}
int main(){
    n = read(); Q = read();
    init();
    while(Q--){
        int op = read();
        if(op == 1){
            int l = read(),r = read();
            if(l == r) continue;
            while(true){
                int m1, m2;
                if((r-l+1) & 1) m1 = (l+r)/2-1,m2 = (l+r)/2+1;
                else m1 = (l+r)/2,m2 = (l+r)/2+1;
                if(query1(1,1,n,l,m1) == query2(1,1,n,m2,r)) break;
                int L = 1,R = m1-l+1,res = -1;
                while(L <= R){
                    int mid = (L+R) >> 1;
                    if(query1(1,1,n,m1-mid+1,m1) != query2(1,1,n,m2,m2+mid-1))
                        res = mid,R = mid-1;
                    else L = mid+1;
                }
                assert(~res);
                merge(m1-res+1,m2+res-1);
            }
        }else{
            int a = read(),b = read(),x = read(),y = read();
            if(a-b != x-y) puts("Not equal");
            else if(query1(1,1,n,a,b) == query1(1,1,n,x,y)) puts("Equal");
            else puts("Unknown");
        }
    }
	return 0;
} 