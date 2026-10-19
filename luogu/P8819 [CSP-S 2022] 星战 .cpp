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
const int N = 5e5+10;
int n,m,q;
ll w[N],SUM;
ll r[N],g[N],now;
int main(){
	srand(time(0));
	n = read(); m = read();
	for(int i=1;i<=n;i++) w[i] = rand(),SUM += w[i];
	for(int i=1;i<=m;i++){
		int u = read(),v = read();
		g[v] += w[u];
	}
	for(int i=1;i<=n;i++) r[i] = g[i],now += g[i];
	q = read();
	while(q--){
		int op = read(),u = read(),v;
		if(op == 1){
			v = read();
			r[v] -= w[u];
			now -= w[u];
		}else if(op == 2){
			now -= r[u];
			r[u] = 0;
		}else if(op == 3){
			v = read();
			r[v] += w[u];
			now += w[u];
		}else{
			now += g[u]-r[u];
			r[u] = g[u];
		}
		if(now == SUM) puts("YES");
		else puts("NO");
	}
	return 0;
}