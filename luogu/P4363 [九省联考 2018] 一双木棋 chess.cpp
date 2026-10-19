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
const int N = 15;
int n,m,a[N][N],b[N][N];
int f[1<<20][2],vis[1<<20][15];
int dfs(int sta,bool op){
    if(vis[sta][op]) return f[sta][op];
    if(sta == (((1 << n)-1) << m)) return f[sta][op] = 0;
    vis[sta][op] = true;
    if(!op){
        f[sta][op] = -1e9;
        int x = n+1,y = 0;
        int lst = -1;
        for(int i=0;i<n+m;i++){
            int c = (sta >> i) & 1;
            if(c) x--; else y++;
            if(c == 0 && lst == 1)
                f[sta][op] = max(f[sta][op],dfs(sta^(1<<(i-1))^(1<<i),op^1)+a[x][y]);
            lst = c;
        }
        // assert(x == 1 && y == m);
    }else{
        f[sta][op] = 1e9;
        int x = n+1,y = 0;
        int lst = -1;
        for(int i=0;i<n+m;i++){
            int c = (sta >> i) & 1;
            if(c) x--; else y++;
            if(c == 0 && lst == 1)
                f[sta][op] = min(f[sta][op],dfs(sta^(1<<(i-1))^(1<<i),op^1)-b[x][y]);
            lst = c;
        }
        // assert(x == 1 && y == m);
    }
    return f[sta][op];
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[i][j] = read();
    cout << dfs((1<<n)-1,0);
    return 0;
}
