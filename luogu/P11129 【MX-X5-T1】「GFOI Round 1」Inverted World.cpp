#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
ll n,k,d;
signed main(){
	int T = read();
    while(T--){
        n = read(); k = read(); d = read();
        if(d % 2 == 0) cout << n*(n-1)/2+n << "\n";
        else{
            ll len = (n+1)/2;
            ll ans = len*n+len;
            ans -= (1+1+(len-1)*2)*len/2;
            cout << ans << "\n";
        }
    }
    return 0;
}
