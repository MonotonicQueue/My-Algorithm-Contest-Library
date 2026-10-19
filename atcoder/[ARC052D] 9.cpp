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
const ll B = 1e5-1;
ll m,k,ans;
ll a[N];
map<ll,ll> mp;
int main(){
	k = read(); m = read();
	for(int i=1;i<=B+1;i++) a[i] = (a[i/10]+(i % 10))%k;
	for(int i=1;i<=min(m,B);i++) ans += a[i] == (i%k);
	if(m <= B) return cout << ans,0;
	for(int i=0;i<=B;i++) mp[(a[i]-i%k+k)%k]++;
	for(int i=1;i<m/(B+1);i++){
		ll x = i*100000ll%k-a[i];
		x = (x%k+k)%k;
		ans += mp[x];
	}
	mp.clear();
	for(int i=0;i<=m%(B+1);i++) mp[(a[i]-i%k+k)%k]++;
	ll i = m/(B+1); ll x = i*100000ll%k-a[i];
	x = (x%k+k)%k; ans += mp[x];
	cout << ans;
    return 0;
}
