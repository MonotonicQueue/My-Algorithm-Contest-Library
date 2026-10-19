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
const int N = 2e5+10;
int n,a[N],b[N];
ll ans;
bool chk(int mid){
	ll cnt = 0;
	for(int i=1;i<=n;i++) b[i] = a[i]-mid;
	queue<int> q;
	for(int i=1;i<=n;i++) if(b[i] >= 1) q.push(i);
	while(!q.empty()){
		int x = q.front(); q.pop();
		int t = (b[x]+1)/2;
		int y = x%n+1;
		b[y] += t; cnt += t;
		b[x] -= 2*t;
		if(b[y] >= 1 && b[y]-t < 1) q.push(y);
	}
	for(int i=1;i<=n;i++)
		if(b[i] != 0) return false;
	ans = min(ans,cnt);
	return true;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int l = 0,r = 1e9;
	ans = 1e18;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(chk(mid)) l = mid+1;
		else r = mid-1;
	}
	if(ans == 1e18) ans = -1;
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}