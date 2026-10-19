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
ll L,R,k,pw[15];
bool vis[15];
namespace Sol1{
	int num[15];
	ll f[15][N];
	ll dfs(int x,bool flag,ll y){
		if(x == -1) return y == 0;
		if(!flag && ~f[x][y]) return f[x][y];
		int lim = flag ? num[x] : 9;
		ll res = 0;
		for(int i=0;i<=lim;i++){
			if(!vis[i]) continue;
			ll t = y-i*pw[x]%k;
			t = (t%k+k)%k;
			res += dfs(x-1,flag&(i==num[x]),t);
		}
		return f[x][y] = res;
	}
	ll calc(ll x){
		memset(f,-1,sizeof(f));
		for(int i=0;i<=11;i++) num[i] = (x/pw[i])%10;
		if(vis[0]) return dfs(11,1,0);
		ll res = 0;
		for(int i=0;i<=11;i++)
			if(x > pw[i]) res += dfs(i-1,0,0);
			else res += dfs(i-1,1,0);
		return res;
	}
	void solve(){
		cout << calc(R)-calc(L-1);
	}
}
namespace Sol2{
	ll calc(ll x){
		auto chk = [&](ll x){
			while(x){
				if(!vis[x%10]) return false;
				x /= 10;
			}
			return true;
		};
		ll res = 0;
		for(ll i=1;i*k<=x;i++) res += chk(i*k);
		return res;
	}
	void solve(){
		cout << calc(R)-calc(L-1);
	}
}
int main(){
	pw[0] = 1;
	for(int i=1;i<=11;i++) pw[i] = pw[i-1]*10;
	k = read(); L = read(); R = read();
	string s; cin >> s;
	for(char c : s) vis[c-'0'] = true;
	if(k <= 100000) Sol1::solve();
	else			Sol2::solve();
    return 0;
}
