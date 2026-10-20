#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
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
int n,Q;
vector<int> G[N];
int st[N][20],dfn[N],cnt,Lg[N],dep[N];
int ans[N];
int getmn(int x,int y){
	return dfn[x] < dfn[y] ? x : y;
}
void st_init(){
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = getmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++) Lg[i] = Lg[i>>1]+1;
}
int lca(int x,int y){
	if(x == y) return x;
	x = dfn[x]; y = dfn[y];
	if(x > y) swap(x,y);
	x++; int t = Lg[y-x+1];
	return getmn(st[x][t],st[y-(1<<t)+1][t]);
}
void dfs(int x,int fa){
	dep[x] = dep[fa]+1;
	st[dfn[x] = ++cnt][0] = fa;
	for(int y : G[x]){
		if(y == fa) continue;
		dfs(y,x);
	}
}

struct BIT{
	int t[N];
	void clear(){
		memset(t,0,sizeof(t));
	}
	void add(int x,int y){
		while(x <= n){
			t[x] = max(t[x],y);
			x += x&(-x);
		}
	}
	int ask(int x){
		int res = 0;
		while(x){
			res = max(res,t[x]);
			x -= x&(-x);
		}
		return res;
	}
}T;
int L[N],R[N],stk[N],top,a[N];
struct node{int l,r,d,id;}c[N],q[N];
bool cmp1(node x,node y){return x.r > y.r;}
bool cmp2(node x,node y){return x.d > y.d;}
int t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
void update(int rt,int l,int r,int pos,int d){
	if(l == r){
		t[rt] = d;
		return ;
	}
	int mid = (l+r) >> 1;
	if(pos <= mid) update(ls,l,mid,pos,d);
	else 		   update(rs,mid+1,r,pos,d);
	t[rt] = max(t[ls],t[rs]);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr) return t[rt];
	int mid = (l+r) >> 1,res = 0;
	if(ql <= mid) res = max(res,query(ls,l,mid,ql,qr));
	if(qr >  mid) res = max(res,query(rs,mid+1,r,ql,qr));
	return res;
}
int main(){
	// freopen("query.in","r",stdin);
	// freopen("query.out","w",stdout);
	n = read();
	for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	st_init();
	for(int i=1;i<n;i++) a[i] = dep[lca(i,i+1)];
	for(int i=1;i<n;i++){
		while(top && a[stk[top]] >= a[i]){
			R[stk[top]] = i;
			top--;
		}
		L[i] = stk[top]+1;
		stk[++top] = i;
	}
	while(top) R[stk[top--]] = n;
	for(int i=1;i<n;i++) c[i] = node{L[i],R[i],R[i]-L[i]+1,a[i]}; 
	// for(int i=1;i<n;i++){
	// 	cout << c[i].l << " " << c[i].r << " " << c[i].id << "\n";
	// }
	for(int i=1;i<=n;i++) update(1,1,n,i,dep[i]);
	Q = read();
	for(int i=1;i<=Q;i++){
		int l = read(),r = read(),k = read();
		if(k == 1) ans[i] = query(1,1,n,l,r);
		q[i] = node{l,r,k,i};
	}
	sort(c+1,c+n,cmp1); sort(q+1,q+1+Q,cmp1);
	for(int i=1,j=1;i<=Q;i++){
		while(j < n && c[j].r >= q[i].r){
			T.add(c[j].l,c[j].id);
			j++;
		}
		ans[q[i].id] = max(ans[q[i].id],T.ask(q[i].r-q[i].d+1));
	}
	T.clear();
	sort(c+1,c+n,cmp2); sort(q+1,q+1+Q,cmp2);
	memset(t,0,sizeof(t));
	for(int i=1,j=1;i<=Q;i++){
		while(j < n && c[j].d >= q[i].d){
			update(1,1,n,c[j].r,c[j].id);
			j++;
		}
		ans[q[i].id] = max(ans[q[i].id],query(1,1,n,q[i].l+q[i].d-1,q[i].r));
	}
	for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
	return 0;
}

