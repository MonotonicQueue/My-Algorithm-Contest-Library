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
const int N = 5e5+10;
int n,m;
bool flag[N];
ll k;
struct node{
	ll x,y,t;
}a[N];
ll cnt[N];
bool chk(ll now){
	for(int i=1;i<=n;i++) cnt[i] = 0;
	ll rst = now;
	for(int i=1;i<=m;i++){
		if(a[i].t > now) continue;
		ll t = (a[i].y-1)/k+1+cnt[a[i].x]+a[i].t-1;
		if(t > now) continue;
		ll s = now-t+1;
		if(rst-a[i].t+1 < s) return false;
		cnt[a[i].x] += s;
		rst -= s;
	}
	return true;
}
void solve(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=m;i++){
		a[i].t = read();
		a[i].x = read(); a[i].y = read();
		flag[a[i].x] = true;
	}
	sort(a+1,a+1+m,[](node x,node y){return x.t > y.t;});
	auto chkif = [&](){
		int sum = 0;
		for(int i=1;i<=n;i++)
			sum += flag[i];
		return sum == 1;
	};
	if(chkif()) return puts("-1"),void();
	ll l = 0,r = 4e18,res = 0;
	while(l <= r){
		ll mid = (l+r) >> 1;
		if(chk(mid)) res = mid,l = mid+1;
		else r = mid-1;
	}
	cout << res << "\n";
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}