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
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,m,q;
pii p[N];
ll dis[N][55],a[N];
int id(int x,int y){
    return (x-1)*m+y;
}
bool chk(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i != n && a[id(i,j)]+a[id(i+1,j)] < 0) return true;
            if(j != m && a[id(i,j)]+a[id(i,j+1)] < 0) return true;
        }
    }
    return false;
}
bool vis[N];

void dijkstra(int st){
    priority_queue<pair<ll,pii>> q;
    for(int i=1;i<=n*m;i++) dis[i][st] = 1e18;
    dis[id(p[st].fi,p[st].se)][st] = a[id(p[st].fi,p[st].se)];
    q.push(mk(-a[id(p[st].fi,p[st].se)],p[st]));
    while(!q.empty()){
        int x = q.top().se.fi,y = q.top().se.se;
        ll w = q.top().fi; q.pop();
        if(dis[id(x,y)][st] != -w) continue;
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(dis[id(nx,ny)][st] > dis[id(x,y)][st]+a[id(nx,ny)]){
                dis[id(nx,ny)][st] = dis[id(x,y)][st]+a[id(nx,ny)];
                q.push(mk(-dis[id(nx,ny)][st],mk(nx,ny)));
            }
        }
    }

}
signed main(){
	n = read(); m = read(); q = read();
    for(int i=1;i<=n*m;i++) a[i] = read();
    for(int i=1;i<=q;i++){
        int x = read(),y = read();
        p[i] = mk(x,y);
    }
    if(chk()) return puts("No"),0;
    for(int i=1;i<=q;i++) dijkstra(i);
    ll ans = 1e18;
    for(int i=1;i<=n*m;i++){
        ll mx = -1e18;
        for(int j=1;j<=q;j++) mx = max(mx,dis[i][j]);
        ans = min(ans,mx);
    }
    cout << ans;
    return 0;
}
