#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
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
const int N = 15;
const double eps = 1e-8; 
int n;
double W,t,V;
struct node{
	double l,r;
	double v;
	int op;
}a[N];
bool cmp(node x,node y){
	return x.l < y.l;
}
double ans;
int main(){
	n = read(); W = read(); t = read(); V = read();
	for(int i=1;i<=n;i++){
		a[i].l = read(); a[i].r = read()+a[i].l;
		a[i].v = read();
		if(a[i].v > 0) a[i].op = 1;
		else if(a[i].v < 0) a[i].op = 2;
		else a[i].op = 3;
		a[i].v = fabs(a[i].v);
	}
	double lim;
	if(n*t > 500) lim = 0.00005;
	else if(n*t > 200) lim = 0.000025;
	else lim = 0.000005;
	int T = t/lim;
	while(T--){
		for(int i=1;i<=n;i++){
			if(a[i].op == 1){
				a[i].l += lim*a[i].v;
				a[i].r += lim*a[i].v;
				if(W-a[i].r < 0){
					a[i].op = 2;
					a[i].l += (W-a[i].r)*2;
					a[i].r += (W-a[i].r)*2;
				}
			}else if(a[i].op == 2){
				a[i].l -= lim*a[i].v;
				a[i].r -= lim*a[i].v;
				if(a[i].l < 0){
					a[i].op = 1;
					a[i].r = a[i].r-2*a[i].l;
					a[i].l = -a[i].l;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		double sum = 0,l = a[1].l,r = a[1].r;
		for(int i=2;i<=n;i++){
			if(a[i].l > r){
				sum += r-l;
				l = a[i].l; r = a[i].r;
			}else{
				l = min(l,a[i].l); r = max(r,a[i].r);
			}
		}
		
		sum += r-l;
		ans += max(V*lim*(W-sum),0.00); 
	}
	printf("%.2lf",ans);
	return 0;
}
/*
2 4 3 10
0 1 1
3 1 -1


*/