#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){ch = getchar(); r = -1;}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar(); 
	}
	return X*r;
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x = 1; y = 0; return;}
	exgcd(b,a%b,x,y);
	ll z = x; x = y; y = z-(a/b)*y;
}
int main(){
	ll a,b;
	a = read(); b = read();
	ll x,y;
	exgcd(a,b,x,y);
	cout << (x%b+b)%b;
	return 0;
}