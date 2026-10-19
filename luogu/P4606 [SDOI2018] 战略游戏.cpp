#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
int dfn[N],low[N],num;
int stk[N],top;
void tarjan(int x){
    low[x] = dfn[x] = ++num;
    stk[++top] = x;
    for(int y : G[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(low[y] == dfn[x]){
                cnt++;
                int z = 0;
                do{
                    z = stk[top--];
                    E[cnt].push_back(z);
                    E[z].push_back(cnt);
                }while(z != y);
                E[cnt].push_back(x);
                E[x].push_back(cnt);
            }
        }else low[x] = min(low[x],dfn[y]);
    }
}
int dfsn[N],tot;
int st[N][20];
void st_pre(){
    auto getmn = [&](int x,int y)->int{
        return dfsn[x] < dfsn[y] ? x : y;
    };
    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=cnt;i++)
            st[i][j] = getmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int lca(int x,int y){
    auto getmn = [&](int x,int y)->int{
        return dfsn[x] < dfsn[y] ? x : y;
    };
    if(x == y) return x;
    x = dfsn[x]; y = dfsn[y];
    if(x > y) swap(x,y);
    x++; int t = log(y-x+1)/log(2);
    return getmn(st[x][t],st[y-(1<<t)+1][t]);
}
int dep[N];
void dfs(int x,int fa){
    // cout << x << " " << fa << "\n";
    dep[x] = dep[fa]+(x <= n);
    st[dfsn[x] = ++tot][0] = fa;
    for(int y : E[x]){
        if(y == fa) continue;
        dfs(y,x);
    }
}
int q[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        auto clear = [&](){
            for(int i=1;i<=n;i++) G[i].clear();
            for(int i=1;i<=2*n;i++) E[i].clear();
            top = num = tot = 0; cnt = n;
            for(int i=1;i<=n;i++) low[i] = dfn[i] = 0;
        };
        clear();
        for(int i=1;i<=m;i++){
            int u = read(),v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        tarjan(1);
        dfs(1,0);
        st_pre();
        // for(int i=1;i<=cnt;i++) cout << dfsn[i] << " ";
        // cout << "\n";
        // cout << lca(4,5) << "\n";
        int Q = read();
        while(Q--){
            int s = read();
            auto cmp = [&](int x,int y){
                return dfsn[x] < dfsn[y];
            };
            for(int i=1;i<=s;i++) q[i] = read();
            sort(q+1,q+1+s,cmp);
            ll ans = 0;
            q[0] = q[s];
            for(int i=1;i<=s;i++)
                ans += dep[q[i-1]]+dep[q[i]]-2*dep[lca(q[i-1],q[i])];
            ans = ans/2+(lca(q[1],q[s]) <= n)-s;
            cout << ans << "\n";
        }
    }
    return 0; 
}
