#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
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
int n,m;
char s[N];
int fa[N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
ll ans,siz[N],sum[N];
void merge(int x,int y){
	x = get(x); y = get(y);
	if(x == y) return ;
	fa[y] = x;
	ans -= siz[x]*(siz[x]-1)+siz[y]*(siz[y]-1);
	siz[x] += siz[y];
	ans += siz[x]*(siz[x]-1);
}
vector<int> G[N];
int main(){
	n = read(); m = read();
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=n;i++)
		if(s[i] == '1')
			for(int x : G[i]) if(s[x] == '1') merge(x,i);
	for(int i=n;i;i--){
		int t = get(i);
		ans -= siz[t]*(siz[t]-1); siz[t]++;
		ans += siz[t]*(siz[t]-1);
		for(int x : G[i]) if(x >= i || s[x] == '1') merge(x,i);
		sum[i] = ans/2;
	}
	for(int i=1;i<=n;i++) cout << sum[i] << "\n";
	return 0;
}

