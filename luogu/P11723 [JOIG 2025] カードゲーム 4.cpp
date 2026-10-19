#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
int n,k;
void solve(){
	n = read(); k = read();
	vector<int> a[2];
	for(int i=1;i<=n;i++){
		int x = read();
		a[x & 1].push_back(x);
	}
	ll ans = 0;
	for(int i=0;i<=1;i++){
		sort(a[i].begin(),a[i].end(),greater<int>());
		int cnt = 0;
		ll sum = 0;
		for(int x : a[i]){
			sum += x;
			cnt++;
			if(cnt == k) break;
		}
		if(cnt == k) ans = max(ans,sum);
	}
	cout << ans;
}
int main(){
	int T = 1;
	while(T--) solve();
    return 0;
}