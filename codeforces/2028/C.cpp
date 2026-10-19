#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,m;
ll v,a[N],sum[N];
int pre[N],suf[N];
void solve(){
    n = read(); m = read(); v = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    for(int i=0;i<=n+1;i++) pre[i] = suf[i] = 0;
    ll now = 0;
    for(int i=1;i<=n;i++){
        now += a[i];
        if(now >= v){
            pre[i] = 1;
            now = 0;
        }
    }
    now = 0;
    for(int i=n;i;i--){
        now += a[i];
        if(now >= v){
            suf[i] = 1;
            now = 0;
        }
    }
    for(int i=1;i<=n;i++) pre[i] += pre[i-1];
    for(int i=n;i>=1;i--) suf[i] += suf[i+1];
    if(pre[n] < m) return puts("-1"),void();
    ll ans = 0;
    for(int i=0,j=1;i<=n;i++){
        while(j <= n && pre[i]+suf[j+1] >= m) j++;
        if(pre[i]+suf[j] >= m && i <= j) ans = max(ans,sum[j-1]-sum[i]);
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}