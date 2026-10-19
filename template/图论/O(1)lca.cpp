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
const int N = 5e5+10;
int n,m,S;
vector<int> G[N];
int dfn[N],cnt;
int st[N][20];
inline int getmn(int x,int y){
	return dfn[x] < dfn[y] ? x : y;
}
void dfs(int x,int fa){
    st[dfn[x] = ++cnt][0] = fa;
    for(int y : G[x]){
        if(y == fa) continue;
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
int main(){
    n = read(); m = read(); S = read();
    for(int i=1;i<n;i++){
		int u = read(),v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
    dfs(S,0); st_init();
    while(m--){
        int u = read(),v = read();
        cout << lca(u,v) << "\n";
    }
    return 0;
}