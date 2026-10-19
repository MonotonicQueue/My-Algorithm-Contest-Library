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
const int N = 1e5+10;
int n,a[N],k;
int siz[N];
set<pii> s;
vector<int> v[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++){
		k = max(a[i],k);
		v[a[i]].push_back(i);
	}
	s.insert(mk(1,n));
	siz[0] = 1;
	for(int i=1;i<=k;i++){
		for(int x : v[i]){
			auto it = s.upper_bound(mk(x,n));
			it--;
			int l = it->fi,r = it->se;
			s.erase(it);
			if(l <= x-1) s.insert(mk(l,x-1));
			if(r >= x+1) s.insert(mk(x+1,r));
		}
		siz[i] = s.size();
	}
	for(int i=1;i<=k;i++){
		ll ans = 0;
		for(int j=0;j<=k;j+=i) ans += siz[j];
		cout << ans << " ";
	}
	return 0;
}
