#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
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
const int M = 1010;
const int mod = 1e9+7;
int n,m,a[N];
ll f[2][N][M][3];
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(n == 1){
		cout << (a[1] <= m);
		return 0;
	}
	sort(a+1,a+1+n);
	f[0][0][0][0] = 1;
	for(int i=0;i<n;i++){
		int c = i&1;
		auto clear = [&](){
			for(int j=0;j<=i;j++) for(int k=0;k<=m;k++)
			for(int p=0;p<=2;p++) f[c^1][j][k][p] = 0;
		};
		clear();
		for(int j=0;j<=i;j++){
			for(int k=0;k<=m;k++){
				for(int d=0;d<=2;d++){
					int p = k+(2*j-d)*(a[i+1]-a[i]); ll val = f[c][j][k][d];
					if(!val || p > m) continue;
					f[c^1][j+1][p][d] = (f[c^1][j+1][p][d]+val*(j+1-d))%mod;
					if(d < 2) f[c^1][j+1][p][d+1] = (f[c^1][j+1][p][d+1]+val*(2-d))%mod;
					if(d < 2 && j) f[c^1][j][p][d+1] = (f[c^1][j][p][d+1]+val*(2-d))%mod;
					if(j) f[c^1][j][p][d] = (f[c^1][j][p][d]+val*(2*j-d))%mod;
					if(j > 1) f[c^1][j-1][p][d] = (f[c^1][j-1][p][d]+val*(j-1))%mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<=m;i++)
		ans = (ans+f[n&1][1][i][2])%mod;
	cout << ans;
	return 0;
}