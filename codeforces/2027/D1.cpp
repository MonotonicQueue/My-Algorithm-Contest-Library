#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e5+10;
const ll inf = 1e18;
int n,m;
ll a[N],b[N],sum[N];
vector<ll> f[N];
void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read(),sum[i] = sum[i-1]+a[i];
	for(int i=1;i<=m;i++) b[i] = read();
	for(int i=0;i<=n;i++){
		f[i].clear();
		f[i].resize(m+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++) f[i][j] = inf;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int l = j,r = n,res = -1;
			f[j][i] = min(f[j][i],f[j][i-1]);
			while(l <= r){
				int mid = (l+r) >>1;
				if(sum[mid]-sum[j-1] <= b[i]) res = mid,l = mid+1;
				else r = mid-1;
			}
			if(res == -1) continue;
			f[res][i] = min(f[res][i],f[j-1][i]+m-i);
		} 
	}
	ll ans = 1e18;
	for(int i=1;i<=m;i++) ans = min(ans,f[n][i]);
	if(ans == 1e18) cout << "-1\n";
	else cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 
