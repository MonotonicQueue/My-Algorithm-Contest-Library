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
const int N = 5e4+10;
const int M = 1e5+10;
int n,m;
vector<int> a[N],ed[M];
int fail[M],tot;
map<int,int> son[M];
inline void insert(int id){
	int len = read(),p = 0;
	for(int i=1;i<=len;i++){
		int c = read();
		if(!son[p][c]) son[p][c] = ++tot;
		p = son[p][c];
	}
	ed[p].emplace_back(id);
}
inline void getFail(){
	queue<int> q;
	for(auto it=son[0].begin();it!=son[0].end();it++) q.push(it->se);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(auto it=son[x].begin();it!=son[x].end();it++){
			int i = it->fi,k = fail[x];
			while(k && !son[k][i]) k = fail[k];
			fail[it->se] = son[k][i];
			q.push(it->se);
		}
	} 
}
bool vis[M];
vector<int> V;
int cnt[M],ans1[M],ans2[M];
inline void calc(int x,int y){
	for(int i=y;i;i=fail[i]){
		if(vis[i]) continue;
		vis[i] = true; V.emplace_back(i);
		cnt[i]++; ans2[x] += ed[i].size();
	}
}
inline void solve(int id){
	int p = 0;
	for(int i : a[id]){
		while(p && !son[p][i]) p = fail[p];
		p = son[p][i];
		calc(id,p);
	}
	for(int i : V) vis[i] = false;
	V.clear();
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		int l = read();
		while(l--){int x = read(); a[i].emplace_back(x);}
		a[i].emplace_back(10001);
		l = read();
		while(l--){int x = read(); a[i].emplace_back(x);}
	}
	for(int i=1;i<=m;i++) insert(i);
	getFail();
	for(int i=1;i<=n;i++) solve(i);
	for(int i=1;i<=tot;i++) for(int j : ed[i]) ans1[j] += cnt[i];
	for(int i=1;i<=m;i++) cout << ans1[i] << "\n";
	for(int i=1;i<=n;i++) cout << ans2[i] << " ";
	return 0;
}