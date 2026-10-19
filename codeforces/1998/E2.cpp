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
int n,x,fa[N],siz[N];
int ls[N],rs[N];
int stk[N],top;
ll a[N],sum[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    if(x == y) return ;
    fa[y] = x,siz[x] += siz[y];
}
void solve(){
    n = read(); x = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) fa[i] = i,siz[i] = 1;
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    stk[top = 0] = 0;
    for(int i=1;i<=n;i++){
        while(top && a[stk[top]] < a[i]) top--;
        ls[i] = rs[stk[top]]; rs[stk[top]] = i;
        if(ls[i] && sum[i-1]-sum[stk[top]] >= a[i]) merge(i,ls[i]);
        stk[++top] = i;
        int x = stk[1];
        while(rs[x]){
            if(sum[i]-sum[x] >= a[x]) merge(rs[x],x);
            x = get(rs[x]); 
        }
        cout << siz[get(stk[1])] << " ";
    }
    cout << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
