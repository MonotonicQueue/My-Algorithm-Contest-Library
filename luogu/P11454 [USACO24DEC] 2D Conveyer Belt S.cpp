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
const int N = 1010;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,Q;
vector<pii> G[N*N];
int id(int x,int y){
    if(x < 1 || y < 1 || x > n || y > n) return 0;
    return (x-1)*n+y;
}
pii a[N][N];
int d[N*N],ans[N*N];
bool vis[N*N];
int main(){
    n = read(); Q = read();
    for(int i=1;i<=Q;i++){
        int x = read(),y = read();
        char op; cin >> op;
        int ty = 0;
        if(op == 'L') ty = 3;
        if(op == 'R') ty = 2;
        if(op == 'U') ty = 1;
        if(op == 'D') ty = 0;
        a[x][y] = mk(i,ty);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(!a[i][j].fi) a[i][j].fi = Q+1;
            for(int k=0;k<4;k++){
                int y = id(i+dx[k],j+dy[k]);
                // if(y == 1) cout << i << " " << j << " " << k << " " << a[i][j].se << " 111\n";
                if(k == a[i][j].se) G[y].emplace_back(id(i,j),Q+1);
                else G[y].emplace_back(id(i,j),a[i][j].fi);
            }
        }
    d[0] = Q+1;
    priority_queue<pii> q;
    q.push(mk(d[0],0));
    while(!q.empty()){
        int x = q.top().se; q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto [y,k] : G[x]){
            int t = min(k,d[x]);
            if(t > d[y]){
                d[y] = t;
                q.push(mk(d[y],y));
            }
        }
    }
    for(int i=1;i<=n*n;i++) ans[d[i]-1]++;
    for(int i=Q;i;i--) ans[i] += ans[i+1];
    for(int i=1;i<=Q;i++) cout << n*n-ans[i] << "\n";
    return 0;
}