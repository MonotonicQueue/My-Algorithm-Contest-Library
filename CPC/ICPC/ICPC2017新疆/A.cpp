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
const int N = 110;
double f[N][N],g[N][N];
void solve(){
    int n = read(),m = read(),k = read();
    for(int t=0;t<=m;t++)
        for(int i=0;i<=n;i++) f[t][i] = 0;
    f[0][n] = 1;
    for(int t=1;t<=m;t++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++) f[t][max(i-k,0)+j] += f[t-1][i]*g[k][j];
        }
    }
    double ans = n;
    for(int i=0;i<=n;i++) ans -= i*f[m][i];
    printf("%.3lf\n",ans);
}
int main(){
    g[0][0] = 1;
    for(int i=1;i<=100;i++){
        for(int j=0;j<=i;j++){
            g[i][j] = g[i-1][j]+g[i-1][j-1];
            g[i][j] /= 2.0;
        }
    }
	int T = read();
	while(T--) solve();
	return 0;
}
/*
1
6
-3 4 2 -1 1 0
*/