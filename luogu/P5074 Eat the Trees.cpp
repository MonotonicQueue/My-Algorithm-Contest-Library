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
const int N = 15;
const int S = 10000;
int n,m,a[N][N];
ll f[2][S];
void solve(){
    n = read(); m = read();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) a[i][j] = read();
    int state = 1<<(m+1);
    for(int i=0;i<state;i++) f[0][i] = f[1][i] = 0;
    f[0][0] = 1;
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c ^= 1;
            for(int k=0;k<state;k++) f[c][k] = 0;
            for(int k=0;k<state;k++){
                if(!f[c^1][k]) continue;
                int lft = (k>>j)&1,up = (k>>(j+1))&1;
                if(a[i][j]){
                    if(lft == up) f[c][k^(3<<j)] += f[c^1][k];
                    else f[c][k^(3<<j)] += f[c^1][k],f[c][k] += f[c^1][k];
                }else{
                    if(lft == 0 && up == 0) f[c][k] += f[c^1][k];
                }
            }
        }
        for(int k=0;k<state;k++) f[c^1][k] = f[c][k],f[c][k] = 0;
        for(int k=0;k<(1<<m);k++) f[c][k<<1] = f[c^1][k];
    }
    cout << f[c][0] << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
