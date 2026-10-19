#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}//快读 
int k;
int main(){
	int k = read();
	while(k--){
		ll n = read(), d = read() , e = read();
		ll m = n-e*d+2;
		ll delta = m*m-4*n;
		ll a = sqrt(delta);
		if(a*a != delta){//delta不是完全平方数 
			puts("NO");
			continue;
		}
		if((m-a) & 1){//即不能被2整除 
			puts("NO");
			continue;
		}
		ll p = (m-a)/2 , q = m-p;
		printf("%lld %lld\n",p,q);
	}
	return 0;
}