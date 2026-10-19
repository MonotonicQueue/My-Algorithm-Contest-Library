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
ll n,siz[N],pos;
vector<int> G[N];
void dfs1(int x,int fa){
	siz[x] = 1;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs1(y,x);
		siz[x] += siz[y];
	}
}
ll f[N];
void dfs2(int x,int fa){
	for(int y : G[x]){
		if(y == fa) continue;
		f[y] = f[x]+siz[y]*(siz[x]-siz[y]);
		dfs2(y,x);
	}
}
int main(){
	n = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v); G[v].push_back(u);
	}
	f[1] = n*(n-1)/2;
	dfs1(1,0); dfs2(1,0);
	for(int i=1;i<=n;i++) if(f[i] > f[pos]) pos = i;
	f[pos] = n*(n-1)/2;
	dfs1(pos,0); dfs2(pos,0);
	for(int i=1;i<=n;i++) if(f[i] > f[pos]) pos = i;
	cout << f[pos];
	return 0;
}
