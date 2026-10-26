#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
#define ls rt<<1
#define rs rt<<1|1
const int N = 5e5+10;
int n,Q;
int sum[N<<2];
int b[N*4],m;
pii a[N],q[N];
void solve(){
	n = read(); Q = read();
	for(int i=1;i<=n;i++){
		int l = read()+1,r = read();
		a[i] = mk(l,r);
		b[++m] = l; b[++m] = r;
	}
	ll ans = n;
	for(int i=1;i<=Q;i++){
		int l = read(),r = read()+1;
		q[i] = mk(l,r);
		b[++m] = l; b[++m] = r;
	}
	sort(b+1,b+1+m);
	m = unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=n;i++){
		int l = a[i].fi,r = a[i].se;
		l = lower_bound(b+1,b+1+m,l)-b;
		r = lower_bound(b+1,b+1+m,r)-b;
		sum[l]++; sum[r+1]--;
	}
	for(int i=1;i<=m;i++) sum[i] += sum[i-1];
	for(int i=1;i<=Q;i++){
		int l = q[i].fi,r = q[i].se;
		l = lower_bound(b+1,b+1+m,l)-b;
		r = lower_bound(b+1,b+1+m,r)-b;
		ans += sum[l]+sum[r];
		sum[l] = sum[r] = 0;
		cout << ans << "\n";
	}
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}
