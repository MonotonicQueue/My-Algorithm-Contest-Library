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
const int N = 1e5+10;
int n,m;
ll a[N],b[N],stk[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    a[n+1] = m; a[0] = 0;
    sort(b+1,b+1+n);
    int r = 0;
    for(int i=1;i<=n;i++) b[i] += b[i-1];
    for(int i=1;i<=n;i++) stk[++r] = b[i];
    
    priority_queue<ll> q;
    ll ans = 0;
    for(int i=n+1;i;i--){
        while(stk[r] >= a[i]) r--;
        int l = r;
        while(l && stk[l] >= a[i-1]) l--;
        l++;
        if(l > r) q.push(a[i]-a[i-1]);
        else{
            int T = r-l;
            while(T--)
                if(!q.empty()) ans += q.top(),q.pop();
            
            if(!q.empty()){
                ll x = q.top(); q.pop();
                if(a[i]-stk[l] > x){
                    ans += a[i]-stk[l];
                    q.push(x+stk[l]-a[i-1]);
                }else{
                    ans += x;
                    q.push(a[i]-a[i-1]);
                }
            }else ans += a[i]-stk[l],q.push(stk[l]-a[i-1]);
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
