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
const int N = 1510;
int l,m,n,a[N];
int b[N][N],pos[N*N];
int f[2][N][N];
void clear(){
    for(int i=1;i<=n*m;i++) pos[i] = 0;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++) f[0][i][j] = f[1][i][j] = 1e9;
}
void solve(){
    l = read(); n = read(); m = read();
    for(int i=1;i<=l;i++) a[i] = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[i][j] = read();
    clear();
    for(int i=1;i<=l;i++){
        if(pos[a[i]]){
            l = i-1;
            break;
        }
        pos[a[i]] = i;
    }
    for(int i=n;i;i--){
        for(int j=m;j;j--){
            f[0][i][j] = min(f[0][i+1][j],f[0][i][j+1]);
            f[1][i][j] = min(f[1][i+1][j],f[1][i][j+1]);
            if(!pos[b[i][j]]) continue;
            if(pos[b[i][j]] % 2 == 0 && pos[b[i][j]]+3 <=  f[1][i+1][j+1]) f[0][i][j] = min(f[0][i][j],pos[b[i][j]]);
            if(pos[b[i][j]] % 2 == 1 && pos[b[i][j]]+3 <=  f[0][i+1][j+1]) f[1][i][j] = min(f[1][i][j],pos[b[i][j]]);
        }
    }
    puts(f[1][1][1] == 1 ? "T" : "N");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
