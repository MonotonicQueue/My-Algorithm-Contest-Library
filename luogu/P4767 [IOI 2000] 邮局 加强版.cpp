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
const int N = 3100;
const int M = 3040;
int n,m,p[N][M];
ll a[N],f[N][M],sum[N];
ll calc(int l,int r){
    int mid = (l+r) >> 1;
    return sum[r]-sum[mid]-(r-mid)*a[mid]+(mid-l+1)*a[mid]-(sum[mid]-sum[l-1]);
}
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    sort(a+1,a+1+n);
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int j=1;j<=m;j++){
		p[n+1][j] = n-1;
        for(int i=n;i>=1;i--){
            for(int k=p[i][j-1];k<=p[i+1][j];k++){
                if(f[k][j-1]+calc(k+1,i) < f[i][j]){
					f[i][j] = f[k][j-1]+calc(k+1,i);
					p[i][j] = k;
				}
            }
        }
    }
    cout << f[n][m];
	return 0;
}