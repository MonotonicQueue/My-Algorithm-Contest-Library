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
int n,c;
ll a[N],sum[N];
ll f[N][N][2];
int main(){
	n = read(); c = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum[i] = read();
		sum[i] += sum[i-1];
	}
	memset(f,0x3f,sizeof(f));
	f[c][c][0] = f[c][c][1] = 0;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			f[i][j][0] = min(f[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),f[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
			f[i][j][1] = min(f[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]),f[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]));
		}
	}
	cout << min(f[1][n][0],f[1][n][1]);
    return 0;
}
