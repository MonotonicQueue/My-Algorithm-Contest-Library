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
const ll inf = 1e13;
int n,fa[N];
ll a[N],f[N];
vector<int> G[N];
void dfs(int x){
	if(G[x].empty()) return f[x] = inf,void();
	ll l = 0,r = 0;
	for(int y : G[x]){
		dfs(y);
		r += f[y];
	}
	f[x] = -inf;
	auto chk = [&](ll mid){
		ll sum = 0;
		for(int y : G[x]){
			if(a[y]-f[y] > a[x]-mid) return false;
			sum += max(mid-a[x]+a[y],0ll);
		}
		return sum <= mid;
	};
	while(l <= r){
		ll mid = (l+r) >> 1;
		if(chk(mid)) f[x] = mid,l = mid+1;
		else r = mid-1;
	}
}
int main(){
	// freopen("water.in","r",stdin);
	// freopen("water.out","w",stdout);
	int C = read(),T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=2;i<=n;i++)
			G[fa[i] = read()].push_back(i);
		for(int i=1;i<=n;i++) a[i] = read();
		dfs(1);
		puts(f[1] >= a[1] ? "Huoyu" : "Shuiniao");
	}
    return 0;
}