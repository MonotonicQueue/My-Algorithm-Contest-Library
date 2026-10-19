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
const int N = 1e6+10;
int n;
ll a[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) a[i] = a[i]+i-1-n;
	vector<pair<ll,int> > v;
	for(int i=1;i<=n;i++){
		v.emplace_back(a[i],i);
	}
	sort(v.begin(),v.end());
	map<ll,bool> mp;
	ll ans = n;
	mp[0] = 1;
	for(int i=1;i<=n;i++){
		auto [u,d] = v[i-1];
		if(mp[u]) mp[u+d-1] = 1,ans = max(ans,n+u+d-1);
	}
	cout << ans <<"\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 
