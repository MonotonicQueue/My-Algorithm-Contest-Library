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
const int M = 1e7+10;
int n,k,w[N],b[N],m;
int pr[M],cnt,d[M];
void init(int m = 1e7){
    d[1] = 1;
    for(int i=2;i<=m;i++){
        if(!d[i]) d[i] = i,pr[++cnt] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=m;j++){
            d[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
int calc(int x){
    int res = 0;
    while(x != 1){
        int t = d[x];
        while(x % t == 0) x /= t;
        res += t;
    }
    return res;
}
long double f[N];
struct Line{
    long double k,b;
    long double val(int x){
        return k*x+b;
    }
}a[N];
int t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void insert(int rt,int l,int r,int id){
    if(!t[rt]) return t[rt] = id,void();
    int mid = (l+r) >> 1,x = b[mid];
    if(a[t[rt]].val(x) > a[id].val(x)) swap(t[rt],id);
    if(l == r) return ;
    if(a[id].val(b[l]) < a[t[rt]].val(b[l])) insert(ls,l,mid,id);
    else insert(rs,mid+1,r,id);
}
double query(int rt,int l,int r,int pos){
    if(!t[rt]) return 1e9;
    double res = a[t[rt]].val(b[pos]);
    if(l == r) return res;
    int mid = (l+r) >> 1;
    if(pos <= mid) return min(query(ls,l,mid,pos),res);
    return min(query(rs,mid+1,r,pos),res);
}
int main(){
    init();
    n = read(); f[1] = read(); k = read();
    for(int i=1;i<=n;i++){
        int x = read();
        w[i] = calc(x);
        b[++m] = w[i];
    }
    
    sort(b+1,b+1+m);
    m = unique(b+1,b+1+m)-b-1;
    for(int i=1;i<=n;i++) w[i] = lower_bound(b+1,b+1+m,w[i])-b;
    a[1] = Line{1.0/f[1],1.0*b[w[1]]/f[1]};
    insert(1,1,m,1);
    for(int i=2;i<=n;i++){
        f[i] = 1.0/query(1,1,m,w[i])+k;
        a[i] = Line{1.0/f[i],1.0*b[w[i]]/f[i]};
        insert(1,1,m,i);
    }
    long double ans = 0.0;
    for(int i=1;i<=n;i++) ans += f[i];
    printf("%.10Lf",ans);
    return 0;
}