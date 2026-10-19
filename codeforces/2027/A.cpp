#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n;
ll a[N],b[N];
void solve(){
	n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		b[i] = read();
	}
	ll mxh = 0,mxw = 0;
	for(int i=1;i<=n;i++){
		mxh = max(mxh,a[i]);
		mxw = max(mxw,b[i]);
	}
	cout << (mxh+mxw)*2<<"\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
} 
