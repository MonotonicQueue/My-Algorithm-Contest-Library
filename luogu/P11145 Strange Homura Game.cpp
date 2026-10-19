#include<bits/stdc++.h>
#define ll long long
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
ll ask(long long x){
	cout << "? " << x << endl;
	return read();
}
int main(){
	int T = read();
	ll A = 1e18;
	while(T--){
		ll x = ask(A);
		ll B = A-x-1;
		ll y = ask(B);
		cout << "! " << y+1 << endl;
	}
	return 0;
}
