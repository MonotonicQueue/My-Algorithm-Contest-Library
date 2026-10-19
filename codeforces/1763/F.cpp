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
const int N = 4e5+10;
int n,m,q;
vector<int> G[N],E[N];
int dfn[N],low[N],tot,cnt;
int stk[N],top;
int val[N],col[N],fr[N],dep[N];
void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    for(int y : G[x]){
        if(!dfn[y]){
            fr[y] = x;
            dep[y] = dep[x]+1;
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(low[y] >= dfn[x]){
                ++cnt;
                E[cnt].push_back(x);
                E[x].push_back(cnt);
                int z = 0;
                do{
                    z = stk[top--];
                    col[z] = cnt;
                    E[cnt].push_back(z);
                    E[z].push_back(cnt);
                }while(z != y);
            }
        }else low[x] = min(low[x],dfn[y]);
    }
}
int st[N][20],dfsn[N],ttt;
int get(int x,int y){
    return dfsn[x] < dfsn[y] ? x : y;
}
void st_init(){
    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=cnt;i++)
            st[i][j] = get(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
void dfs0(int x,int fa){
    for(int y : G[x]){
        // if(y == fa) continue;
        if(fr[y] == x) dfs0(y,x);
        if(dep[y] >= dep[x]) val[col[y]]++;
        else val[col[x]]++;
    }
}
void dfs(int x,int fa){
    // cout << x << "\n";
    st[dfsn[x] = ++ttt][0] = fa;
    for(int y : E[x]){
        if(y == fa) continue;
        val[y] += val[x];
        dfs(y,x);
    }
}
int lca(int u,int v){
    if(u == v) return u;
    u = dfsn[u]; v = dfsn[v];
    if(u > v) swap(u,v);
    u++;
    int t = log(v-u+1)/log(2);
    return get(st[u][t],st[v-(1<<t)+1][t]);
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt = n;
    tarjan(1);
    dfs0(1,0);
    for(int i=n+1;i<=cnt;i++)
        if((val[i] /= 2) == 1) val[i] = 0;
    dfs(1,0); st_init();
    q = read();
    while(q--){
        int u = read(),v = read();
        int d = lca(u,v);
        // cout << d << "\n";
        cout << val[u]+val[v]-val[d]-val[st[dfsn[d]][0]] << "\n";
    }
    return 0;
}