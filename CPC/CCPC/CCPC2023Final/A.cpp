#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
int n,fa[N],ls[N],rs[N];
int stk[N],top,rt,siz[N];
ll a[N];
void dfs(int x,int ft){
    fa[x] = ft; siz[x] = 1;
    if(ls[x]) dfs(ls[x],x);
    if(rs[x]) dfs(rs[x],x);
    siz[x] += siz[ls[x]];
    siz[x] += siz[rs[x]];
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) fa[i] = ls[i] = rs[i] = 0;
    ll ans = 0,sum = 0;
    top = rt = 0;
    for(int i=1;i<=n;i++){
        while(top && a[stk[top]] < a[i]) ls[i] = stk[top--];
        if(top) rs[stk[top]] = i;
        stk[++top] = i; 
        ans += a[i];
        if(i > 1) sum += abs(a[i]-a[i-1]);
    }
    a[0] = 1e18;
    ll M = a[1]+a[n];
    rt = stk[1];
    dfs(rt,0);
    vector<pii> v;
    for(int i=1;i<=n;i++) v.push_back(mk(siz[i],i));
    sort(v.begin(),v.end());
    for(auto it : v){
        if(M >= sum) break;
        int x = it.se;
        if(sum-2*(a[fa[x]]-a[x]) <= M){
            ans += (sum-M+1)/2*siz[x];
            break;
        }else{
            ans += (a[fa[x]]-a[x])*siz[x];
            sum -= 2*(a[fa[x]]-a[x]);
        }
    }   
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
