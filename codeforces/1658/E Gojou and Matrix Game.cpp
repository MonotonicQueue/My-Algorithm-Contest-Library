#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair 
#define fi first
#define se second
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
const int N = 2e3+10;
const int inf = 1e9;
int n,k,a[N][N];
pii p[N*N];
bool sg[N][N];
int main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) a[i][j] = read(),p[a[i][j]] = mk(i,j);
	int mx1 = -inf,mx2 = -inf,mn1 = inf,mn2 = inf;
	for(int i=n*n;i;i--){
		int x = p[i].fi+p[i].se,y = p[i].fi-p[i].se;
		if(max(max(mx1-x,x-mn1),max(mx2-y,y-mn2)) > k) sg[p[i].fi][p[i].se] = 1;
		else{
			mx1 = max(mx1,x); mx2 = max(mx2,y);
			mn1 = min(mn1,x); mn2 = min(mn2,y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(sg[i][j]) putchar('G');
			else 		putchar('M');
		puts("");
	}
		
	return 0;
} 
//g++ -std=c++14 -O2 -Wall -o 1st 1st.cpp