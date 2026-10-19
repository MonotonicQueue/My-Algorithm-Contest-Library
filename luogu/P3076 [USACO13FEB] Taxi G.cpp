#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
int main(){
	int n = read(),m = read();
	vector<int> s = {m},t = {0};
	ll ans = 0;
	for(int i=1;i<=n;i++){
		int u = read(),v = read();
		s.push_back(u);
		t.push_back(v);
		ans += abs(u-v);
	}
	sort(all(s)); sort(all(t));
	for(int i=0;i<=n;i++) ans += abs(s[i]-t[i]);
	cout << ans;
    return 0;
}
