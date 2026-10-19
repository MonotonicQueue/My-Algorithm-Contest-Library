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
const int N = 55;
int n,a[N],b[N];
int f[N][N][510],suf[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i] == a[j]) suf[i] += b[j];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=suf[i];j++) f[i][i][j] = (b[i]+j)*(b[i]+j);
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			for(int k=0;k<=suf[j];k++) f[i][j][k] = f[i][j-1][0]+(b[j]+k)*(b[j]+k);
			for(int k=i;k+2<=j;k++)
				if(a[k] == a[j]) for(int t=0;t<=suf[j];t++)
					f[i][j][t] = max(f[i][j][t],f[i][k][t+b[j]]+f[k+1][j-1][0]);
		}
	}
	cout << f[1][n][0];
    return 0;
}