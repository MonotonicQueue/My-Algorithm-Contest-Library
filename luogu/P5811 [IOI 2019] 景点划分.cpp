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
const int N = 1e5+10;
int n,m,A[4],P[4],a,b;
int ans[N],dep[N],siz[N],root,fr[N];
vector<int> G[N];
void getrt(int x,int ft){
	siz[x] = 1;
	fr[x] = ft;
	dep[x] = dep[ft]+1;
	int mx = 0;
	for(int y : G[x]){
		if(dep[y]) continue;
		getrt(y,x);
		siz[x] += siz[y];
		mx = max(mx,siz[y]);
	}
	mx = max(mx,n-siz[x]);
	if(mx*2 <= n) root = x;
}
int fa[N];
int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void dfs0(int x,int col){
	fa[x] = col;
	for(int y : G[x]){
		if(fr[y] != x) continue;
		dfs0(y,col);
	}
}
int cnt;
void dfs1(int x,int col,int tar,int pos){
	if(cnt == tar) return ;
	ans[x] = col;
	cnt++;
	for(int y : G[x]){
		if(fa[y] != pos || ans[y]) continue;
		dfs1(y,col,tar,pos);
	}
}
int sum;
bool vis[N],vvv[N];
void dfs2(int x,int tar,int pos){
	if(sum >= tar) return ;
	if(!vis[get(x)]){
		vis[get(x)] = 1;
		sum += siz[get(x)];
		fa[get(x)] = pos;
	}
	vvv[x] = true;
	for(int y : G[x]){
		if(y != root && !vvv[y]) dfs2(y,tar,pos);
	}
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=3;i++){
		A[i] = read();
		P[i] = i;
	}
	sort(P+1,P+4,[](int x,int y){return A[x] < A[y];});
	a = A[P[1]],b = A[P[2]];
	for(int i=1;i<=m;i++){
		int u = read()+1,v = read()+1;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	getrt(1,0);
	int mx = 0;
	for(int x : G[root])
		if(dep[x] > dep[root]) mx = max(mx,siz[x]);
		else mx = max(mx,n-siz[root]);
	
	for(int y : G[root]){
		if(fr[y] == root) dfs0(y,y);
	}
	for(int i=1;i<=n;i++)
		if(!fa[i] && i != root) fa[i] = fr[root];
	
	if(mx >= a){
		int pos = 0;
		for(int x : G[root])
			if(dep[x] > dep[root] && mx == siz[x]) pos = x;
		if(!pos) pos = fr[root];
		for(int i=1;i<=n;i++)
			if(fa[i] != pos) fa[i] = 0;
		cnt = 0;
		dfs1(pos,1,a,pos);
		cnt = 0;
		dfs1(root,2,b,0);
		for(int i=1;i<=n;i++)
			if(!ans[i]) ans[i] = 3;
	}else{
		if(fr[root]) siz[fr[root]] = n-siz[root];
		int pos = 0;
		for(int y : G[root]){
			if(fr[y] == root){
				pos = y;
				dfs2(pos,a,pos);
				break;
			}
		}
		if(sum >= a){
			for(int i=1;i<=n;i++)
				if(get(i) != pos) fa[i] = 0;
			cnt = 0;
			dfs1(pos,1,a,pos);
			cnt = 0;
			dfs1(root,2,b,0);
			for(int i=1;i<=n;i++)
				if(!ans[i]) ans[i] = 3;
		}else{
			for(int i=1;i<=n;i++) ans[i] = 0;
		}
	}
	for(int i=1;i<=n;i++) cout << P[ans[i]] << " ";
    return 0;
}