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
ll x,y;
int main(){
    int T = read();
    while(T--){
        x = read(); y = read();
        ll l = x*y/__gcd(x,y)/__gcd(x,y);
        cout << "1 " << l << "\n";
    }
	return 0;
}