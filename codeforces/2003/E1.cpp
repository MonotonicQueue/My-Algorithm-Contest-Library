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
const int N = 5100;
const int INF = 1e9;
int n,m,l[N],r[N],nxt[N];
int f[N][N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=m;i++) l[i] = read(),r[i] = read();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) f[i][j] = -INF;
    for(int i=1;i<=n;i++) nxt[i] = 0;
    for(int i=1;i<=m;i++) nxt[l[i]] = r[i];
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        if(nxt[i]){
            for(int j=0;j<=i;j++)
                for(int k=i;k<nxt[i];k++)
                    f[nxt[i]][j+nxt[i]-k] = max(f[nxt[i]][j+nxt[i]-k],f[i-1][j]+(k-i+1)*j);
            i = nxt[i];
        }else{
            for(int j=0;j<=i;j++){
                f[i][j] = max(f[i][j],f[i-1][j]+j);
                if(j) f[i][j] = max(f[i][j],f[i-1][j-1]); 
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++)
        ans = max(ans,f[n][i]+i*(i-1)/2+(n-i)*(n-i-1)/2);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
