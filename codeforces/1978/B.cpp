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
const int N = 1e6+10;
ll n,a,b;
void solve(){
    n = read(); a = read(); b = read();
    if(a >= b) cout << a*n << "\n";
	else{
		ll len = min(b-a+1,n);
		cout << (b+b-len+1)*len/2+(n-len)*a << "\n";
	}
}
int main(){
	int T = read();
    while(T--) solve();
	return 0;
}
/*
1
4 4 5
*/