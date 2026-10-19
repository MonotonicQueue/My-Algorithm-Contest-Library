#include<bits/stdc++.h>
using namespace std;
double f[1100][1100];
double q(int n,int m){
	if(f[n][m]) return f[n][m];
	if(!n) return f[n][m] = 1.000/(m+1);
	if(!m) return f[n][m] = 1.000;
	double a = m * (1 - q(m - 1, n)) / (m + 1.0), b = 1 / (m + 1.0) + a, c = 1, d = 1 - q(m, n - 1);
	double p = (d - c) / (a - b - c + d);
	return f[n][m] = p*a+(1.000-p)*c;
}
int main(){
	int n,m;
	cin >> n >> m;
	double p=q(n,m);
	printf("%.10lf %.10lf",p,1.000-p);
	return 0;
}