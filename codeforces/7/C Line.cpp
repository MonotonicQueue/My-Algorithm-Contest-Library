#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	ll X = 0 , f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){
		f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		X = (X<<1)+(X<<3)+ch-'0';
		ch = getchar();
	}
	return X*f;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b,a%b,x,y);
	ll z = x;
	x = y;
	y = z-(a/b)*y;
	return d;
}
signed main(){
	ll a,b,c;
	a = read();
	b = read();
	c = read();
	c = -c;
	ll x,y;
	ll d = exgcd(a,b,x,y);
	if(c%d == 0){
		x = x*(c/d);
		y = y*(c/d);
		cout << x << " " << y;
	}else
		puts("-1");
	return 0;
}
