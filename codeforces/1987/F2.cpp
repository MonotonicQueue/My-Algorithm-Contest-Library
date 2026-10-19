#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 810;
const int inf = 1e9;
int n,a[N];
int f[N][N],g[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	auto clear = [&](){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) f[i][j] = inf;
		for(int i=1;i<=n;i++) g[i] = 0;
	};
	clear();
	auto chkmx = [](int x,int y,int z)->int{
		return max(x,max(y,z));
	};
	for(int len=2;len<=n;len+=2)
		for(int i=1;i+len-1<=n;i++){
			int j = i+len-1;
			if(a[i] % 2 != i % 2 || a[i] > i) continue;
			int val = (i-a[i])/2;
			if(len == 2 || f[i+1][j-1] <= val) f[i][j] = val;
			for(int k=i+1;k<=j;k+=2)
				f[i][j] = min(f[i][j],chkmx(val,f[i][k],f[k+1][j]-(k-i+1)/2));
		}
	for(int i=1;i<=n;i++){
		g[i] = g[i-1];
		for(int j=i-1;j>=1;j-=2)
			if(g[j-1] >= f[j][i]) g[i] = max(g[i],g[j-1]+(i-j+1)/2);
	}
	cout << g[n] << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}