#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
int n,Q;
vector<int> G[N],opt[N];
int dfn[N],ct,dep[N],tag[N],cnt[N];
int st[N][20];
inline int getmn(int x,int y){
	return dfn[x] < dfn[y] ? x : y;
}
void dfs(int x,int fth){
	dep[x] = dep[fth]+1;
    st[dfn[x] = ++ct][0] = fth;
    for(int y : G[x]){
        if(y == fth) continue;
        dfs(y,x);
    }   
}
int Lg[N];
inline void st_init(){
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = getmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++) Lg[i] = Lg[i>>1]+1;
}
int lca(int x,int y){
	if(x == y) return x;
	x = dfn[x]; y = dfn[y];
	if(x > y) swap(x,y);
	x++; int lg = Lg[y-x+1];
	return getmn(st[x][lg],st[y-(1<<lg)+1][lg]);
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int ft[N],ans[N],col[N],now,bel[N],sz[N];
void clear(){
	for(int i=1;i<=n;i++) G[i].clear(),col[i] = bel[i] = 0;
	for(int i=1;i<=Q;i++) opt[i].clear();
	ct = 0;
}

struct rec{
	int l,r,len;
}res[N];
int get(int x){
	return ft[x] == x ? x : ft[x] = get(ft[x]);
}
void merge(int u,int v,int op){
	int x=get(u),y=get(v);
	if(x==y)return;
	if(op)swap(x,y);
	ft[x]=y;
}
void merge(int u,int v){
	int x=get(u),y=get(v);
	int l,r,len=0;
	if(x==y)return;
	int l1=res[x].l,r1=res[x].r;
	int l2=res[y].l,r2=res[y].r;
	int d1=res[x].len,d2=res[y].len;
	int d3=dis(l1,l2),d4=dis(r1,r2);
	int d5=dis(l1,r2),d6=dis(l2,r1);
	if(len<=d1)len=d1,l=l1,r=r1;
	if(len<=d2)len=d2,l=l2,r=r2;
	if(len<=d3)len=d3,l=l1,r=l2;
	if(len<=d4)len=d4,l=r1,r=r2;
	if(len<=d5)len=d5,l=l1,r=r2;
	if(len<=d6)len=d6,l=l2,r=r1;
	merge(x,y,1);
	now = max(len,now);
	res[get(x)]=(rec){l,r,len};
}
pii q[N];
void solve(){
	n = read(); Q = read();
	clear();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i=1;i<=n;i++){
		ft[i] = i,sz[i] = 1;
		tag[i] = Q+1;
		col[i] = 0;
	}
	for(int i=0;i<=Q+1;i++)
		cnt[i] = ans[i] = 0,opt[i].clear();
	dfs(1,0); st_init();
	for(int i=1;i<=Q;i++){
		int x,y,z;
		x = read(); y = read();
		z = lca(x,y);
		while(dep[x] >= dep[z]){
			if(x == get(x)) merge(x,st[dfn[x]][0],0);
			tag[x] = min(tag[x],i);
			x = get(x);
		}
		while(dep[y] >= dep[z]){
			if(y == get(y)) merge(y,st[dfn[y]][0],0);
			tag[y] = min(tag[y],i);
			y = get(y);
		}
	}
	for(int i=1;i<=n;i++)
		opt[tag[i]].push_back(i);
	for(int i=1;i<=n;i++){
		ft[i] = i,sz[i] = 1;
		res[i] = (rec){i,i,0};
	}
	for(int i=1;i<=Q+1;i++){
		ans[i] = ans[i-1];
		for(int x : opt[i]){
			col[x] = 1;
			for(int y : G[x]){
				if(col[x] != col[y])continue;
				merge(x,y);
			}
			ans[i] = max(ans[i],res[get(x)].len);
		}
	}
	for(int i=1;i<=n;i++){
		ft[i] = i,sz[i] = 1;
		res[i] = (rec){i,i,0};
	}
	for(int i=Q+1;i>=1;i--){
		cnt[i-1] = cnt[i];
		for(int x : opt[i]){
			col[x] = 0;
			for(int y : G[x]){
				if(col[x]!=col[y])continue;
				merge(x,y);
			}
			cnt[i-1] = max(cnt[i-1],res[get(x)].len);
		}
	}
	for(int i=1;i<=Q;i++)
		cout << max(ans[i],cnt[i])+1 << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}