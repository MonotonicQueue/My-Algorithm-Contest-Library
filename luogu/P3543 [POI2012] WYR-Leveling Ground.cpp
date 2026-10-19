#include<bits/stdc++.h>
#define ppp if(abs(X)+abs(Y) < abs(ansx[i])+abs(ansy[i])) ansx[i] = X,ansy[i] = Y;
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
int exgcd(int a,int b,int &x,int &y){
	if(!b){x = 1; y = 0; return a;}
	int d = exgcd(b,a%b,x,y),z = x;
	x = y; y = z-(a/b)*y;
	return d;
}
const int N = 1e5+10;
int n,a,b,x,y;
int m[N],c[N],ansx[N],ansy[N];
priority_queue<pair<ll,int> >q;
int main(){
	n = read(); a = read(); b = read();
	ll d = exgcd(a,b,x,y);
	a /= d; b /= d;
	for(int i=1;i<=n;i++){
		m[i] = read();
		c[i] = m[i]-m[i-1];
		if(c[i] % d != 0){
			puts("-1");
			return 0;
		}
	}
	n++; c[n] = -m[n-1];
	for(int i=1;i<=n;i++){
		int X = (1ll*c[i]*x/d%b+b)%b, Y = (c[i]/d-1ll*a*X)/b;
		ansx[i] = X; ansy[i] = Y;
		X -= b; Y += a; ppp
		Y = (1ll*c[i]*y/d%a+a)%a; X = (c[i]/d-1ll*b*Y)/a; ppp
		Y -= a; X +=b; ppp
	}
	ll s = 0;
	for(int i=1;i<=n;i++) s += ansx[i];
	s /= b;
	if(s < 0) s = -s,swap(ansx,ansy),swap(a,b);
	for(int i=1;i<=n;i++) q.push(make_pair(-(abs(ansx[i]-b)+abs(ansy[i]+a)-abs(ansx[i])-abs(ansy[i])),i));
	while(s--){
		int x = q.top().second; q.pop();
		ansx[x] -= b; ansy[x] += a;
		q.push(make_pair(-(abs(ansx[x]-b)+abs(ansy[x]+a)-abs(ansx[x])-abs(ansy[x])),x));
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) ans += abs(ansx[i])+abs(ansy[i]);
	printf("%lld",ans/2);
	return 0; 
} 

