#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 1e6+10;
int n,a[N];
#define ls (x<<1)
#define rs (x<<1|1)
map<int,int> f[N];
int get(int x,int v){
    if(f[x].count(v)) return f[x][v];
    if(v < min(a[ls],a[rs])) return f[x][v] = x;
    if(a[ls] < min(v,a[rs])) return f[x][v] = get(ls,v);
    int y = min(v,a[ls]);
    int p1 = get(ls,y),p2 = get(rs,y);
    if(p1 < p2){
        if(y == v) return f[x][v] = p1;
        else return f[x][v] = get(rs,v);
    }else{
        if(y == v) return f[x][v] = p2;
        else return f[x][v] = get(ls,v);
    }
}
void solve(int x){
    if(x > n) return ;
    if(a[x] < min(a[ls],a[rs])){
        solve(ls); solve(rs);
        return ;
    }
    if(a[ls] < min(a[x],a[rs])){
        swap(a[ls],a[x]);
        solve(ls); solve(rs);
        return ;
    }
    int v = min(a[x],a[ls]),u = max(a[x],a[ls]);
    a[x] = a[rs];
    int p1 = get(ls,v),p2 = get(rs,v);
    if(p1 < p2) a[ls] = v,a[rs] = u;
    else a[ls] = u,a[rs] = v;
    solve(ls); solve(rs);
}
int main(){
    memset(a,0x3f,sizeof(a));
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    solve(1);
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    return 0;
}
