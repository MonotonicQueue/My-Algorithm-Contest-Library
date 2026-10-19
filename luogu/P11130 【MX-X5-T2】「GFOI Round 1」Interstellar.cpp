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
__int128 gcd(__int128 x,__int128 y){
    return y ? x : gcd(y,x%y);
}
signed main(){
	int T = read();
    while(T--){
        __int128 n = read(),m = read();
        int ans = 0;
        if(m % n != 0){
            puts("-1");
            continue;
        }
        while(n < m){
            __int128 x = __gcd(n*n,m);
            ans++;
            n = x;
            if(ans > 100) break;
        }
        if(n == m) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}