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
const int mod = 1e9+7;
int n,a[N];
ll x,y,xx,yy;
int main(){
    n = read();
	x = read(); yy = read(); xx = read(); y = read();
	ll mnx = 1e9,mny = 1e9,mxx = 0,mxy = 0;
	for(int i=1;i<=n;i++){
		ll xxx = read(),yyy = read();
		mnx = min(mnx,xxx); mny = min(mny,yyy);
		mxx = max(mxx,xxx); mxy = max(mxy,yyy);
	}
	cout << (mnx-x+1)*(mny-y+1)%mod*(xx-mxx+1)%mod*(yy-mxy+1)%mod;
    return 0;
}
