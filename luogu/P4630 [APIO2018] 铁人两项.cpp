#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
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
const int N = 2e5+10;
int n,m,cnt;
vector<int> G[N],E[N];
int dfn[N],low[N],tot,sum;
ll w[N];
int stk[N],top;
void tarjan(int x){
    sum++;
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    for(int y : G[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(dfn[x] <= low[y]){
                int z;
                cnt++;
                do{
                    w[cnt]++;
                    z = stk[top--];
                    E[cnt].push_back(z);
                    E[z].push_back(cnt);
                }while(z != y);
                w[cnt]++;
                E[cnt].push_back(x);
                E[x].push_back(cnt);
            }
        }else low[x] = min(low[x],dfn[y]);
    }
}
ll ans;
ll siz[N];
void dfs(int x,int fa){
    // cout << x << " " << fa << " " << w[x] << "\n";
    siz[x] = x <= n;
    for(int y : E[x]){
        if(y == fa) continue;
        dfs(y,x);
        ans += 2*w[x]*siz[x]*siz[y];
        siz[x] += siz[y];
    }
    ans += 2*w[x]*siz[x]*(sum-siz[x]);
}
signed main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt = n;
    for(int i=1;i<=n;i++) w[i] = -1;
    for(int i=1;i<=n;i++)
        if(!dfn[i]){
            sum = top = 0;
            tarjan(i);
            dfs(i,0);
        }
    cout << ans;
    return 0;
}
