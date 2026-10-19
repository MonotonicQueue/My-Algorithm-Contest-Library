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
const int N = 1e5+10;
int n,m,dfn[N],low[N],tot;
ll k;
vector<int> G[N],v[N];
int stk[N],top,cnt,col[N];
bool ins[N];
void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    ins[x] = true;
    for(int y : G[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x],low[y]);
        }else if(ins[y]) low[x] = min(low[x],dfn[y]);
    }
    if(low[x] == dfn[x]){
        int z;
        cnt++;
        do{
            z = stk[top--];
            col[z] = cnt;
            v[cnt].push_back(z);
            ins[z] = false;
        }while(z != x);

    }
}
int dep[N],d;
void dfs(int x,int fa,int c){
    dep[x] = dep[fa]+1;
    for(int y : G[x]){
        if(col[y] != c) continue;
        if(dep[y]) d = __gcd(d,abs(dep[y]-dep[x]-1));
        else dfs(y,x,c);
    }
}
ll t[N],ans;
int main(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=cnt;i++){
        int mx = 0;
        d = 0;
        dfs(v[i][0],0,i);
        for(int y : v[i]) mx = max(mx,dep[y]),t[dep[y]]++;
        if(d != 0){
            if(k % d == 0){
                for(int j=1;j<=mx;j++){
                    ans += t[j]*(t[j]+1)/2;
                    if(j > d){
                        ans += t[j]*t[j-d];
                        t[j] += t[j-d];
                    }
                }
            }else if(d % 2 == 0 && k % d == d/2){
                for(int j=d/2+1;j<=mx;j++){
                    ans += t[j]*t[j-d/2];
                    if(j > d)  t[j] += t[j-d];
                }
            }
        }
        for(int j=1;j<=mx;j++) t[j] = 0;
    }
    cout << ans;
    return 0;
}
