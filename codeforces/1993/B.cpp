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
ll n,a[N];
vector<int> v;
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		int cnt =0 ;
		for(int i=1;i<=n;i++) if(a[i] % 2 == 0) cnt++;
		if(cnt == n) puts("0");
		else{
			ll mx = 0,pos = 0;
			v.clear();
			for(int i=1;i<=n;i++)
				if(a[i] & 1) mx = max(mx,a[i]);
				else v.push_back(a[i]);
			sort(v.begin(),v.end());
			int ans = 0;
			for(auto y : v){
				if(mx > y) mx = mx+y,ans++;
				else mx = mx+2*y,ans+=2;
			}
			cout << min(ans,cnt+1) << "\n";
		}
	}
	return 0;
}
