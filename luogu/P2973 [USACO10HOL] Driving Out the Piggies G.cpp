#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 310;
const int M = 5e4+10;
const double eps = 1e-15;
int n,m;
int st[M],ed[M],deg[N];
double a[N][N],P,ans[N];
inline void guass(){
	for(int i=1;i<=n;i++){
		int maxn = i;
		for(int j=i+1;j<=n;j++)
			if(fabs(a[j][i]) > fabs(a[maxn][i]))
				maxn = j;
		if(i != maxn) swap(a[i],a[maxn]);
		for(int j=n+1;j>=i;j--) a[i][j] /= a[i][i];
		for(int j=1;j<=n;j++){
			if(i == j || fabs(a[j][i]) < eps) continue;
			for(int k=n+1;k>=i;k--)
				a[j][k] -= a[j][i]*a[i][k];
		}
	}
		
}
int main(){
	n = read(); m = read();
	int PPP = read(),QQQ = read();
	P = PPP*1.0/QQQ;
	for(int i=1;i<=m;i++){
		st[i] = read(); ed[i] = read();
		deg[st[i]]++; deg[ed[i]]++;
	}
	for(int i=1;i<=m;i++){
		a[st[i]][ed[i]] += double(1.0-P)/deg[ed[i]];
		a[ed[i]][st[i]] += double(1.0-P)/deg[st[i]];
	}
	a[1][n+1] = -1;
	for(int i=1;i<=n;i++) a[i][i] = -1;
	guass();
	for(int i=1;i<=n;i++) ans[i] = a[i][n+1]*P;
	for(int i=1;i<=n;i++) printf("%.9lf\n",ans[i]);
	return 0;
} 