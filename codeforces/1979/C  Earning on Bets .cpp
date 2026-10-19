#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 55;
int n,a[N];
ll gcd(ll x,ll y){
    return y ? gcd(y,x%y) : x;
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
int main(){
	int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        ll d = 1;
        for(int i=1;i<=n;i++) d = lcm(d,a[i]);
        ll sum = 0;
        for(int i=1;i<=n;i++) sum += d/a[i];
        if(sum >= d) puts("-1");
        else{
            for(int i=1;i<=n;i++) cout << d/a[i] << " ";
            cout << "\n";
        }
    }
	return 0;
}
