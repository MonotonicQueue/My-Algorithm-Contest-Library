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
const int N = 1e5+10;
int n,pos[N];
ll a[N],f[70][N],sum[2][N],b[N];
bool cmp(int x,int y){
	return b[x] < b[y];
}
signed main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) a[i] = a[n]-a[i],pos[i] = i;
	memset(f,0x3f,sizeof(f));
	f[0][0] = 0;
	for(int k=0;k<=60;k++){
		for(int i=1;i<=n;i++) b[i] = a[i] & ((1ll<<k)-1);
		sort(pos+1,pos+n+1,cmp);
		//进位的一定是模2^k排序后后i大的
		for(int i=1;i<=n;i++){
			sum[0][i] = sum[0][i-1];
			sum[1][i] = sum[1][i-1];
			sum[(a[pos[i]]>>k)&1][i]++;
		}
		//枚举后i位产生了进位
		for(int i=0;i<=n;i++){
			//这一位x取0
			f[k+1][sum[1][n]-sum[1][n-i]] = min(f[k+1][sum[1][n]-sum[1][n-i]],f[k][i]+sum[1][n-i]+sum[0][n]-sum[0][n-i]);
			//这一位x取1
			f[k+1][n-sum[0][n-i]] = min(f[k+1][n-sum[0][n-i]],f[k][i]+sum[0][n-i]+sum[1][n]-sum[1][n-i]);
		}
	}
	cout << f[61][0];
    return 0;
}