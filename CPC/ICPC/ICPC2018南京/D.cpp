#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 110;
const double eps = 1e-5;
int n;
double a[N],b[N],c[N];
double calc(double x,double y,double z){
	double res = 0;
	for(int i=1;i<=n;i++)
		res = max(res,(a[i]-x)*(a[i]-x)+(b[i]-y)*(b[i]-y)+(c[i]-z)*(c[i]-z));
	return res;
}
double calcz(double x,double y){
	double l = -1e5,r = 1e5;
	while(r-l > eps){
		double m1 = (l*2+r)/3,m2 = (l+r*2)/3;
		if(calc(x,y,m1) > calc(x,y,m2)) l = m1;
		else r = m2;
	}
	return calc(x,y,l);
}
double calcy(double x){
	double l = -1e5,r = 1e5;
	while(r-l > eps){
		double m1 = (l*2+r)/3,m2 = (l+r*2)/3;
		if(calcz(x,m1) > calcz(x,m2)) l = m1;
		else r = m2;
	}
	return calcz(x,l);
}
double calcx(){
	double l = -1e5,r = 1e5;
	while(r-l > eps){
		double m1 = (l*2+r)/3,m2 = (l+r*2)/3;
		if(calcy(m1) > calcy(m2)) l = m1;
		else r = m2;
	}
	return calcy(l);
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		b[i] = read();
		c[i] = read();
	}
	printf("%.10lf",sqrt(calcx()));
	return 0;
}