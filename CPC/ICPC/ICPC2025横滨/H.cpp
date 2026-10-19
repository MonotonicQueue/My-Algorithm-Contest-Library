#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1010;
int n,m,k;
int a[N][N],b[N][N];
char c[N][N];
bool chk1(int x,int y){
	if(y+k-1 > m) return false;
	for(int i=y;i<=y+k-1;i++)
		if(c[x][i] != '#') return false;
	return true;
}
bool chk2(int x,int y){
	if(x+k-1 > n) return false;
	for(int i=x;i<=x+k-1;i++)
		if(c[i][y] != '#') return false;
	return true;
}
void clear1(int x,int y){
	for(int i=y;i<=y+k-1;i++) c[x][i] = '.';
}
void clear2(int x,int y){
	for(int i=x;i<=x+k-1;i++) c[i][y] = '.';
}
void solve(){
	n = read(); m = read(); k = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin >> c[i][j];
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=m+1;j++) a[i][j] = b[i][j] = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(c[i][j] != '#') continue;
			bool ya = chk1(i,j),yb = chk1(i+k-1,j),
				 xa = chk2(i,j),xb = chk2(i,j+k-1);
			if(ya+yb+xa+xb != 3){
				cout << "no\n";
				return;
			}
			if(ya) clear1(i,j);
			if(yb) clear1(i+k-1,j);
			if(xa) clear2(i,j);
			if(xb) clear2(i,j+k-1);
		}
	cout << "yes\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}
