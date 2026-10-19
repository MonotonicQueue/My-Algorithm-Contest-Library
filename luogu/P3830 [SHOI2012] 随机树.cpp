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
const int N = 110;
int n;
double f[N][N];
signed main(){
    int T = read(); n = read();
    if(T == 1){
        double ans = 0;
        for(int i=2;i<=n;i++) ans += 2.0/i;
        printf("%.6lf",ans);
    }else{
        for(int i=1;i<=n;i++) f[i][0] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                for(int k=1;k<i;k++) f[i][j] += f[k][j-1]+f[i-k][j-1]-f[k][j-1]*f[i-k][j-1];
                f[i][j] /= i-1;
            }
        }
        double ans = 0.0;
        for(int i=1;i<n;i++) ans += f[n][i];
        printf("%.6lf",ans);
    }
    return 0;
}
