#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e5+10;
mt19937 rnd(time(0));
int n,a[N];
struct node{
	ll val,a;
}b[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	sort(a+1,a+1+n,greater<int>());
	ll ans = 0;
	for(int i=1;i<=200;i++)
		for(int j=i+1;j<=200;j++) ans = max(ans,1ll*a[i]*a[j]/__gcd(a[i],a[j]));
	shuffle(a+1,a+1+n,rnd);
	for(int i=1;i<=n;i++) b[i].a = a[i];
	for(int i=1;i<=min(50,n);i++)
		for(int j=1;j<=n;j++)
			b[j].val = max(b[j].val,1ll*a[i]*a[j]/__gcd(a[i],a[j])),ans = max(ans,b[j].val);
	sort(b+1,b+1+n,[](node x,node y){return x.val > y.val;});
	for(int i=1;i<=min(1500,n);i++)
		for(int j=i+1;j<=min(1500,n);j++) ans = max(ans,b[i].a*b[j].a/__gcd(b[i].a,b[j].a));
	for(int i=1;i<=min(20,n);i++)
		for(int j=1;j<=n;j++) ans = max(ans,b[i].a*b[j].a/__gcd(b[i].a,b[j].a));
	cout << ans;
    return 0;
}
