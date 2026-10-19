#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
int n,m,k,ans;
bool a[10][10];
void dfs(int cnt){
    ans = min(ans,k-cnt);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(a[i][j]){
            if(i >= 3 && a[i-1][j] && !a[i-2][j]){
                a[i-1][j] = 0;
                a[i-2][j] = 1;
                a[i][j] = 0;
                dfs(cnt+1);
                a[i-1][j] = 1;
                a[i-2][j] = 0;
                a[i][j] = 1;
            }
            if(j >= 3 && a[i][j-1] && !a[i][j-2]){
                a[i][j-1] = 0;
                a[i][j-2] = 1;
                a[i][j] = 0;
                dfs(cnt+1);
                a[i][j-1] = 1;
                a[i][j-2] = 0;
                a[i][j] = 1;
            }
            if(i <= n-2 && a[i+1][j] && !a[i+2][j]){
                a[i+1][j] = 0;
                a[i+2][j] = 1;
                a[i][j] = 0;
                dfs(cnt+1);
                a[i+1][j] = 1;
                a[i+2][j] = 0;
                a[i][j] = 1;
            }
            if(j <= m-2 && a[i][j+1] && !a[i][j+2]){
                a[i][j+1] = 0;
                a[i][j+2] = 1;
                a[i][j] = 0;
                dfs(cnt+1);
                a[i][j+1] = 1;
                a[i][j+2] = 0;
                a[i][j] = 1;
            }
        }
        
}
void solve(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=k;i++){
        int x = read(),y = read();
        a[x][y] = 1;
    }
    
    ans = k;
    dfs(0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j] = 0;
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}