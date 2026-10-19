#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 110;
int n;
pii a[N];
ll calc(pii x,pii y){
    return x.se*y.fi-x.fi*y.se;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        a[i].fi = read(),a[i].se = read();
    double ans = 0;
    for(int i=2;i<=n-1;i++){
        ans += calc(mk(a[i].fi-a[1].fi,a[i].se-a[1].se),mk(a[i+1].fi-a[1].fi,a[i+1].se-a[1].se));
    }
    printf("%.6lf\n",abs(ans/2.0));
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}