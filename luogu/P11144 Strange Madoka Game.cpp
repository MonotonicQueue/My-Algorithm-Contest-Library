#include<bits/stdc++.h>
#define ll __int128
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
ll ask(long long x){
	cout << "? " << x << endl;
	return read();
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return a;}
	ll d = exgcd(b,a%b,x,y);
	ll z = x; x = y; y = z-(a/b)*y;
	return d;
}
int main(){
	int T = read();
	ll A = 400000000,B = A-1,M = A*B;
	while(T--){
		ll x = ask(A),y = ask(B);
		ll invA,invB,tmp;
		exgcd(B,A,invB,tmp);
		exgcd(A,B,invA,tmp);
		invA = (invA%M+M)%M;
		invB = (invB%M+M)%M;
		long long ans = (invB*B%M*x%M+invA*A%M*y%M+M)%M;
		cout << "! " << ans << endl;
	}
	return 0;
}
