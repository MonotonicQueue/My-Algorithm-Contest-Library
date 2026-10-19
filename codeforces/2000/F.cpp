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
int n,m;
int a[N],b[N];
int f[N][N],g[N],dp[N];
void work(int x,int y){
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++) f[i][j] = 1e9;
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++){
            if(i == 0 && j == 0) f[i][j] = 0;
            if(i > 0) f[i][j] = min(f[i][j],f[i-1][j]+y-j);
            if(j > 0) f[i][j] = min(f[i][j],f[i][j-1]+x-i);
        }
    for(int i=1;i<=x+y;i++) g[i] = 1e9;
    for(int i=0;i<=x;i++)
        for(int j=0;j<=y;j++) g[i+j] = min(g[i+j],f[i][j]);
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) a[i] = read(),b[i] = read();
        int sum = 0;
        for(int i=1;i<=n;i++) sum += a[i]+b[i];
        if(sum < m){
            puts("-1");
            continue;
        }
        dp[0] = 0;
        for(int i=1;i<=m;i++) dp[i] = 1e9;
        for(int i=1;i<=n;i++){
            work(a[i],b[i]);
            for(int j=m;j>=0;j--)
                for(int k=0;k<=min(a[i]+b[i],j);k++) dp[j] = min(dp[j],dp[j-k]+g[k]);
        }
        cout << dp[m] << "\n";
    }
    return 0;
}
