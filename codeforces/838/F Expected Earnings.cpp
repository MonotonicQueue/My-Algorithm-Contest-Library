#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e4+10;
int n;
double c,p[2][N],f[2][N];
int main(){
	n = read(); c = read()/1000000.0;
	for(int i=0;i<=n;i++) p[n&1][i] = read()/1000000.0;
	for(int i=n-1;~i;i--){
		int id = (i & 1);
		for(int j=0;j<=i;j++){
			p[id][j] = p[id^1][j+1]*(j+1)/(i+1)+p[id^1][j]*(i+1-j)/(i+1);
			if(p[id][j] < 1e-18) continue;
            double P = p[id^1][j+1]/p[id][j]*(j+1)/(i+1);
			f[id][j] = max(0.0,P*(f[id^1][j+1]+1)+(1-P)*f[id^1][j]-c);
		}
	}
	printf("%.12lf",f[0][0]);
	return 0;
}
