#include <bits/stdc++.h>
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
const int N = 2e5+10;
int n,ans,res,siz;
int a[N],b[N];
int fa[N],sz[N];
int sumji[N],sumou[N];
vector<int>v[N];
map <int,int> m;
int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y){
	int fx = get(x),fy = get(y);
	if(fx != fy){
		fa[fx] = fy;
		sz[fy] += sz[fx];
	}
}
int calc(int x){
	if(sz[x] & 1){
		if(x & 1) return sumji[x+sz[x]-1]-sumji[x-1];
		return sumou[x+sz[x]-1]-sumou[x-1];
	}
	return max(sumji[x+sz[x]-1]-sumji[x-1],sumou[x+sz[x]-1]-sumou[x-1]);
}
void init(){
    for(int i=1;i<=n;i++) sz[i] = sumji[i] = sumou[i] = 0;
    for(int i=1;i<=n;i++) fa[i] = i;
}
void solve(){
	res = 0;
	n = read();
	init();
	for(int i=1;i<=n;i++)
		a[i] = b[i] = read();
	sort(a+1,a+n+1);
	a[n+1] = 0;
	int tmp = 0, cnt = 0;
	for(int i=n;i>=1;i--){
		if(a[i] != a[i+1]) {
			tmp = i;
			++cnt;
		}
		m[a[i]] = tmp;
	}
	for(int i=1;i<=n;i++) v[m[b[i]]].push_back(i);
	for(int i=1;i<=n;i++){
		if(b[i] == a[n]){
			if (i & 1) sumji[i] = 1;
			else sumou[i] = 1;
		}
		sumji[i] += sumji[i-1];
		sumou[i] += sumou[i-1];
	}
	ans = siz = res = 0;
	int tail = n+1;
	while(true){
		while (a[tail-1] == a[tail]) -- tail;
		--tail;
		if(tail == 0) break;
		for(int x : v[m[a[tail]]]){
			sz[x] = 1; fa[x] = x;
			res += calc(x);
			++siz;
			if(x != 1 && b[x-1] >= a[tail] && get(x-1) != get(x)){
				res -= calc(x);
				res -= calc(get(x-1));
				--siz;
				siz -= (sz[get(x-1)]+1)/2;
				merge(x,x-1);
				res += calc(get(x));
				siz += (sz[get(x-1)]+1)/2;
			}
			if(x != n && b[x+1] >= a[tail] && get(x) != get(x+1)){
				res -= calc(get(x));
				res -= calc(get(x+1));
				siz -= (sz[get(x)]+1)/2;
				siz -= (sz[get(x+1)]+1)/2;
				merge(x+1,x);
				res += calc(get(x));
				siz += (sz[get(x)]+1)/2;
			}
		}
		if(res) ans = max(ans,siz+a[tail]+a[n]);
		else ans = max(ans,siz-1+a[tail]+a[n]);
	}
	for(int i=1;i<=n;i++) v[i].clear();
	m.clear();
	cout << ans << '\n';
}
signed main () {
	int T = read();
	while(T--) solve();
	return 0;
}