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
ll n,k;
ll a[N];
void solve(){
	n = read(); k = read();
	if(k & 1) return puts("NO"),void();
	for(int i=1;i<=n;i++) a[i] = i;
	for(ll l=1,r=n;l<r;){
		if(2*(r-l) <= k) k -= 2*(r-l),swap(a[l],a[r]),l++,r--;
		else l++;
	}
	if(!k){
		puts("YES");
		for(int i=1;i<=n;i++) cout << a[i] << " ";
		cout << "\n";
	}else puts("NO");
}
int main(){
	int T = read();
    while(T--) solve();
	return 0;
}
/*
1
4 4 5
*/