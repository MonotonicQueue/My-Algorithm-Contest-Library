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

signed main(){
	int T = read();
	while(T--){
		int n = read(),a = read(),b = read();
		if(a*2 < b) cout << a*n << "\n";
		else{
			if(n & 1) cout << (n/2)*b+a << "\n"; 
			else cout << n/2*b << "\n";
		}
	}
	return 0;
}