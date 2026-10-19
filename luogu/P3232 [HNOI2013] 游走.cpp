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
const int N = 5100;
const int M = 126000*2;
int n,m,deg[N];
int head[N],to[M*2],nxt[M*2],tot;
inline void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
} 
double a[N][N],f[M];
void guass(int cnt){
	for(int i=1;i<=cnt;i++){
		int maxn = i;
		for(int j=i+1;j<=cnt;j++)
			if(fabs(a[j][i]) > fabs(a[maxn][i]))
				maxn = j;
		swap(a[maxn],a[i]);
		for(int j=cnt+1;j>=i;j--) a[i][j] /= a[i][i];
		for(int j=i+1;j<=cnt;j++)
				for(int k=cnt+1;k>=i;k--)
					a[j][k] -= a[j][i]*a[i][k];
	}
	for(int i=cnt;i>=1;i--){
		for(int j=i+1;j<=n;j++)
			a[i][cnt+1] -= a[j][cnt+1]*a[i][j];
		a[i][cnt+1] /= a[i][i];
	}
}
int st[M],ed[M];
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		st[i] = u; ed[i] = v;
		add(u,v); add(v,u);
		deg[u]++; deg[v]++;
	}
	a[1][n] = -1;
	for(int i=1;i<n;i++){
		a[i][i] = -1;
		for(int j=head[i];j;j=nxt[j]){
			if(to[j] != n)
				a[i][to[j]] = 1.0/deg[to[j]];
		}
	}
	guass(n-1);
	for(int i=1;i<=m;i++){
		int x = st[i],y = ed[i];
		if(x != n) f[i] += a[x][n]/deg[x];
		if(y != n) f[i] += a[y][n]/deg[y];
	}
	sort(f+1,f+1+m);
	double ans = 0.0;
	for(int i=1;i<=m;i++) ans += (m-i+1)*f[i];
	printf("%.3lf",ans);
	return 0;
} 