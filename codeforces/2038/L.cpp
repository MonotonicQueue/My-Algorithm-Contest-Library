#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e3+10;
int n;
void solve(){
	n = read();
	int a = n,b = n,c = n,ans = 0;
	ans += b/2;
	a -= b/2; b %= 2;
	ans += a/3;
	a %= 3;
	ans += c/2;
	c %= 2;
	if(a == 2){
		ans += 1+c;
	}else if(a == 1){
		if(a+b+c == 3) ans += 2;
		else if(a+b+c == 2) ans += 1;
		else ans += 1;
	}else{
		if(b+c > 0) ans += 1;
	}
	cout << ans << "\n";
}
int main(){
	int T = 1;
	while(T--) solve();
    return 0;
}