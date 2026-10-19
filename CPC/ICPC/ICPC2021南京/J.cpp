#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
vector<ll> v;
map<pair<ll,ll>,ll> mp;
ll dfs(ll a,ll b){
	if(a == 1) return 0;
	if(mp.count(mk(a,b))) return mp[mk(a,b)];
	ll d = b-a,ans = a-1;
	for(auto x : v){
		if(d % x != 0) continue;
		ll y = a%x;
		if(y != a) ans = min(ans,y+1+dfs((a-y)/x,(b-y)/x));
		ans = min(ans,x-y+1+dfs((a+x-y)/x,(b+x-y)/x));
	}
	return mp[mk(a,b)] = ans;
}
void solve(){
	ll a = read(),b = read();
	if(a > b) swap(a,b);
	ll d = b-a,tmp = d;
	v.clear(); mp.clear();
	for(ll i=2;i*i<=tmp;i++){
		if(tmp % i == 0){
			v.push_back(i);
			while(tmp % i == 0) tmp /= i;
		}
	}
	if(tmp > 1) v.push_back(tmp);
	cout << dfs(a,b) << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
