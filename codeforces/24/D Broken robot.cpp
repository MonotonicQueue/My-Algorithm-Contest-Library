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
const int N = 1e3+10;
int n,m,x,y;
double f[N][N],a[N][N]; 
void Guass(){
	for(int i=1;i<m;i++){
		double k = a[i+1][i]/a[i][i];
		a[i+1][i] = 0;
		a[i+1][i+1] -= k*a[i][i+1];
		a[i+1][m+1] -= k*a[i][m+1];
	}
	a[m][m+1] = a[m][m+1]/a[m][m]; a[m][m] = 1;
	for(int i=m-1;i;i--)
		a[i][m+1] = (a[i][m+1]-a[i][i+1]*a[i+1][m+1])/a[i][i];;
}
int main(){
	n = read(); m = read(); x = read(); y = read();
	n -= x-1; x = 1;
	if(m == 1){
		printf("%.10lf",(n-1)*2.0);
		return 0;
	}
	for(int i=n-1;i;i--){
		a[1][1] = a[m][m] = 2;
		a[1][2] = a[m][m-1] = -1;
		a[1][m+1] = f[i+1][1]+3;
		a[m][m+1] = f[i+1][m]+3;
		for(int j=2;j<m;j++){
			a[j][j] = 3;
			a[j][j-1] = a[j][j+1] = -1;
			a[j][m+1] = f[i+1][j]+4;
		}
		Guass();
		for(int j=1;j<=m;j++) f[i][j] = a[j][m+1];
	}
	printf("%.10lf",f[1][y]);
	return 0;
}

