#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e5+10;
int n;
pll a[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i].se = read();
    for(int i=1;i<=n;i++) a[i].fi = read();
    sort(a+1,a+1+n,[](pll x,pll y){return x.fi+x.se < y.fi+y.se;});
    ll sum = 0;
    priority_queue<ll> q;
    for(int i=1;i<=n;i++){
        if(sum <= a[i].fi) sum += a[i].se,q.push(a[i].se);
        else if(!q.empty() && a[i].se < q.top())
            sum -= q.top(),q.pop(),sum += a[i].se,q.push(a[i].se);
    }
    cout << q.size() << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
	return 0;
}
