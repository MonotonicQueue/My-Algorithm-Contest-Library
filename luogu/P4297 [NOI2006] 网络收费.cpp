#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = (1<<11)+10;
int n;
int a[N],c[N],f[N][N];
int dp[N][N],ql[N],qr[N];
int tmp[N];
#define ls rt<<1
#define rs rt<<1|1
void dfs(int rt,int l,int r,int sit,int dep){
	if(l == r){
		dep--;
		dp[rt][0] = dp[rt][1] = 0;
		if(a[l]) dp[rt][1] = c[l];
		else dp[rt][0] = c[l];
		for(int i=1;i<=dep;i++){
			int mid = (ql[i]+qr[i])>>1;
			if(sit&(1<<(dep-i))){
				if(l <= mid) dp[rt][0] += f[l][qr[i]]-f[l][mid];
				else 		 dp[rt][0] += f[l][mid]-f[l][ql[i]-1];
			}else{
				if(l <= mid) dp[rt][1] += f[l][qr[i]]-f[l][mid];
				else 		 dp[rt][1] += f[l][mid]-f[l][ql[i]-1];
			}
		}
		return ;
	}
	int mid = (l+r)>>1,len = r-l+1;
	ql[dep] = l; qr[dep] = r;
	dfs(ls,l,mid,sit<<1,dep+1);
	dfs(rs,mid+1,r,sit<<1,dep+1);
	memset(tmp,0x3f,sizeof(tmp));
	for(int i=0;i<=len/2-1;i++)
		for(int j=0;j<=i;j++)
			tmp[i] = min(tmp[i],dp[ls][j]+dp[rs][i-j]);
	for(int i=0;i<=len/2-1;i++) dp[rt][i] = tmp[i];
	dfs(ls,l,mid,sit<<1|1,dep+1);
	dfs(rs,mid+1,r,sit<<1|1,dep+1);
	memset(tmp,0x3f,sizeof(tmp));
	for(int i=len/2;i<=len;i++)
		for(int j=0;j<=i;j++)
			tmp[i] = min(tmp[i],dp[ls][j]+dp[rs][i-j]);
	for(int i=len/2;i<=len;i++) dp[rt][i] = tmp[i];
}
int main(){
	n = read(); n = 1<<n;
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) c[i] = read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[j][i] = f[i][j] = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j] += f[i][j-1];
	memset(dp,0x3f,sizeof(dp));
	dfs(1,1,n,0,1);
	int ans = 2e9;
	for(int i=0;i<=n;i++) ans = min(ans,dp[1][i]);
	cout << ans;
	return 0;
}