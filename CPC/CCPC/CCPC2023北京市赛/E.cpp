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
const int N = 2100;
int n,m;
int a[N],b[N];
int f[N][N];
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=m;i++) b[i] = read();
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+m);
    int ans = min(n,m);
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++) f[i][0] = i;
    for(int i=1;i<=m;i++) f[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j] = min(f[i][j],f[i-1][j]+1);
            f[i][j] = min(f[i][j],f[i][j-1]+1);
            if(a[i] == b[j] || a[i] == 1 || b[j] == 1) f[i][j] = min(f[i][j],f[i-1][j-1]);
            if(i == n || j == m) ans = min(ans,f[i][j]);
        }
    }
    cout << ans;
	return 0;
}