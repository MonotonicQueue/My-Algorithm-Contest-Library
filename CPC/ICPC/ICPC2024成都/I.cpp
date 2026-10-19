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
const int N = 2e5+10;
int n,q,a[N];
vector<int> v[N];
void init(int n = 2e5){
	for(int i=1;i<=n;i++)
		for(int j=1;j*j<=i;j++)
			if(i % j == 0){
				v[i].push_back(j);
				if(j*j != i) v[i].push_back(i/j);
			}
}
int t[N],d[N];
void solve(){
	n = read(); q = read();
	a[n+1] = 2e9+1; a[0] = -2e9-1;
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=0;i<=n;i++) t[i] = d[i] = 0;
	t[0] = n;
	int cnt = 0;
	auto upd = [&](int x,int y){
		t[d[x]]--;
		d[x] += y;
		t[d[x]]++;
	};
	auto add = [&](int x,int w){
		if(a[x] <= a[x+1]) return ;
		cnt += w;
		for(int y : v[x]) upd(y,w);
	};
	for(int i=1;i<=n;i++) add(i,1);
	cout << t[cnt] << "\n";
	while(q--){
		int u = read();
		add(u-1,-1); add(u,-1);
		a[u] = read();
		add(u-1, 1); add(u, 1);
		cout << t[cnt] << "\n";
	}
}
int main(){
	init();
    int T = read();
	while(T--) solve();
	return 0;
}