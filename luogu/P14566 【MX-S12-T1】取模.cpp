#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
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
const int N = 1e5+10;
int n,a[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+1+n);
	n = unique(a+1,a+1+n)-a-1;
	int ans = a[n]-a[1];
	if(n > 1) ans = max(ans,a[n-1]);
	cout << ans << "\n";
} 
int main(){
	int T = read();
	while(T--) solve(); 
	return 0;
}
