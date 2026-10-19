#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e5+10;
int f[N],g[N];
struct node{
	int minn,maxn;
}pre1[N],pre2[N],suf1[N],suf2[N];
bool chk1(int i,int j,int n,int m){
	if(i == 1 || j == 1) return true;
	node X = pre1[i-1],Y = pre2[j-1];
	if(f[X.minn] < g[Y.minn]) return chk1(X.minn,j,n,m);
	if(f[X.maxn] < g[Y.maxn]) return chk1(i,Y.maxn,n,m);
	return false;
}
bool chk2(int i,int j,int n,int m){
	if(i == n || j == m) return true;
	node X = suf1[i+1],Y = suf2[j+1];
	if(f[X.minn] < g[Y.minn]) return chk2(X.minn,j,n,m);
	if(f[X.maxn] < g[Y.maxn]) return chk2(i,Y.maxn,n,m);
	return false;
}
inline bool solve(int tf[],int tg[],int n,int m){
	if(tf[1] >= tg[1]) return false;
	for(int i=1;i<=n;i++) f[i] = tf[i];
	for(int i=1;i<=m;i++) g[i] = tg[i];
	for(int i=1;i<=n;i++){
		if(i == 1) pre1[i] = node{1,1};
		else pre1[i] = node{f[pre1[i-1].minn] < f[i] ? pre1[i-1].minn : i,f[pre1[i-1].maxn] > f[i] ? pre1[i-1].maxn : i};
	}
	for(int i=1;i<=m;i++){
		if(i == 1) pre2[i] = node{1,1};
		else pre2[i] = node{g[pre2[i-1].minn] < g[i] ? pre2[i-1].minn : i,g[pre2[i-1].maxn] > g[i] ? pre2[i-1].maxn : i};
	}
	for(int i=n;i>=1;i--){
		if(i == n) suf1[i] = node{n,n};
		else suf1[i] = node{f[suf1[i+1].minn] < f[i] ? suf1[i+1].minn : i,f[suf1[i+1].maxn] > f[i] ? suf1[i+1].maxn : i};
	}
	for(int i=m;i>=1;i--){
		if(i == m) suf2[i] = node{m,m};
		else suf2[i] = node{g[suf2[i+1].minn] < g[i] ? suf2[i+1].minn : i,g[suf2[i+1].maxn] > g[i] ? suf2[i+1].maxn : i};
	}
	node X = pre1[n],Y = pre2[m];
	if(f[X.minn] >= g[Y.minn] || f[X.maxn] >= g[Y.maxn]) return false;
	return chk1(X.minn,Y.maxn,n,m) && chk2(X.minn,Y.maxn,n,m);
}
int a[N],b[N],tmpa[N],tmpb[N];
int main(){
// 	freopen("expand.in","r",stdin);
//	freopen("expand.out","w",stdout);
	int c,n,m,q; 
	c = read(); n = read(); m = read(); q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++) b[i] = read();
	printf("%d",solve(a,b,n,m)||solve(b,a,m,n));
	while(q--){
		for(int i=1;i<=n;i++) tmpa[i] = a[i];
		for(int i=1;i<=m;i++) tmpb[i] = b[i];
		int kx = read(),ky = read();
		while(kx--){
			int x = read(),y = read();
			tmpa[x] = y;
		}
		while(ky--){
			int x = read(),y = read();
			tmpb[x] = y;
		}
		printf("%d",solve(tmpa,tmpb,n,m)||solve(tmpb,tmpa,m,n));
	}
	return 0;
} 