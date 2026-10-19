// #include "mosaic.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n,Q;
ll a[210][210],b[4][N],c[N][4];
ll sum1[N],sum2[N];
ll calc(int x,int y){
	if(x <= 3) return b[x][y];
	if(y <= 3) return c[x][y];
	ll res = b[3][y]+c[x][3]-b[3][3];
	if(x <= y) res += sum1[y]-sum1[y-x+3]+sum2[x];
	else	   res += sum2[x]-sum2[x-y+3]+sum1[y];
	return res;
}
vector<ll> mosaic(vector<int> X,vector<int> Y,vector<int> T,vector<int> B,vector<int> L,vector<int> R){
	n = (int)X.size(); Q = (int)T.size();
	vector<ll> ans(Q,0);
	if(n <= 3){
		for(int i=1;i<=n;i++) a[1][i] = X[i-1];
		for(int i=1;i<=n;i++) a[i][1] = Y[i-1];
		for(int i=2;i<=n;i++)
			for(int j=2;j<=n;j++)
				a[i][j] = !(a[i-1][j] | a[i][j-1]);
		for(int i=0;i<Q;i++)
			for(int x=T[i]+1;x<=B[i]+1;x++)
				for(int y=L[i]+1;y<=R[i]+1;y++) ans[i] += a[x][y];
		return ans;
	}
	// 	a[i][j] = !(a[i-1][j] | a[i][j-1]);
	for(int i=1;i<=n;i++) b[1][i] = X[i-1];
	for(int i=2;i<=3;i++) b[i][1] = Y[i-1];
	for(int i=2;i<=3;i++)
		for(int j=2;j<=n;j++) b[i][j] = !(b[i-1][j] | b[i][j-1]);
	for(int i=1;i<=n;i++) c[i][1] = Y[i-1];
	for(int i=2;i<=3;i++) c[1][i] = X[i-1];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=3;j++) c[i][j] = !(c[i-1][j] | c[i][j-1]);
	for(int i=4;i<=n;i++) sum1[i] = sum1[i-1]+b[3][i-1];
	for(int i=4;i<=n;i++) sum1[i] += sum1[i-1];
	for(int i=5;i<=n;i++) sum2[i] = sum2[i-1]+c[i-1][3];
	for(int i=5;i<=n;i++) sum2[i] += sum2[i-1];
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++) b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++) c[i][j] += c[i-1][j]+c[i][j-1]-c[i-1][j-1];
	for(int i=0;i<Q;i++) ans[i] = calc(B[i]+1,R[i]+1)-calc(B[i]+1,L[i])-calc(T[i],R[i]+1)+calc(T[i],L[i]);
	return ans;
}
/*
g++ -std=c++14 -Wall -O2 -pipe -static -g -o mosaic mosaic.cpp grader.cpp
./mosaic
*/
