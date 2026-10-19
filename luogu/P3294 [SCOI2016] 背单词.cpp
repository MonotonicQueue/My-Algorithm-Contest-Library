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
const int N = 1e5+10;
int n,tot;
char ch[N];
int son[N*20][26];
int ed[N*20];
inline void insert(int id){
	int p = 0,len = strlen(ch+1);
	for(int i=1;i<=len;i++){
		int c = ch[i]-'a';
		if(!son[p][c]) son[p][c] = ++tot;
		p = son[p][c];
	}
	ed[p] = id;
}
vector<int> G[N];
void dfs1(int x,int lst){
	if(ed[x]){
		G[lst].push_back(ed[x]);
		lst = ed[x];
	}
	for(int i=0;i<26;i++) if(son[x][i]) dfs1(son[x][i],lst);
}
int siz[N];
bool cmp(int x,int y){
	return siz[x] < siz[y];
}
void dfs2(int x){
	siz[x] = 1;
	for(int y : G[x]){
		dfs2(y);
		siz[x] += siz[y];
	}
	sort(G[x].begin(),G[x].end(),cmp);
}
int dfn[N],cnt=-1;
ll ans;
void dfs3(int x){
	// cout << x << "\n";
	dfn[x] = ++cnt;
	for(int y : G[x]){
		dfs3(y);
		ans += dfn[y]-dfn[x];
	}
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		cin >> ch+1;
		int len = strlen(ch+1);
		reverse(ch+1,ch+1+len);
		insert(i);
	}
	dfs1(0,0);
	dfs2(0); dfs3(0);
	cout << ans;
	return 0;
}