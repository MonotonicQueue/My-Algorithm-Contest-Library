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
const int N = 2e5+10;
int n,a[N],b[N];
void solve(){
	for(int i=1;i<n;i++)
		if(b[i] != (a[i] & a[i+1])){
			puts("-1");
			return ;
		}
	for(int i=1;i<=n;i++) cout << a[i] << " ";
	cout << "\n";
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<n;i++) b[i] = read();
		b[n] = 0;
		for(int i=1;i<=n;i++) a[i] = b[i] | b[i-1];
		solve();
	}
	return 0;
}
