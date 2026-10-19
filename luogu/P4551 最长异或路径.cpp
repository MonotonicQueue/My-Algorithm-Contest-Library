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
int n;
int head[N],to[N<<1],nxt[N<<1],edge[N<<1],tot=1;
inline void add_edge(int u,int v,int w){
    to[++tot] = v; nxt[tot] = head[u];
    head[u] = tot; edge[tot] = w;
}
int f[N];
void dfs(int x,int fa){
    for(int i=head[x];i;i=nxt[i]){
        int y = to[i];
        if(y == fa) continue;
        f[y] = f[x]^edge[i];
        dfs(y,x);
    }
}
int son[N*40][2],cnt;
void insert(int x){
    int p = 0;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(!son[p][c]) son[p][c] = ++cnt;
        p = son[p][c];
    }
}
int query(int x){
    int res = 0,p = 0;
    for(int i=30;~i;i--){
        int c = (x >> i) & 1;
        if(son[p][!c]){
            p = son[p][!c];
            res += (1<<i);
        }else p = son[p][c];
    }
    return max(res,x);
}
int main(){
	n = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read(),w = read();
        add_edge(u,v,w); add_edge(v,u,w);
    }
    dfs(1,0);
     int ans = 0;
    for(int i=1;i<=n;i++) insert(f[i]);
    for(int i=1;i<=n;i++) ans = max(ans,query(f[i]));
    cout << ans;
	return 0;
}