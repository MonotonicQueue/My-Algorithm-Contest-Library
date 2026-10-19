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
const int N = 6e3+5;
int n,mod;
int f[N][N<<1];
inline int add(int x,int y){
    return x+y > mod ? x+y-mod : x+y;
}
inline int mul(int x,int y){
    return 1ll*x*y%mod;
}
int main(){
    n = read()*3; mod = read();
    f[0][n] = 1;
    for(int i=0;i<n;i++){
        for(int j=-i;j<=i;j++){
            f[i+1][j+n+1] = add(f[i+1][j+n+1],f[i][j+n]);
            f[i+2][j+n-1] = add(f[i+2][j+n-1],mul(f[i][j+n],i+1));
            f[i+3][j+n] = add(f[i+3][j+n],mul(f[i][j+n],(i+1)*(i+2)));
        }
    }
    int ans = 0;
    for(int j=0;j<=n;j++) ans = add(ans,f[n][j+n]);
    cout << ans;
	return 0;
}
