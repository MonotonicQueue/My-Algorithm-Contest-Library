#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 55;
int n,m;
vector<int> G[N];
inline void clear(){
	for(int i=1;i<=n;i++) G[i].clear();

}
int siz[N],mxpart[N],mn;
void dfs1(int x,int fa){
	int mx = 0;
	siz[x] = 1;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs1(y,x);
		mx = max(mx,siz[y]);
		siz[x] += siz[y];
	}
	mx = max(mx,n-siz[x]);
	mxpart[x] = mx;
	mn = min(mn,mx);
}
string f[N],g[N],hsh[N];
void dfs2(int x,int fa){
	f[x] = "(";
	for(int y : G[x]){
		if(y == fa) continue;
		dfs2(y,x);
	}
	int cnt = 0;
	for(int y : G[x]){
		if(y == fa) continue;
		g[++cnt] = f[y];
	}
	sort(g+1,g+1+cnt);
	for(int i=1;i<=cnt;i++) f[x] += g[i];
	f[x] += ")";
}
inline void work(int id){
	for(int i=1;i<=id;i++)
		if(hsh[i] == hsh[id]){
			printf("%d\n",i);
			return ;
		}
}
int main(){
	m = read();
	for(int id=1;id<=m;id++){
		n = read(); clear();
		for(int i=1;i<=n;i++){
			int p = read();
			if(p) G[i].push_back(p),G[p].push_back(i);
		}
		mn = n; hsh[id] = "9";
		dfs1(1,0);
		for(int i=1;i<=n;i++)
			if(mn == mxpart[i]){
				dfs2(i,0);
				hsh[id] = min(hsh[id],f[i]);
			}
		work(id);
	}
	return 0;
}