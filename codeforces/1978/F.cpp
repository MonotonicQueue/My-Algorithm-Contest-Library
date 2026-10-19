#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 2e6+10;
int n,k,a[N],b[N];
int pr[N],cnt,vis[N];
int fa[N];
void init(int m = 1e6){
	for(int i=2;i<=m;i++){
		if(!vis[i]) vis[i] = i,pr[++cnt] = i;
		for(int j=1;j<=cnt&&pr[j]*i<=m;j++){
			vis[pr[j]*i] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}
int get(int x){
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
	x = get(x); y = get(y);
	if(x == y) return ;
	fa[x] = y;
}
vector<int> v[N];
void solve(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	ll ans = 0;
	for(int i=1;i<=n;i++)
		if(a[i] == 1) ans += n;
	for(int i=1;i<=n;i++)
		b[i-1] = b[i-1+n] = a[i];
	set<int> s;
	for(int i=1;i<2*n;i++){
		fa[i] = i;
		int ttt = b[i];
		while(ttt > 1){
			v[vis[ttt]].push_back(i);
			int tmp = vis[ttt];
			s.insert(tmp);
			while(ttt % tmp == 0) ttt /= tmp;
		}
	}
	for(int x : s){
		int pre = 0;
		for(int i : v[x]){
			if(pre && i-pre <= k)
				merge(pre,i);
			pre = i;
		}
		v[x].clear();
	}
	for(int i=1;i<2*n;i++)
		if(fa[i] == i && b[i] > 1) ans++;
	cout << ans << "\n";
}
int main(){
	init();
	int T = read();
    while(T--) solve();
	return 0;
}