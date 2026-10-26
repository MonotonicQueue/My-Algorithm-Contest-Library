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
const int N = 3010;
const ll inf = 9e18;
int n,m;
ll x,y,z;
int a[N],b[N];
ll f[N][N];
void solve(){
    n = read(); m = read();
    x = read(); y = read(); z = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++) b[i] = read();
    for(int i=0;i<=n+1;i++) 
        for(int j=0;j<=m+1;j++) f[j][i] = inf;
    f[1][1] = x;
    for(int i=1;i<=m+1;i++){
        for(int j=1;j<=n;j++){
            f[i+1][j+1] = min(f[i+1][j+1],f[i][j]+abs(a[j]-b[i])*y);
            f[i][j+1] = min(f[i][j+1],f[i][j]+z);
        }
        f[i][1] = min(f[i][1],f[i][n+1]+x);
        for(int j=1;j<=n;j++){
            f[i+1][j+1] = min(f[i+1][j+1],f[i][j]+abs(a[j]-b[i])*y);
            f[i][j+1] = min(f[i][j+1],f[i][j]+z);
        }
    }
    cout << f[m+1][n+1] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
