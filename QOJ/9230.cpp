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
int n,m;
vector<int> G[N];
struct node{
	int dep;
	ll x,y;
	node change(){
		return node{dep+1,2*x+1,y};
	}
	node operator+(const node &X){
		return node{max(dep,X.dep)+1,x*2+X.x*2+1,y+X.y+min(x,X.x)};
	}
}f[N];
ll ans = 6e18;
void get(node x){
	if(x.dep >= 32) return ;
	ans = min(ans,x.x+x.y);
}
void dfs0(int x,int fa){
	for(int i=0;i<G[x].size();i++){
		if(G[x][i] == fa){
			swap(G[x][i],G[x].back());
			G[x].pop_back();
			break;
		}
	}
	if(G[x].empty()){
		f[x] = {0,1,0};
	}else if(G[x].size() == 1){
		int y = G[x][0];
		dfs0(y,x);
		f[x] = f[y].change();
	}else{
		int u = G[x][0],v = G[x][1];
		dfs0(u,x); dfs0(v,x);
		f[x] = f[u]+f[v];
	}
}
void dfs1(int x,node fr){
	// cout << x << "\n";
	if(G[x].empty()){
		get(fr);
	}else if(G[x].size() == 1){
		dfs1(G[x][0],fr.change());
		get(fr+f[G[x][0]]);
	}else{
		dfs1(G[x][0],fr+f[G[x][1]]);
		dfs1(G[x][1],fr+f[G[x][0]]);
	}
}
signed main(){
    n = read(); m = read();
	if(m > n-1){
		puts("NIE");
		return 0;
	}
	if(n == 1){
		cout << 0 << "\n";
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(G[i].size() > 3){
			puts("NIE");
			return 0;
		}
	}
	int rt = 0;
	for(int i=1;i<=n;i++){
		if(G[i].size() == 1){
			dfs0(i,0);
			rt = i;
			break;
		}
	}
	get(f[G[rt][0]]);
	// cout << rt << " " << G[rt][0] << "\n";
	dfs1(G[rt][0],node{0,1,0});
	if(ans >= 6e18) puts("NIE");
	else cout << ans;
    return 0;
}