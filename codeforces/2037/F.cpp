#include<bits/stdc++.h>
#define int long long
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
int n,m,p;
ll h[N],a[N];
bool chk(int mid){
	vector<pii> v;
	for(int i=1;i<=n;i++){
		int ct = (h[i]+mid-1)/mid;
		if(ct > m) continue;
		int d = m-ct;
		int l = a[i]-d,r = a[i]+d;
		v.emplace_back(l,1);
		v.emplace_back(r+1,-1);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(auto [x,y] : v){
		sum += y;
		if(sum >= p) return true;
	}
	return false;
}
void solve(){
	n = read(); m = read(); p = read();
	for(int i=1;i<=n;i++) h[i] = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int l = 1,r = 1e9,res = -1;
	// chk(10);
	while(l <= r){
		int mid = (l+r) >> 1;
		if(chk(mid)) res = mid,r = mid-1;
		else l = mid+1;
	}
	cout << res << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
