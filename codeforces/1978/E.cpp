#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;
int n,a[N],b[N],c[N],d[N],sum[N];
void solve(){
	n = read();
	string s;
	cin >> s;
	for(int i=0;i<n;i++) a[i+1] = s[i]-'0';
	cin >> s;
	for(int i=0;i<n;i++) b[i+1] = s[i]-'0';
	for(int i=1;i<=n;i++) c[i] = a[i],d[i] = b[i];
	for(int i=1;i+2<=n;i++)
		if(c[i] == c[i+2] && c[i] == 0) d[i+1] = 1;
	for(int i=1;i+2<=n;i++)
		if(d[i] == d[i+2] && d[i] == 1) c[i+1] = 1;
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+c[i];
	int Q = read();
	while(Q--){
		int l = read(),r = read();
		if(r-l+1 <= 3){
			if(l == r) cout << a[l] << "\n";
			else if(l+1 == r) cout << a[l]+a[r] << "\n";
			else{
				int ans = a[l]+a[r];
				if(a[l+1] || (b[l] && b[r])) ans++;
				cout << ans << "\n";
			}
		}else{
			int ans = sum[r]-sum[l-1];
			if(!a[l] && c[l]) ans--;
			if(!a[r] && c[r]) ans--;
			if(c[l+1] && !a[l+1] && !b[l]) ans--;
			if(c[r-1] && !a[r-1] && !b[r]) ans--;
			cout << ans << "\n";
		}
	}
}
int main(){
	int T = read();
    while(T--) solve();
	return 0;
}
