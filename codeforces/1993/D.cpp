#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 5e5+10;
int n,k,a[N],len;
int g[N],f[N],d[N];
bool chk(int mid){
	int num = len/2+1,mx = 0;
	for(int i=1;i<=n;i++) f[i] = 0;
	for(int i=0;i<=n;i++) g[i] = 0;
	auto chkmx = [&](int x,int y)->int{
		return x > y ? x : y;
	};
	for(int i=1;i<=n;i++){
		int c = d[i];
		if(c+1 > len) continue;
		f[i] = g[c]+(a[i] >= mid);
		g[c+1] = chkmx(g[c+1],f[i]);
		mx = chkmx(mx,f[i]);
	}
	return mx >= num;
}
int main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++) d[i] = (i-1)%k;
		len = (n-1)%k+1;
		int l = 0,r = 1e9,res = -1;
		while(l <= r){
			int mid = (l+r) >> 1;
			if(chk(mid)) res = mid,l = mid+1;
			else r = mid-1;
		}
		cout << res << "\n";
	}
	return 0;
}
/*
1
4 3
3 9 9 2
*/