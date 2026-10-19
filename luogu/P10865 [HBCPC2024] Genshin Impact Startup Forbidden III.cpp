#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e3+10;
const int dx[5] = {0,0,0,1,-1};
const int dy[5] = {0,1,-1,0,0};
int n,m,k;
struct node{
    int x,y,a;
}a[N];
vector<pii> v;
int pos[N][N],f[1<<20];
bool vis[N][N];
int dfs(int state){
    if(state == 0) return 0;
    if(f[state]) return f[state];
    f[state] = 1e9;
    for(auto &[x,y] : v){
        int s = state;
        for(int i=0;i<5;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(pos[nx][ny] >= 0){
                int k = pos[nx][ny],p = (s >> (2*k)) & 3;
                if(p) s -= 1 << (2*k);
            }
        }
        if(s == state) continue;
        f[state] = min(f[state],dfs(s)+1);
    }
    assert(f[state] >= 0);
    return f[state];
}
int main(){
    memset(pos,-1,sizeof(pos));
    n = read(); m = read(); k = read();
    for(int i=0;i<k;i++){
        a[i].x = read(); a[i].y = read();
        a[i].a = read();
        pos[a[i].x][a[i].y] = i;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<5;j++){
            int nx = a[i].x+dx[j],ny = a[i].y+dy[j];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            v.emplace_back(nx,ny);
        }
    }
    int st = 0;
    for(int i=0;i<k;i++) st += a[i].a<<(2*i);
    assert(st >= 0);
    cout << dfs(st) << "\n";
    
	return 0;
}