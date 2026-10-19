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
const int N = 110;
const int M = 2010;
const int mod = 998244353;
int n,m,a[N][M];
ll sum[N];
inline void add(ll &x,ll y){x = x+y >= mod ? x+y-mod : x+y;}
inline void del(ll &x,ll y){x = x-y >= 0 ? x-y : x-y+mod;}
ll f[N][N*2];
/*
枚举出现次数超过一半的菜
f_{i,j}
考虑了前i种烹饪方法，主要食材出现次数*2-做的菜数=j的方案数
*/
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) a[i][j] = read();
	//枚举做多少道菜 i 
	//总 - 一种菜超过 i/2 的方案

	ll ans = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) add(sum[i],a[i][j]);
		ans = ans*(sum[i]+1)%mod;
	}
	del(ans,1);

	for(int x=1;x<=m;x++){
		for(int i=1;i<=n;i++) del(sum[i],a[i][x]);
		memset(f,0,sizeof(f));
		f[0][n] = 1;
		for(int i=0;i<n;i++)
		for(int j=0;j<=2*n;j++) if(f[i][j]){
			add(f[i+1][j],f[i][j]); //不用这种烹饪方法
			add(f[i+1][j+1],a[i+1][x]*f[i][j]%mod); //选钦定的特殊菜
			add(f[i+1][j-1],sum[i+1]*f[i][j]%mod);	//选其他菜
		}
		for(int i=n+1;i<=2*n;i++) del(ans,f[n][i]);
		for(int i=1;i<=n;i++) add(sum[i],a[i][x]);
	}
	cout << ans;
    return 0;
}
