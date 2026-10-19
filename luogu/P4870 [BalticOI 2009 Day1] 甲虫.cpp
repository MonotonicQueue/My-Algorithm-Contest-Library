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
int n;
ll a[N],m;
ll f[N][N][2];
ll calc(int L){
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		if(a[i] == 0) f[i][i][0] = f[i][i][1] = 0;
	for(int len=2;len<=L;len++){
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			f[i][j][0] = min(f[i+1][j][0]+(a[i+1]-a[i])*(L-len+1),f[i+1][j][1]+(a[j]-a[i])*(L-len+1));
			f[i][j][1] = min(f[i][j-1][1]+(a[j]-a[j-1])*(L-len+1),f[i][j-1][0]+(a[j]-a[i])*(L-len+1));
		}
	}
	ll res = 1e18;
	for(int i=1;i+L-1<=n;i++) res = min(res,min(f[i][i+L-1][0],f[i][i+L-1][1]));
	return res;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	a[++n] = 0;
	sort(a+1,a+1+n);
	ll ans = 0;
	for(int i=2;i<=n;i++) ans = max(ans,(i-1)*m-calc(i));
	cout << ans;
    return 0;
}
