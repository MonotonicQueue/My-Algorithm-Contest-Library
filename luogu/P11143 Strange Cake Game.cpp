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
ll n,m,a[N],k;
int ans = 0;
signed main(){
	n = read(); m = read();
    k = read();
    for(int i=1;i<=k;i++){
        ll x = read(),y = read();
        if(x <= y) ans++;
    }
    cout << ans;
    return 0;
}