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
const int N = 3e5+10;
const ll inf = 1e18;
int n,k;
vector<pii> G[N];
struct node{
    ll x; int cnt;
    bool operator > (const node &o)const{return x != o.x ? x > o.x : cnt > o.cnt;}
    node operator + (const node &o)const{return node{x+o.x,cnt+o.cnt};}
    node operator + (const int &w)const{return node{x+w,cnt};}
    node operator + (const ll &w)const{return node{x+w,cnt};}
}f[N][3];
void dfs(int x,int fa,ll mid){
    for(auto it : G[x]){
        int y = it.fi;
        if(y == fa) continue;
        dfs(y,x,mid);
        node tmp[3];
        tmp[0] = f[x][0]; tmp[1] = f[x][1]; tmp[2] = f[x][2];
        if(tmp[0]+f[y][0] > f[x][0]) f[x][0] = tmp[0]+f[y][0];
        if(tmp[0]+f[y][1] > f[x][0]) f[x][0] = tmp[0]+f[y][1];
        if(tmp[0]+f[y][2] > f[x][0]) f[x][0] = tmp[0]+f[y][2];

        if(tmp[0]+f[y][0]+node{it.se+mid,1} > f[x][1]) f[x][1] = tmp[0]+f[y][0]+node{it.se+mid,1};
        if(tmp[0]+f[y][1]+it.se > f[x][1]) f[x][1] = tmp[0]+f[y][1]+it.se;
        if(tmp[1]+f[y][0] > f[x][1]) f[x][1] = tmp[1]+f[y][0];
        if(tmp[1]+f[y][1] > f[x][1]) f[x][1] = tmp[1]+f[y][1];
        if(tmp[1]+f[y][2] > f[x][1]) f[x][1] = tmp[1]+f[y][2];
        
        if(tmp[1]+f[y][0]+it.se > f[x][2]) f[x][2] = tmp[1]+f[y][0]+it.se;
        if(tmp[1]+f[y][1]+node{it.se-mid,-1} > f[x][2]) f[x][2] = tmp[1]+f[y][1]+node{it.se-mid,-1};
        if(tmp[2]+f[y][0] > f[x][2]) f[x][2] = tmp[2]+f[y][0];
        if(tmp[2]+f[y][1] > f[x][2]) f[x][2] = tmp[2]+f[y][1];
        if(tmp[2]+f[y][2] > f[x][2]) f[x][2] = tmp[2]+f[y][2];
    }
}
bool chk(ll mid){
    for(int i=1;i<=n;i++) f[i][1] = node{-inf,1000000000},f[i][0] = node{0,0},f[i][2] = node{mid,1};
    dfs(1,0,mid);
    if(f[1][1] > f[1][0]) f[1][0] = f[1][1];
    if(f[1][2] > f[1][0]) f[1][0] = f[1][2];
    return f[1][0].cnt >= k+1;
}
int main(){
    n = read(); k = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read(),w = read();
        G[u].push_back(mk(v,w));
        G[v].push_back(mk(u,w));
    }
    ll l = -3e11,r = 3e11,res = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) r = mid-1,res = mid;
        else l = mid+1;
    }
    chk(res);
    cout << f[1][0].x-res*(k+1);
    return 0;
}