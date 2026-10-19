#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 310;
int n,m;
int a[N][N][N];
char s[N][N];
ull hsh[N][N],pw[N],P=131;
ull gethsh(int id,int l,int r){
    return hsh[id][r]-hsh[id][l-1]*pw[r-l+1];
}
double pw2[N];
double f[N][N];
inline void guass(){
    for(int i=1;i<=n+1;i++){
        int pos = i;
        for(int j=pos+1;j<=n+1;j++)
            if(fabs(f[j][i]) > fabs(f[pos][i])) pos = j;
        if(pos != i) swap(f[pos],f[i]);
        for(int j=n+2;j>=i;j--) f[i][j] /= f[i][i];
        for(int j=1;j<=n+1;j++){
            if(i == j) continue;
            for(int k=n+2;k>=i;k--)
                f[j][k] -= f[j][i]*f[i][k];
        }
    }
    for(int i=1;i<=n;i++) printf("%.10lf\n",f[i][n+2]);
}
int main(){
    n = read(); m = read();
    pw[0] = 1; pw2[0] = 1.0;
    for(int i=1;i<=m;i++) pw[i] = pw[i-1]*P,pw2[i] = pw2[i-1]*0.5;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++) hsh[i][j] = hsh[i][j-1]*P+s[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++) a[i][j][k] = gethsh(i,1,k) == gethsh(j,m-k+1,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++) f[i][j] += a[i][j][k]*pw2[m-k];
        f[i][n+1] = -pw2[m];
    }
    for(int i=1;i<=n;i++) f[n+1][i] = 1; f[n+1][n+2] = 1;
    guass();
	return 0;
}
