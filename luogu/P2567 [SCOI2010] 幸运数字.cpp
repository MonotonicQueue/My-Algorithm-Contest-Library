#include<bits/stdc++.h>
#define ll long long
#define int128 __int128
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5010;
ll n,num[N];
ll l,r;
void dfs(ll mul){
	if(mul > r) return ;
	if(mul) num[++n] = mul;
	dfs(mul*10+6); dfs(mul*10+8);
}
bool cmp(int x,int y){
	return x > y;
}
ll ans;
void solve(int x,ll mul,int k){
	if(x > n){
		// cout << mul << "\n";
		if(mul != 1)
			ans = ans+k*(r/mul-l/mul);
		return ;
	}
	solve(x+1,mul,k);
	int128 d = int128(mul/__gcd(mul,num[x]))*num[x];
	if(d <= r) solve(x+1,d,-k);
}
ll tmp[N],tot;
bool vis[N];
inline void change(){
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		tmp[++tot] = num[i];
		for(int j=i+1;j<=n;j++) if(num[j] % num[i] == 0) vis[j] = true;
	}
	n = tot;
	for(int i=1;i<=tot;i++) num[i] = tmp[i];
}
int main(){
	l = read(); r = read();
	dfs(0); l--;
	
	change();
	sort(num+1,num+1+n,cmp);
	solve(1,1,-1);
	cout << ans;
	return 0;
}
// 1 10000000000
