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
const int N = 2100;
int n,m;
ll a[N][N],sum[N][N];
ll Sum(int lx,int ly,int rx,int ry){
    return sum[rx][ry]-sum[lx-1][ry]-sum[rx][ly-1]+sum[lx-1][ly-1];
}
ll f[4][N][N];
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j] = a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[0][i][j] = max(f[0][i-1][j]+3*Sum(i,1,i,j),f[0][i][j-1]+1*Sum(1,j,i,j));
    for(int i=1;i<=n;i++)
        for(int j=m;j;j--)
            f[1][i][j] = max(f[1][i-1][j]+2*Sum(i,j,i,m),f[1][i][j+1]+1*Sum(1,j,i,j));       
    for(int i=n;i;i--)
        for(int j=1;j<=m;j++)
            f[2][i][j] = max(f[2][i+1][j]+3*Sum(i,1,i,j),f[2][i][j-1]+4*Sum(i,j,n,j));
    for(int i=n;i;i--)
        for(int j=m;j;j--)
            f[3][i][j] = max(f[3][i+1][j]+2*Sum(i,j,i,m),f[3][i][j+1]+4*Sum(i,j,n,j));     
    ll ans = -1e18;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++) ans = max(ans,f[0][i][j]+f[1][i][j+1]+f[2][i+1][j]+f[3][i+1][j+1]);
    cout << ans;
    return 0;
}