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
ll a,b,c,d;
void solve(){
    a = 0;
    b = read(); c = read();  d = read();
    for(int i=0;i<61;i++){
        if((b & 1) == (d&1)){

        }else if(((b & 1) | 1)-(c & 1) == (d&1)){
            a |= 1ll << i;
        }else{
            a = -1;
            break;
        }
        b >>= 1; c >>= 1; d >>= 1;
    }
    cout << a << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
