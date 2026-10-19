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
const double eps = 1e-8;
int n;
double a[N][N],b[N][N];
void guass(){
	for(int i=1;i<=n;i++){
		int maxn = i;
		for(int j=i+1;j<=n;j++)
			if(fabs(a[maxn][i]) < fabs(a[j][i])) maxn = j;
		if(maxn != i) swap(a[maxn],a[i]),swap(b[maxn],b[i]);
		if(fabs(a[i][i]) < eps){
			puts("NIE");
			exit(0);
		}
		double z = a[i][i];
		for(int j=1;j<=n;j++) a[i][j] /= z,b[i][j] /= z;
		for(int j=1;j<=n;j++){
			if(i == j) continue;
			double t = a[j][i];
			for(int k=1;k<=n;k++)
				a[j][k] -= t*a[i][k],b[j][k] -= t*b[i][k];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			printf("%.2lf ",a[i][j]);
//		printf("\n");
//	}
}
bool c[N][N],vis[N];
int match[N];
bool dfs(int x){
	for(int i=1;i<=n;i++)
		if(!vis[i] && c[x][i]){
			vis[i] = true;
			if(!match[i] || dfs(match[i])){
				match[i] = x;
				return true;
			}
		}
	return false;
}
int dfs(int x,int tp){
	for(int i=1;i<=n;i++){
		if(!vis[i] && c[x][i]){
			vis[i] = true;
			if(match[i] == tp || (match[i] > tp && dfs(match[i],tp))){
				match[i] = x;
				return i;
			}
		}
	}
	return false;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[j][i] = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[j][i] = read();
	guass();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) c[i][j] = fabs(b[i][j]) > eps;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(!dfs(i)){
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		printf("%d\n",dfs(i,i));
	}
	return 0;
} 