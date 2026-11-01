#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
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
int n,m;
vector<int> G[N];
int p[N],cnt;
void dfs(int x,int ft){
    p[x] = ++cnt;
    for(int y : G[x]){
        if(y == ft) continue;
        dfs(y,x);
    }
    ++cnt;
}
void solvecat(){
    n = read(); m = read();
    cnt = 0;
    for(int i=1;i<=n;i++) G[i].clear(),p[i] = 0;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!p[i]) dfs(i,0);
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << "\n";
}
int b[N],stk[N],top;
void solvedog(){
    n = read();
    for(int i=1;i<=n;i++) b[i] = read();
    for(int i=1;i<=n;i++) p[i] = i;
    sort(p+1,p+1+n,[](int x,int y){return b[x] < b[y];});
    top = 0;
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        int x = p[i];
        for(int j=1;j<=b[p[i]]-b[p[i-1]]-1;j++) top--;
        if(top) ans.emplace_back(x,stk[top]);
        stk[++top] = x;
    }
    cout << ans.size() << "\n";
    for(auto [x,y] : ans) cout << x << " " << y << "\n";
}
int main(){
    string type; cin >> type;
    int T = read();
    while(T--) type == "cat" ? solvecat() : solvedog(); 
    return 0;
}
