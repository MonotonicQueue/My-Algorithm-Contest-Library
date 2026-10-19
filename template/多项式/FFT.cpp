#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){ch = getchar(); r = -1;}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar(); 
	}
	return X*r;
}
const int N = 4e6+10;
const double Pi = acos(-1.0);
int n,m;
int limit=1,l;
int r[N];
struct Complex{
	double x,y;
	//x + yi
	Complex (double _x=0.0,double _y=0.0){
		x = _x; y = _y;
	}
	
	Complex operator + (const Complex &b) const{
		return Complex(x+b.x,y+b.y);
	}
	Complex operator - (const Complex &b) const{
		return Complex(x-b.x,y-b.y);
	}
	Complex operator * (const Complex &b) const{
		return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
	} 
	
}F[N],G[N];

void FFT(Complex *A,int typ){
	for(int i=0;i<limit;i++)
		if(i < r[i]) swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		Complex Wn(cos(Pi/mid),typ*sin(Pi/mid));
		for(int len=mid<<1,j=0;j<limit;j+=len){
			Complex w(1,0);
			for(int k=0;k<mid;k++){
				Complex A0 = A[j+k],A1 = w*A[j+k+mid];
				A[j+k] = A0+A1;
				A[j+k+mid] = A0-A1;
				w = w*Wn;
			}
		}
	}
	if(typ == -1){
		for(int i=0;i<limit;i++) A[i].x /= limit;
	}
}
int main(){
	n = read(); m = read();
	for(int i=0;i<=n;i++) F[i].x = read();
	for(int i=0;i<=m;i++) G[i].x = read();
	while(limit <= n+m) limit <<= 1,l++;
	for(int i=0;i<limit;i++) r[i] = (r[i>>1]>>1) | ((i & 1) << (l-1));
	FFT(F,1); FFT(G,1);
	for(int i=0;i<=limit;i++) F[i] = F[i]*G[i];
	FFT(F,-1);
	for(int i=0;i<=n+m;i++) printf("%d ",int(F[i].x+0.5)); 
	return 0;
}
