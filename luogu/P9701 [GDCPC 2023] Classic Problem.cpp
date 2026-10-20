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
const int N = 1e6+10;
const int inf = 1e9+7;
int n,m,cnt,fa[N];
int pre[N],nxt[N];
int get(int x){
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int getpre(int x){
	if(get(x) != get(pre[x])) return pre[x];
	return pre[x] = getpre(pre[x]);
}
int getnxt(int x){
	if(get(x) != get(nxt[x])) return nxt[x];
	return nxt[x] = getnxt(nxt[x]);
}
vector<pii> G[N];
unordered_map<int,int> W[N];
ll ans;
pii mv[N];
void solve(){
	ans = 0;
	n = read(); m = read();
	map<int,vector<pii>> E;
	map<int,int> mp;
	for(int i=1;i<=m;i++){
		int u = read(),v = read(),w = read();
		E[u].push_back(mk(v,w));
		E[v].push_back(mk(u,w));
	}
	
	int lst = 0;
	for(auto &[x,_] : E){
		if(x-lst >= 2){
			ans += x-lst-2;
			++cnt;
		}
		G[cnt] = _;
		lst = x;
		mp[x] = cnt;
		++cnt;
	}
	if(lst != n){
		ans += n-lst-1;
		++cnt;
	}
	n = cnt;
	for(int i=0;i<n;i++){
		fa[i] = i;
		pre[i] = (i-1+n)%n;
		nxt[i] = (i+1)%n;
		W[i].clear();
	}
	// cout << cnt << "\n";
	for(int x=0;x<n;x++)
		for(auto &[y,w] : G[x]) y = mp[y],W[x][y] = w;
	
	
	auto Lst = [&](int &x){
		x = (x-1+n)%n;
	};
	auto Nxt = [&](int &x){
		x = (x+1)%n;
	};
	auto dis = [&](int x,int y){
		// cout << x << " " << y << "\n";
		if(x == y) return inf;
		return abs(x-y);
	};
	auto searchpre = [&](int x){
		int y = pre[x];
		while(W[x].count(y)){
			y = (y-1+n)%n;
			// cout << y << "\n";
			if(get(y) == get(x)) y = pre[y];
			// cout << y << " " << pre[x] << "\n";
			if(y == pre[x]) return x;
		}
		// cout << y << "\n";
		return y;
	};
	auto searchnxt = [&](int x){
		int y = nxt[x];
		while(W[x].count(y)){
			y = (y+1)%n;
			if(get(y) == get(x)) y = nxt[y];
			if(y == nxt[x]) return x;
		}
		return y;
	};
	int tot = 0;
	while(true){
		// cerr << "114514\n";
		// vector<tuple<int,int,int>> V;
		for(int i=0;i<n;i++)
			if(i == fa[i]) mv[i].fi = inf,mv[i].se = i;
		for(int i=0;i<n;i++){
			int mn = inf,pos = i,x = 0;
			if(dis(i,x=searchpre(i)) < mn) mn = dis(i,x),pos = x;
			// cout << mn << " " << pos << " " << x << "\n";
			if(dis(i,x=searchnxt(i)) < mn) mn = dis(i,x),pos = x;
			for(auto &[y,w] : G[i])
				if(w < mn && get(y) != get(i)) mn = w,pos = y;
			// if(get(pos) != get(i)){
			// 	fa[get(pos)] = fa[get(i)];
			// 	tot++;
			// 	ans += mn;
			// }
			// cout << i << " " << pos  << " " << mn<< "\n";
			// V.emplace_back(i,pos,mn);
			if(mn < mv[get(i)].fi) mv[get(i)] = mk(mn,pos);
		}
		for(int i=0;i<n;i++)
			if(i == fa[i]){
				auto [w,y] = mv[i];
				if(get(i) != get(y)){
					fa[get(i)] = get(y);
					ans += w;
					tot++;
				}
			}
		// for(auto &[u,v,w] : V){
		// 	if(get(u) != get(v)){
		// 		fa[get(u)] = get(v);
		// 		tot++;
		// 		ans += w;
		// 	}
		// 	// cout << u << " " << v << " " << w << "\n";
		// }
		if(tot == n-1) break;
		for(int i=0;i<n;i++){
			pre[i] = getpre(i);
			nxt[i] = getnxt(i);
		}
		// cout << "\n\n";
	}
	cout << ans << "\n";
	for(int i=0;i<cnt;i++){
		G[i].clear();
		pre[i] = nxt[i] = -1;
	}
	cnt = 0;
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
/*
1
5 3
1 2 5
2 3 4
1 5 0
*/