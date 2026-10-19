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
const int N = 510;
const double eps = 1e-4;
int n,m;
struct node{
	double a[N];
	int c,pos;
}b[N];
bool cmp(node x,node y){
	return x.c < y.c;
}
bool vis[N];
int main(){
    n = read(); m = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) b[i].a[j] = read();
	for(int i=1;i<=n;i++) b[i].c = read();
	sort(b+1,b+1+n,cmp);
	int ans = 0,cnt = 0;
	for(int i=1;i<=n;i++){
		int pos = 1;
		while(pos <= m &&(vis[pos] || fabs(b[i].a[pos]) <= eps)) pos++;
		if(pos > m) continue;
		// cout << pos << "\n";
		vis[pos] = true; b[i].pos = pos;
		cnt++; ans += b[i].c;
		for(int j=1;j<=n;j++){
			if(i == j) continue;
			double t = b[j].a[pos]/b[i].a[pos];
			for(int k=1;k<=m;k++)
				b[j].a[k] -= t*b[i].a[k];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++) printf("%.5lf ",b[i].a[j]);
	// 	cout << "\n";
	// }
	cout << cnt << " " << ans;
    return 0;
} 