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
const int N = 2e5+10;
const int mod = 998244353;
int n,k,a[N];
ll f[N][12],sum[12];
int main(){
    n = read(); k = read();
    f[0][0] = 1; sum[0] = 1;
    for(int i=1;i<=n;i++){
        f[i][1] = 1;
        for(int j=2;j<=k;j++)
            f[i][j] = (sum[j-1]-(i >= 3 ? f[i-2][j-1] : 0)+mod)%mod;
        f[i][k] = (f[i][k]+sum[k]-(i >= 3 ? f[i-2][k] : 0)+mod)%mod;
        for(int j=1;j<=k;j++) sum[j] = (sum[j]+f[i][j])%mod;
    }
    cout << (f[n][k]+f[n-2][k-1]+f[n-2][k])%mod;
	return 0;
}
