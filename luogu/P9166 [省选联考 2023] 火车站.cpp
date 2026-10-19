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
const int N = 2e5+10;
int n,m,x,minn=1e9,maxn; 
bool vis[N];
struct node{
	int l,r;
}a[N];
bool cmp(node x,node y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
int main(){
	n = read(); m = read(); x = read();
	for(int i=1;i<=m;i++){
		a[i].l = read(); a[i].r = read();
		if(a[i].l <= x && x <= a[i].r){
			minn = min(a[i].l,minn);
			maxn = max(a[i].r,maxn);
			vis[a[i].l] = vis[a[i].r] = true;
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++) if(a[i].l <= maxn && a[i].l >= minn) maxn = max(maxn,a[i].r);
	for(int i=m;i>=1;i--) if(a[i].r >= minn && a[i].r <= maxn) minn = min(minn,a[i].l);
	for(int i=1;i<=m;i++){
		if(minn <= a[i].l && a[i].r <= maxn){
			if(a[i].r < x) vis[a[i].l] = true;
			else vis[a[i].r] = true;
		}
	}
	for(int i=1;i<=n;i++) if(vis[i] && i != x) cout << i << " ";
	return 0;
}