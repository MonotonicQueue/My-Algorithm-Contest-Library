#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};
int n,m;
inline int id(int x,int y){
    return (x-1)*m+y;
}
char mp[N];
int f[N][4][4];
void bfs(){
    queue<tuple<int,int,int,int>> q;
    int stx = 0,sty = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[id(i,j)] == 'S') q.push(make_tuple(i,j,0,0)),stx = i,sty = j;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
                f[id(stx,sty)][i][j] = 1;
    while(!q.empty()){
        auto [x,y,lst,cnt] = q.front(); q.pop();
        if(mp[id(x,y)] == 'T'){
            cout << f[id(x,y)][lst][cnt]-1 << "\n";
            return ;
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m || mp[id(nx,ny)] == '#') continue;
            int nl = i,nc = (i == lst ? cnt+1 : 1);
            if(nc > 3) continue;
            if(f[id(nx,ny)][nl][nc]) continue;
            f[id(nx,ny)][nl][nc] = f[id(x,y)][lst][cnt]+1;
            for(int j=nc+1;j<=nc;j++) if(!f[id(nx,ny)][nl][j]) f[id(nx,ny)][nl][j] = f[id(nx,ny)][nl][nc];
            q.push(make_tuple(nx,ny,nl,nc));
        }
    }
    cout << "-1";
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> mp[id(i,j)];
    bfs();
	return 0;
}
