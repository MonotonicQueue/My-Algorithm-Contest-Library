#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 210;
int n,l,K,a[N];
double p[N];
double f[2][N][N];
int pos[N];
bool cmp(int x,int y){
	return a[x] > a[y];
}
int main(){
	n = read(); l = read(); K = read();
	for(int i=1;i<=n;i++) p[i] = read()/100.0;
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) pos[i] = i;
	sort(pos+1,pos+1+n,cmp);
	f[0][0][min(n,K)] = 1;
	for(int i=1;i<=n;i++){
		int op = i&1;
		for(int j=0;j<=i;j++) 
			for(int k=0;k<=n;k++)
				f[op][j][k] = 0;
		for(int j=0;j<i;j++)
			for(int k=0;k<=n;k++){
				f[op][j][k] += f[op^1][j][k]*(1-p[pos[i]]);
				if(k+a[pos[i]] >= 0) f[op][j+1][min(n,k+a[pos[i]])] += f[op^1][j][k]*p[pos[i]];
			}
	}
	double ans = 0.0;
	for(int j=l;j<=n;j++)
		for(int k=0;k<=n;k++) ans += f[n&1][j][k];
	printf("%.10lf",ans);
	return 0;
}
