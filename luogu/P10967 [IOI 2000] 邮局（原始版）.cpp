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
const int N = 310;
const int M = 40;
int n,m;
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<i;k++){
                f[i][j] = min(f[i][j],f[k][j-1]+calc(k+1,i));
            }
        }
    }
    cout << f[n][m];
	return 0;
}