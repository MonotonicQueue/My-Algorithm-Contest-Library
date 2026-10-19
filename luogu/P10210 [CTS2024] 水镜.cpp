#include<bits/stdc++.h>
#define ll long long
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
const int N = 5e5+10;
int n,Lg;
ll h[N],f[N][22],g[N][22];
ll qrymn(int l,int r){
	int k = log(r-l+1)/log(2);
	return max(g[l][k],g[r-(1<<k)+1][k]);
}
ll qrymx(int l,int r){
	int k = log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	n = read();
	Lg = log(n)/log(2);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) h[i] = read();
	for(int i=2;i<n;i++){
		if(h[i-1] <= h[i] && h[i] >= h[i+1]) g[i][0] = min(h[i-1]+h[i],h[i]+h[i+1]);
		if(h[i-1] >= h[i] && h[i] <= h[i+1]) f[i][0] = max(h[i-1]+h[i],h[i]+h[i+1]);
	}
	for(int j=1;j<=Lg;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int j=1;j<=Lg;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g[i][j] = max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	ll ans = 0;
	for(int i=1;i<n;i++){
		int l = i+1,r = n,res = l;
		while(l <= r){
			int mid = (l+r)>>1;
			if(mid-i<=1 || qrymn(i+1,mid-1) < qrymx(i+1,mid-1)){
				res = mid;
				l = mid+1;
			}else r = mid-1;
		}
		ans += res-i;
	}
	cout << ans;
	return 0;
}



























