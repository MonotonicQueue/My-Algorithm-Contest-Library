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
const int N = 2e5+10;
int n,a[N];
vector<int> G[N];
int f[N],siz[N];
void dfs(int x){
	siz[x] = 1;
	f[x] = 1e9;
	for(int y : G[x]){
		dfs(y);
		siz[x] += siz[y];
		f[x] = min(f[x],f[y]);
	}
	if(siz[x] == 1) f[x] = a[x];
	else if(a[x] < f[x]){
		if(x != 1) f[x] = (a[x]+f[x])/2;
	}
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=2;i<=n;i++){
			int x = read();
			G[x].push_back(i);
		}
		dfs(1);
		cout << f[1]+a[1] << "\n";
	}
	return 0;
}
