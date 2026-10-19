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
const int B = 500;
int n,m,a[N],_a[N];
vector<int> G[N];
int fa[N],siz[N],son[N];
void dfs1(int x){
	siz[x] = 1;
	for(int y : G[x]){
		dfs1(y);
		siz[x] += siz[y];
		if(siz[y] >= siz[son[x]])
			son[x] = y;
	}
}
int top[N],dfn[N],raw[N],tot;
void dfs2(int x,int topx){
	dfn[x] = ++tot; raw[tot] = x;
	top[x] = topx;
	if(!son[x]) return ;
	dfs2(son[x],topx);
	for(int y : G[x])
		if(y != son[x]) dfs2(y,y);
}
int pos[N],L[N],R[N],ans;
int sum[N/B+10][N<<1],col[N],add[N];
void change(int l,int r,int v){
	int p = pos[l];
	for(int i=l;i<=r;i++){
		if(!col[i]){
			sum[p][a[i]]--;
			if(a[i] >= 1+n-add[p]) ans--;
		}
		a[i] += v;
		if(!col[i]){
			sum[p][a[i]]++;
			if(a[i] >= 1+n-add[p]) ans++;
		}
	}
}
void update(int l,int r,int v){
	if(pos[l] == pos[r]){
		change(l,r,v);
		return ;
	}
	int pl = pos[l],pr = pos[r];
	change(l,R[pl],v); change(L[pr],r,v);
	for(int i=pl+1;i<=pr-1;i++){
		if(v == 1) add[i] ++,ans += sum[i][n+1-add[i]];
		else ans -= sum[i][n+1-add[i]],add[i] --;
	}
}
int main(){
	n = read(); m = read();
	for(int i=2;i<=n;i++){
		fa[i] = read();
		G[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) _a[i] = read();
	dfs1(1); dfs2(1,1);
	for(int i=1;i<=n;i++) a[i] = n-_a[raw[i]];
	for(int i=1;i<=n;i++) pos[i] = (i-1)/B+1;
	for(int i=1;i<=pos[n];i++) L[i] = (i-1)*B+1,R[i] = i*B;
	R[pos[n]] = n;
	for(int i=1;i<=n;i++) sum[pos[i]][a[i]]++;
	while(m--){
		int x = read();
		int y = x > 0 ? 1 : -1; x = abs(x);
		col[dfn[x]] ^= 1;
		sum[pos[dfn[x]]][a[dfn[x]]] -= y;
		if(a[dfn[x]] >= 1+n-add[pos[dfn[x]]]) ans -= y;
		while(x){
			update(dfn[top[x]],dfn[x],y);
			x = fa[top[x]];
		}
		cout << ans << " ";
	}
	return 0;
}
