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
ll n,c;
ll a[N],mx[N],sum[N];
void solve(){
	n = read(); c = read();
	for(int i=1;i<=n;i++) a[i] = read();
	mx[n] = a[n];
	for(int i=n-1;i;i--) mx[i] = max(mx[i+1],a[i]);
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	vector<int> ans;
	if(a[1]+c >= mx[1]) ans.push_back(0);
	else ans.push_back(1);
	ll maxn = a[1];
	for(int i=2;i<=n;i++){
		if(a[i] > maxn && a[i] > a[1]+c){
			if(a[i] >= mx[i]) ans.push_back(0);
			else{
				if(sum[i]+c >= mx[i]) ans.push_back(i-1);
				else ans.push_back(i);
			}
		}else{
			if(sum[i]+c >= mx[i]) ans.push_back(i-1);
			else ans.push_back(i);
		}
		maxn = max(maxn,a[i]);
	}
	for(int x : ans) cout << x << " ";
	cout << "\n";
}
int main(){
	int T = read();
    while(T--) solve();
	return 0;
}