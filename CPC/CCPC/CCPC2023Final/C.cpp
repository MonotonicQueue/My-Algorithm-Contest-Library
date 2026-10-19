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
int n,m,dis[N];
bool vis[N];
vector<int> G[N];
void solve(){
    n = read(); m = read();
    for(int i=0;i<n;i++) G[i].clear(),dis[i] = 1e9;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<n;i++) G[i].push_back((i+1)%n);
    dis[0] = 0;
    queue<int> q; q.push(0);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : G[x])
           if(dis[y] > dis[x]+1) dis[y] = dis[x]+1,q.push(y);
    }
    for(int i=0;i<n;i++) putchar((dis[i] & 1) ? 'R' : 'B');
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
