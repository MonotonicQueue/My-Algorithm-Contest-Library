#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e4+10;
const int M = 5e4+10;
int n,m,fa[N];
vector<int> G[N];
int get(int x){
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}
struct Edge{int u,v,w;}e[M];
int cnt,val[N];
int st[N][20],tot,dfn[N],Lg[N];
void dfs(int x,int ft){
    st[dfn[x] = ++tot][0] = ft;
    for(int y : G[x]) dfs(y,x);
}
int getmn(int x,int y){
    return dfn[x] < dfn[y] ? x : y;
}
inline void st_init(){
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=cnt;i++)
            st[i][j] = getmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    for(int i=2;i<=cnt;i++) Lg[i] = Lg[i>>1]+1;
}
int ask(int u,int v){
    if(u == v) return u;
    u = dfn[u]; v = dfn[v];
    if(u > v) swap(u,v);
    u++; int t = Lg[v-u+1];
    return getmn(st[u][t],st[v-(1<<t)+1][t]);
}
int main(){
    n = read(); m = read();
    cnt = n;
    for(int i=1;i<=2*n;i++) fa[i] = i;
    for(int i=1;i<=m;i++){
        e[i].u = read(); e[i].v = read();
        e[i].w = read();
    }
    sort(e+1,e+1+m,[](Edge x,Edge y){return x.w > y.w;});
    for(int i=1;i<=m;i++){
        int x = e[i].u,y = e[i].v;
        x = get(x); y = get(y);
        if(x == y) continue;
        val[++cnt] = e[i].w;
        fa[x] = fa[y] = cnt;
        G[cnt].push_back(x); G[cnt].push_back(y);
    }
    for(int i=1;i<=cnt;i++) if(fa[i] == i) dfs(i,0);
    st_init();
    int Q = read();
    while(Q--){
        int u = read(),v = read();
        if(get(u) != get(v)) puts("-1");
        else printf("%d\n",val[ask(u,v)]);
    }
	return 0;
}