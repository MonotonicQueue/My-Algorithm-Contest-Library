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
const int B = 1200;
const int N = B+10;
const int inf = 1e9+7;
const int dx[5] = {-1,-1,-1, 1,1};
const int dy[5] = {-1, 0, 1,-1,1};
int n,m;
vector<vector<int>> f[N],g[N];
void solve(){
    n = read(); m = read();
    for(int k=0;k<=B+1;k++){
        f[k].resize(n+1,vector<int>(m+1,0));
        g[k].resize(n+1,vector<int>(m+1,0));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            g[0][i][j] = f[0][i][j] = read();
    for(int k=1;k<=B+1;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int mn = inf,mx = -inf;
                for(int o=0;o<5;o++){
                    int x = i+dx[o],y = j+dy[o];
                    if(x <= 0 || y <= 0 || x > n || y > m) continue;
                    mx = max(mx,g[k-1][x][y]);
                    mn = min(mn,f[k-1][x][y]);
                }
                f[k][i][j] = mx;
                g[k][i][j] = mn;
            }
        }    
    }
    int Q = read();
    while(Q--){
        int x = read(),y = read(); ll k = read();
        k = min(k,B+(k&1));
        cout << f[k][x][y] << "\n";
    }
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
