#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e6+10;
int n,Q,pos[N];
char ch[N];
int son[N][26],fail[N],tot;
void insert(int id){
	int len = strlen(ch+1),p = 0;
	for(int i=1;i<=len;i++){
		int c = ch[i]-'a';
		if(!son[p][c]) son[p][c] = ++tot;
		p = son[p][c];
	}
	pos[id] = p;
}
vector<int> G[N];

void getFail(){
	queue<int> q;
	for(int i=0;i<26;i++) if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<26;i++){
			if(son[x][i]){
				fail[son[x][i]] = son[fail[x]][i];
				q.push(son[x][i]);
			}else son[x][i] = son[fail[x]][i];
		}
	}
	for(int i=1;i<=tot;i++) G[fail[i]].push_back(i);
}
int siz[N],dfn[N],cnt;
int fa[N][24],dep[N];
void dfs(int x){
	for(int i=1;i<=22;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	dfn[x] = ++cnt;
	siz[x] = 1;
	for(int y : G[x]){
		fa[y][0] = x; dep[y] = dep[x]+1;
		dfs(y);
		siz[x] += siz[y];
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i=22;~i;i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i=22;~i;i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int t[N];
inline void add(int x,int y){
	while(x <= cnt){
		t[x] += y;
		x += x&(-x);
	}
}
inline int ask(int x){
	int res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
inline int query(int x){
	return ask(dfn[x]+siz[x]-1)-ask(dfn[x]-1);
}
bool cmp(int x,int y){
	return dfn[x] < dfn[y];
}
int a[N],m;
void work(){
	m = 0;
	int len = strlen(ch+1),p = 0;
	for(int i=1;i<=len;i++){
		p = son[p][ch[i]-'a'];
		a[++m] = p;
	}
	sort(a+1,a+1+m,cmp);
	m = unique(a+1,a+1+m)-a-1;
	// for(int i=1;i<=m;i++) cout << a[i] << " ";
	// cout << "\n";
	for(int i=1;i<=m;i++) add(dfn[a[i]],1);
	for(int i=1;i<m;i++){
		add(dfn[lca(a[i],a[i+1])],-1);
		// cout << lca(a[i],a[i+1]) << " ";
	}
	// cout << "\n";
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		cin >> ch+1;
		insert(i);
	}
	getFail();
	dfs(0);
	Q = read();
	while(Q--){
		int op = read();
		if(op == 1){
			cin >> ch+1;
			work();
		}else{
			int x = read();
			cout << query(pos[x]) << "\n";
		}
	}
	return 0;
}