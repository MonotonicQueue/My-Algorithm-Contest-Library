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
const int N = 5e5+10;
int n,m;
vector<pii> V[N],G[N];
int a[N];
struct node{
	int l,x,r,y;
}op[N];
int dfn[N],low[N],tot;
bool ins[N];
int stk[N],top;
int bel[N],cnt,in[N];
vector<int> c[N];
vector<int> ans;
void tarjan(int x){
	dfn[x] = low[x] = ++tot;
	ins[x] = true;
	stk[++top] = x;
	for(auto [y,id] : G[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}else if(ins[y]) low[x] = min(low[x],dfn[y]);
	}
	if(low[x] == dfn[x]){
		int z;
		++cnt;
		do{
			z = stk[top--];
			ins[z] = false;
			bel[z] = cnt;
			c[cnt].push_back(z);
		}while(x != z);
	}
}
bool vis[N];
void dfsin(int x){
	if(vis[x]) return ;
	vis[x] = true;
	if(!a[x]) a[x] = 2;
	for(auto [y,id] : G[x]){
		if(bel[x] == bel[y]) ans.push_back(id),dfsin(y);
	}
}
void dfs0(int id){
	int st = c[id][0];
	if(vis[st]) return ;
	for(int x : c[id]){
		if(a[x] == 2) st = x;
	}
	if(!a[st]) a[st] = 1;
	dfsin(st);
	for(int x : c[id]){
		for(auto [y,_] : G[x]){
			if(bel[x] == bel[y]) continue;
			ans.push_back(_);
			if(!a[y]) a[y] = 2;
			dfs0(bel[y]);
		}
	}
}

void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		a[i] = dfn[i] = low[i] = 0;
		G[i].clear();
		V[i].clear();
		c[i].clear();
		bel[i] = in[i] = vis[i] = 0;
	}
	tot = cnt = top = 0;
	ans.clear();
	for(int i=1;i<=m;i++){
		int l = read(),x = read(),r = read(),y = read();
		op[i] = node{l,x,r,y};
		if(x == y && x == 2) a[l] = a[r] = 2,ans.push_back(i);
		if(x == 1 && y == 2) G[l].push_back(mk(r,i));
		if(x == 2 && y == 1) G[r].push_back(mk(l,i));
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i] && !G[i].empty()) tarjan(i);
	// cerr << cnt << "\n";
	for(int i=1;i<=n;i++)
		for(auto [y,id] : G[i])
			if(bel[i] != bel[y] && bel[i] && bel[y]) in[bel[y]]++;
	// for(int i=1;i<=cnt;i++){
	// 	for(int x : c[i]) cerr << x << " ";
	// 	cerr << "\n";
	// }
	for(int i=1;i<=cnt;i++){
		if(!in[i]){
			// cout << i << "\n";
			dfs0(i);
		}
	}
	for(int i=1;i<=m;i++)
		if(op[i].x == op[i].y && op[i].x == 1){
			ans.push_back(i);
			if(!a[op[i].l]) a[op[i].l] = 1;
			if(!a[op[i].r]) a[op[i].r] = 1;
		}
	int sum = 0;
	for(int i=1;i<=n;i++){
		sum += a[i];
	}
	cout << sum << "\n";
	reverse(ans.begin(),ans.end());
	for(int x : ans) cout << x << " ";
	cout << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	
	return 0;
}