#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 4e6+10;
int n,a[N],mn[N];
ll g[N],f[N];
#define ls (x<<1)
#define rs (x<<1|1)
void dfs(int x,int l,int r){
    if(l == r){
        mn[x] = a[l];
        g[x] = 0;
        f[x] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    dfs(ls,l,mid);
    dfs(rs,mid+1,r);
    mn[x] = min(mn[ls],mn[rs]);
    f[x] = max(f[ls],max(f[rs],g[ls]+g[rs]));
    g[x] = max(f[ls]-mn[x],max(f[rs]-mn[x],g[ls]+g[rs]));
}
void solve(){
    n = read();
    for(int i=0;i<(1<<n);i++) a[i] = read();
    dfs(1,0,(1<<n)-1);
    cout << f[1] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
