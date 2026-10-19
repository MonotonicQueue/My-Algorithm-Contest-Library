#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int mod = 998244353;
int n;
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
ll inv6 = fpow(6,mod-2);
ll calc(ll x){
    return x*(x+1)%mod*(2*x+1)%mod*inv6%mod;
}
vector<int> v;
ll ans = 0; int p = 1;
void dfs(int x,ll now=1){
    if(x == v.size()){
        ans += p*now*now%mod*calc(n/now);
        ans = (ans%mod+mod)%mod;
        return ;
    }
    dfs(x+1,now);
    p = -p;
    dfs(x+1,now*v[x]);
    p = -p;
}
void solve(){
    n = read(); int x = n;
    v.clear();
    for(int i=2;i*i<=x;i++){
        if(x % i == 0){
            v.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) v.push_back(x);
    ans = 0; p = 1;
    dfs(0);
    cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}