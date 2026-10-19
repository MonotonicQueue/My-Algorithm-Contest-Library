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
const int M = (1<<20)+10;
const int mod = (1<<20)-1;
unsigned pw[M][22],C[N][22];
void init(int n=2e5,int m=(1<<20)){
    C[0][0] = 1;
    for(int i=1;i<=n;i++){
        C[i][0] = 1;
        for(int j=1;j<=20;j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
    for(int i=0;i<=m;i++){
        pw[i][0] = 1;
        for(int j=1;j<=20;j++) pw[i][j] = pw[i][j-1]*i;
    }
}
int n,q;

unsigned a[N],tag[N<<2];
struct node{
    unsigned g[20];
    node(){
        memset(g,0,sizeof(g));
    }
}t[N<<2];
node operator*(const node &x,const node &y){
    node res;
    for(int i=0;i<20;i++) for(int j=0;i+j<20;j++)
        res.g[i+j] += x.g[i]*y.g[j];
    return res;
}
#define ls rt<<1
#define rs rt<<1|1
void build(int rt,int l,int r){
    if(l == r){
        t[rt].g[0] = a[l];
        t[rt].g[1] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[rt] = t[ls]*t[rs]; 
}
inline void change(int rt,unsigned d){
    for(int i=0;i<20;i++){
        unsigned res = 0;
        for(int j=i;j<20;j++)
            res += t[rt].g[j]*C[j][j-i]*pw[d][j-i];
        t[rt].g[i] = res;
    }
    tag[rt] = (tag[rt]+d)&mod;
}
inline void push_down(int rt){
    if(tag[rt]){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,unsigned d){
    if(ql <= l && r <= qr) return change(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    t[rt] = t[ls]*t[rs];
}
node query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return t[rt];
    push_down(rt);
    int mid = (l+r) >> 1;
    if(mid >= qr) return query(ls,l,mid,ql,qr);
    if(mid <  ql) return query(rs,mid+1,r,ql,qr);
    return query(ls,l,mid,ql,qr)*query(rs,mid+1,r,ql,qr);
}
int main(){
    init();
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    build(1,1,n);
    while(q--){
        int op = read(),l = read(),r = read();
        if(op == 1){
            int d = read();
            update(1,1,n,l,r,d);
        }else{
            cout << (query(1,1,n,l,r).g[0]&mod) << "\n";
        }
    }
	return 0;
}