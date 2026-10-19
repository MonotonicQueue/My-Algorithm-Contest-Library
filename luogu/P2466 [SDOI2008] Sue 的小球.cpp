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
const int N = 1010;
int n,x0;
struct node{
	int x,y,c;
}a[N];
ll sum[N],tot;
ll f[N][N][2];
int main(){
	n = read(); x0 = read();
	for(int i=1;i<=n;i++) a[i].x = read();
	for(int i=1;i<=n;i++) a[i].y = read();
	for(int i=1;i<=n;i++) a[i].c = read();
	a[++n] = {x0,0,0};
	sort(a+1,a+1+n,[](node x,node y){return x.x < y.x;});
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i].c,tot += a[i].y;
	memset(f,0xcf,sizeof(f));
	for(int i=1;i<=n;i++)
	 	if(a[i].x == x0) f[i][i][0] = f[i][i][1] = tot;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			f[i][j][0] = max(f[i+1][j][0]-(a[i+1].x-a[i].x)*(sum[i]+sum[n]-sum[j]),f[i+1][j][1]-(a[j].x-a[i].x)*(sum[i]+sum[n]-sum[j]));
			f[i][j][1] = max(f[i][j-1][1]-(a[j].x-a[j-1].x)*(sum[i-1]+sum[n]-sum[j-1]),f[i][j-1][0]-(a[j].x-a[i].x)*(sum[i-1]+sum[n]-sum[j-1]));
		}
	}
	printf("%.3lf",max(f[1][n][0],f[1][n][1])*1.0/1000);
    return 0;
}
