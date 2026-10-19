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
map<ll,int> mp[3];
int n,pre[N][3];
ll sum[N][3];
map<int,int> f[N];
int dfs(int x,int y){
    if(x < 0 || y < 0) return -1000000000;
    if(x == 0 && y == 0) return 0;
    if(f[x][y]) return f[x][y];
    f[x][y] = 0;
    if(pre[x][0] > pre[y][1]) f[x][y] = max(f[x][y],dfs(pre[x][0],y)+1);
    else f[x][y] = max(f[x][y],dfs(x,pre[y][1])+1);
    f[x][y] = max(f[x][y],dfs(pre[min(x,y)][2],pre[min(x,y)][2])+1);
    return f[x][y];
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) sum[i][0] = read(),sum[i][0] += sum[i-1][0];
    for(int i=1;i<=n;i++) sum[i][1] = read(),sum[i][1] += sum[i-1][1];
    for(int i=1;i<=n;i++) sum[i][2] = sum[i][0]+sum[i][1];
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++){
            if(mp[j][sum[i][j]] || !sum[i][j]) pre[i][j] = mp[j][sum[i][j]];
            mp[j][sum[i][j]] = i;
            pre[i][j] = max(pre[i][j],pre[i-1][j]);
        }
    cout << dfs(n,n);
    return 0;
}
