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
const int N = 1e3+10;
int n,m,sx,sy,d;
void solve(){
    n = read(); m = read();
    sx = read(); sy = read();
    d = read();
    if((sx-d > 1 && sy+d < m) || (sx+d < n && sy-d > 1)) cout << n+m-2 << "\n";
    else puts("-1");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}