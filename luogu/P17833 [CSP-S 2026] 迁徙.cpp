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
const int N = 2e6+10;
int n,L[N],R[N],f[N],g[N],cntL[N],cntR[N];
ll d,a[N];
void solve(){
    n = read(); d = read(); ll ans = 0;
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=0;i<=n+1;i++) L[i] = R[i] = i,cntL[i] = cntR[i] = 0;
    for(int i=1,j=0;i<=n;i++){
        while(j < n && (a[j+1]-a[i]) <= d) L[++j] = i;
        f[i] = min(i,L[i+1])-L[i]+(L[i+1] != L[i] ? f[L[i]] : 0);
    }
    for(int i=n,j=n+1;i>=1;i--){
        while(j > 1 && (a[i]-a[j-1]) <= d) R[--j] = i;
        g[i] = R[i]-max(i,R[i-1])+(R[i-1] != R[i] ? g[R[i]] : 0);
    }
    for(int i=1;i<=n;i++) f[i]++,cntL[L[i]] += (L[i] != i);
    for(int i=1;i<=n;i++) g[i]++,cntR[R[i]] += (R[i] != i);
    for(int i=1;i<n;i++){
        ll x = cntR[i+1],y = cntL[i];
        if(L[i] == i || R[i+1] == i+1 || R[i] == i+1 || L[i+1] == i) continue;
        if(R[L[i]] == i+1) x += f[L[i]]-1;
        if(L[R[i+1]] == i) y += g[R[i+1]]-1;
        ans += x*y;
    }
    cout << ans << '\n';
}
int main(){
    read(); int T = read();
    while(T--) solve();
    return 0;
}
