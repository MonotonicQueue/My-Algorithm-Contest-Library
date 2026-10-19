#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
ll n,a[N],lcm;
ll gcd(ll x,ll y){
	return y ? gcd(y,x%y) : x;
}
ll Lcm(ll x,ll y){
	return x*y/gcd(x,y);
}
unordered_map<int,int> mp;
int b[N],tot;
void work(){
	mp.clear();
	for(int i=1;i<=n;i++) mp[a[i]] = 1;
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		if(a[n] % a[i]){
			cout << n << "\n";
			return ;
		}
	tot = 0;
	for(int i=2;i*i<=a[n];i++)
		if(a[n] % i == 0){
			b[++tot] = i;
			if(i*i != a[n]) b[++tot] = a[n]/i;
		}
	int ans = 0;
	for(int i=1;i<=tot;i++){
		int lcm = 1,res = 0;
		if(mp[b[i]]) continue;
		for(int j=1;j<=n;j++){
			if(b[i] % a[j]) continue;
			lcm = Lcm(lcm,a[j]);
			res++;
		}
		if(lcm != b[i]) continue;
		ans = max(ans,res);
	}
	cout << ans << "\n";
}
int main(){
	int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
		work();
    }
	return 0;
}