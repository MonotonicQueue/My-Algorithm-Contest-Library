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
const int N = 2e5+10;
const int C = 30;
const int mod = 1e9+7;
int n,m,k,q;
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
vector<pii> G[N];
int val[N];
void clear(){
    for(int i=1;i<=n+m;i++) val[i] = -1;
    for(int i=1;i<=n+m;i++) G[i].clear();
}
bool flag;
void dfs(int x){
    for(auto it : G[x]){
        int y = it.fi,z = it.se;
        if(val[y] == -1){
            val[y] = val[x]^z;
            dfs(y);
        }else
            flag &= (val[x]^val[y]) == z;
    }
}
void solve(){
    n = read(); m = read();
    k = read(); q = read();
    clear();
    for(int i=1;i<=k;i++){
        int x = read(),y = read(),z = read();
        G[x].push_back(mk(y+n,z));
        G[y+n].push_back(mk(x,z));
    }
    int cnt = 0; flag = true;
    for(int i=1;i<=n+m;i++){
        if(~val[i]) continue;
        val[i] = 0; dfs(i);
        cnt++;
    }
    cout << flag*fpow(1<<30,cnt-1) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}