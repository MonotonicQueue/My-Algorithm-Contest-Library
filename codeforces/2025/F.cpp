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
const int N = 3e5+10;
int n,q;
int a[N],b[N];
vector<pii> G[N];
int dep[N],f[N],g[N];
bool vis[N];
void dfs(int x){
    vis[x] = true;
    for(auto it : G[x]){
        int y = it.fi;
        if(!vis[y]) dep[y] = dep[x]+1,dfs(y);
        if(dep[y] > dep[x]){
            if(f[y]) f[y] = 0,g[it.se] = y;
            else f[x] ^= 1,g[it.se] = x;
        }
    }
}
int cnt[N];
int main(){
	n = read(); q = read();
	for(int i=1;i<=q;i++){
		a[i] = read();
		b[i] = read();
        G[a[i]].push_back(mk(b[i],i));
        G[b[i]].push_back(mk(a[i],i));
	}
    dep[1] = 1;
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    for(int i=1;i<=q;i++){
        assert(g[i] == a[i] || g[i] == b[i]);
        if(g[i] == a[i]) cout << "x";
        else cout << "y";
        if(cnt[g[i]]) cout << "-\n";
        else cout << "+\n";
        cnt[g[i]] ^= 1;
    }
    return 0;
}