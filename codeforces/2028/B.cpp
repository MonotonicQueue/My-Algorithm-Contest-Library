#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
void solve(){
    ll n = read(),b = read(),c = read();
    if(b == 0){
        if(c >= n) cout << n << "\n";
        else if(c >= n-2) cout << n-1 << "\n";
        else cout << "-1\n";
    }else{
        if(c >= n) cout << n << "\n";
        else cout << n-max(0ll,(n-c-1)/b+1) << "\n";
    }
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}