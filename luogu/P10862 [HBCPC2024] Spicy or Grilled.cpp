#include<bits/stdc++.h>
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

int main(){
    int T = read();
	while(T--){
		ll n = read(),x = read(),a = read(),b = read();
		cout << b*x+(n-x)*a << "\n";
	}
	return 0;
}