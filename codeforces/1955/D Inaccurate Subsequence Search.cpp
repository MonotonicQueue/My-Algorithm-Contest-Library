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
const int N = 3e5+10;
const int M = 1e6+10;
int n,m,k;
int a[N],b[N];
int cnt[M];
signed main(){
	int T = read();
	while(T--){
		n = read(); m = read(); k = read();
		k = m-k;
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=m;i++) b[i] = read();
		for(int i=1;i<=n;i++) cnt[a[i]] = 0;
		for(int i=1;i<=m;i++) cnt[b[i]] = 0;
		int x = 0;
		for(int i=1;i<=m;i++) cnt[b[i]]++,x++;
//		for(int i=1;i<=m;i++) cout << cnt[b[i]] << " ";
//		cout << "\n";
		for(int i=1;i<=m;i++){
			if(cnt[a[i]] > 0) x--;
			cnt[a[i]]--;
//			cout << cnt[a[i]] << " " << x << "\n";
		}
//		cout << x << "\n";
		int ans = x<=k;
		for(int i=m+1;i<=n;i++){
			if(cnt[a[i]] > 0) x--;
			cnt[a[i]]--;
			
			cnt[a[i-m]]++;
			if(cnt[a[i-m]] > 0) x++;
			ans += x<=k;
//			cout << x << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
