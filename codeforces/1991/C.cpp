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
const int N = 2e5+10;
int n,a[N];
int ans[N],tot;
bool chk(){
	for(int i=1;i<=n;i++)
		if(a[i]) return false;
	return true;
}
void solve(){
	if(chk()){
		puts("0"); puts("");
		return ;
	}
	for(int k=1;k<=40;k++){
		int mx = 0,mn = 1e9;
		for(int i=1;i<=n;i++) mx = max(mx,a[i]),mn = min(mn,a[i]);
		ans[k] = (mx+mn)/2;
		for(int i=1;i<=n;i++) a[i] = abs(a[i]-ans[k]);
		if(chk()){
			cout << k << "\n";
			for(int i=1;i<=k;i++) cout << ans[i] << " ";
			cout << "\n";
			return ;
		}
	}
	puts("-1");
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		solve();
	}
	return 0;
}
