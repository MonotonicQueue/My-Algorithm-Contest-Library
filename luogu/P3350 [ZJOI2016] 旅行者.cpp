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
const int N = 2e4+10;
const int M = 1e5+10;
const int inf = 1e9;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int n,m,w[N][4],Q;
inline int id(int x,int y){
    return (x-1)*m+y;
}
int dis[N],ans[M];
bool vis[N];
struct Ques{
    int xl,yl,xr,yr,id;
}p[M],tmp[M];

void dij(int nx,int ny,int xl,int xr,int yl,int yr,int l,int r){
    for(int i=xl;i<=xr;i++)
        for(int j=yl;j<=yr;j++)
            dis[id(i,j)] = inf,vis[id(i,j)] = false;
    dis[id(nx,ny)] = 0;
    priority_queue<pair<int,pii> > q; q.push(mk(0,mk(nx,ny)));
    while(!q.empty()){
        int x = q.top().se.fi,y = q.top().se.se; q.pop();
        if(vis[id(x,y)]) continue;
        vis[id(x,y)] = true;
        for(int k=0;k<4;k++){
            int tx = x+dx[k],ty = y+dy[k];
            if(tx < xl || tx > xr || ty < yl || ty > yr) continue;
            if(dis[id(x,y)]+w[id(x,y)][k] < dis[id(tx,ty)]){
                dis[id(tx,ty)] = dis[id(x,y)]+w[id(x,y)][k];
                q.push(mk(-dis[id(tx,ty)],mk(tx,ty)));
            }
        }
    }
    for(int i=l;i<=r;i++)
        ans[p[i].id] = min(ans[p[i].id],dis[id(p[i].xl,p[i].yl)]+dis[id(p[i].xr,p[i].yr)]);
}
void solve(int xl,int xr,int yl,int yr,int l,int r){
    if(xr-xl > yr-yl){
        int mid = (xl+xr)>>1;
        for(int i=yl;i<=yr;i++) dij(mid,i,xl,xr,yl,yr,l,r);
        for(int i=l;i<=r;i++) tmp[i] = p[i];
        int ql = l-1,qr = r+1;
        for(int i=l;i<=r;i++){
            if(tmp[i].xl < mid && tmp[i].xr < mid) p[++ql] = tmp[i];
            if(tmp[i].xl > mid && tmp[i].xr > mid) p[--qr] = tmp[i];
        }
        if(ql >= l) solve(xl,mid-1,yl,yr,l,ql);
        if(qr <= r) solve(mid+1,xr,yl,yr,qr,r);
    }else{
        int mid = (yl+yr)>>1;
        for(int i=xl;i<=xr;i++) dij(i,mid,xl,xr,yl,yr,l,r);
        for(int i=l;i<=r;i++) tmp[i] = p[i];
        int ql = l-1,qr = r+1;
        for(int i=l;i<=r;i++){
            if(tmp[i].yl < mid && tmp[i].yr < mid) p[++ql] = tmp[i];
            if(tmp[i].yl > mid && tmp[i].yr > mid) p[--qr] = tmp[i];
        }
        if(ql >= l) solve(xl,xr,yl,mid-1,l,ql);
        if(qr <= r) solve(xl,xr,mid+1,yr,qr,r);
    }
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            w[id(i,j)][0] = w[id(i,j+1)][1] = read();
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
            w[id(i,j)][2] = w[id(i+1,j)][3] = read();
    Q = read();
    for(int i=1;i<=Q;i++){
        p[i].xl = read(); p[i].yl = read(); 
        p[i].xr = read(); p[i].yr = read(); 
        p[i].id = i; ans[i] = inf;
    }
    solve(1,n,1,m,1,Q);
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
	return 0;
}
