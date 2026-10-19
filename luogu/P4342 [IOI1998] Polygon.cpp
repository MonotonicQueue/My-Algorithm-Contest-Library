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
const int N = 105;
int n;
ll f[N][N],g[N][N];
char op[N];
int main(){
    n = read();
    memset(f,0xcf,sizeof(f));
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++){
        cin >> op[i-1] >> f[i][i];
        op[i+n-1] = op[i-1];
        g[i][i] = g[i+n][i+n] = f[i+n][i+n] = f[i][i];
    }
    // for(int i=1;i<=2*n-1;i++) cout << op[i] << " ";
    // cout << "\n";
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n-1;i++){
            int j = i+len-1;
            for(int k=i;k<j;k++){
                if(op[k] == 't'){
                    f[i][j] = max(f[i][j],f[i][k]+f[k+1][j]);
                    g[i][j] = min(g[i][j],g[i][k]+g[k+1][j]);
                }else{
                    f[i][j] = max(f[i][j],max(f[i][k]*f[k+1][j],max(g[i][k]*g[k+1][j],max(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                    g[i][j] = min(g[i][j],min(f[i][k]*f[k+1][j],min(g[i][k]*g[k+1][j],min(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << f[i][i+n-1] << " ";
    // cout << "\n";
    ll ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,f[i][i+n-1]);
    cout << ans << "\n";
    for(int i=1;i<=n;i++)
        if(f[i][i+n-1] == ans) cout << i << " ";
	return 0;
}
