#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int mod = 998244353;
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
int n,m;
vector<int> G[N];
ll f[N];
int main(){
    int id = read();
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        ll sum = 0;
        for(int x : G[i]) sum = (sum+f[i-1]-f[x-1]+mod)%mod;
        f[i] = (G[i].size()+1+sum)%mod;
        f[i] = (f[i]+f[i-1])%mod;
    }
    cout << f[n];
	return 0;
} 