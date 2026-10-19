#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
const double eps = 1e-12;
int n,k,q[N];
int g[N];
double f[N];
double slope(int x,int y){
	return (f[x]-f[y])/(x-y);
}
bool chk(double mid){
	int head = 1,tail = 0;
	q[++tail] = 0;
	for(int i=1;i<=n;i++){
		while(head < tail && slope(q[head],q[head+1]) > 1.0/i) ++head;
		f[i] = f[q[head]]+(long double)(i-q[head])/i-mid; g[i] = g[q[head]]+1;
		while(head < tail && slope(q[tail],q[tail-1]) < slope(i,q[tail])) --tail;
		q[++tail] = i;
	}
	return g[n] >= k;
}
int main(){
	n = read(); k = read();
	double l = 0,r = 1e6;
	while(r-l > eps){
		double mid = (l+r)/2;
		if(chk(mid)) l = mid;
		else r = mid; 
	}
	chk(l);
	printf("%.9lf",f[n]+l*k);
    return 0;
}
