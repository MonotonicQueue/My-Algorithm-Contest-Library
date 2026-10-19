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
const int N = 1e6+10;
int n,x;
int main(){
    int T = read();
    while(T--){
        n = read(); x = read();
        ll ans = 0;
        for(ll i=1;i<=x;i++){
            for(ll j=1;i+j<=x;j++){
                if(i*j > n) break;
                ans += min(1ll*(x-i-j),(n-i*j)/(i+j));
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
