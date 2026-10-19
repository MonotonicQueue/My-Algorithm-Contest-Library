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
const int B = 700;
int n,m,k,Q,a[N];
vector<int> G[N],v[N],g[N];
vector<pii> q[N];
int lst[N],ti[N],pre[N];
bool flag1[N];
int t[N],ans[N],b[N];
void add(int x,int y){
	while(x <= k){
		t[x] += y;
		x += x&(-x);
	}
}
int ask(int x){
	int res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
int main(){
	// freopen("show.in","r",stdin);
	// freopen("show.out","w",stdout);
    int C = read();
	n = read(); m = read(); k = read(); Q = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		G[v].push_back(u);
	}
	for(int i=1;i<=k;i++) a[i] = read();
	for(int i=1;i<=n;i++)
		if(G[i].size() > B)
			for(int y : G[i]) g[y].push_back(i);
	for(int y : G[1]) flag1[y] = true;
	for(int i=1;i<=k;i++){
		int p = lst[a[i]];
		for(int y : g[a[i]]) p = max(p,ti[y]);
		if(flag1[a[i]]) p = i;
		ti[a[i]] = pre[i] = lst[a[i]] = p;
		if(G[a[i]].size() <= B)
			for(int y : G[a[i]]) lst[y] = max(lst[y],p);
	}
	for(int i=k;i>=1;i--) v[pre[i]].push_back(i);
	for(int i=1;i<=Q;i++){
		int l = read(),r = read();
		q[l].push_back(mk(r,i));
	}
	for(int i=k;i;i--){
		for(int x : v[i]){
			if(b[a[x]]) add(b[a[x]],-1);
			add(x,1); b[a[x]] = x;
		}
		for(pii it : q[i]) ans[it.se] = ask(it.fi);
	}
	for(int i=1;i<=Q;i++) cout << n-1-ans[i] << "\n";
    return 0;
}
