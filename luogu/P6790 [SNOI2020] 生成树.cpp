#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 5e5+10;
const int mod = 998244353;
int n,m;
map<int,pair<ll,ll>> G[N];
inline void link(int x,int y,pair<ll,ll> w){
	if(G[x].count(y)){
		pair<ll,ll> t = G[x][y],res = mk((w.fi*t.se+w.se*t.fi)%mod,w.se*t.se%mod);
		G[x][y] = G[y][x] = res;
	}else G[x][y] = G[y][x] = w;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		link(u,v,mk(1,1));
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(int(G[i].size()) <= 2) q.push(i);
	ll ans = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(int(G[x].size()) == 1){
			ans = ans*(G[x].begin()->se.fi)%mod;
		}else if(int(G[x].size()) == 2){
			int t = G[x].begin()->fi,d = G[x].rbegin()->fi;
			pair<ll,ll> w1 = G[x].begin()->se,w2 = G[x].rbegin()->se;
			link(t,d,mk(w1.fi*w2.fi%mod,(w1.fi*w2.se+w1.se*w2.fi)%mod));
		}
		for(auto it : G[x]){
			G[it.fi].erase(x);
			if(G[it.fi].size() == 2)
				q.push(it.fi);
		}
		G[x].clear();
	}
	cout << ans << "\n";
    return 0;
}