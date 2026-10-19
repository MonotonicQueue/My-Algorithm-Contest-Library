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
const int N = 1e3+10;
int n,m,a[N][N],b[N][N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[i][j] = 4;
    for(int i=1;i<=m;i++) b[1][i]--,b[n][i]--;
    for(int i=1;i<=n;i++) b[i][1]--,b[i][m]--;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j] < a[i][j]){
                puts("NO");
                return ;
            }
    puts("YES");
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++) cout << b[i][j] << " ";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
