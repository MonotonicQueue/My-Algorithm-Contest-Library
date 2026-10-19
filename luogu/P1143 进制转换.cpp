#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c="0123456789ABCDEF";
ll n,m;
string a;
ll work1(string x,ll y){
	ll len = x.size();
	ll sum = 0 , base = 1;
	for(ll i=len-1;i>=0;i--){
		for(ll j=0;j<=15;j++)
			if(x[i] == c[j]) sum+=j*base;
		base*=y;
	}
	return sum;
}
void work2(ll x,ll y){
	ll b = 1 , i = 0;
	while(b <= x) b*=y , i++; b/=y;
	while(i){
		cout << c[x/b];
		x%=b;
		b/=y;
		i--;
	}
}
int main(){
	cin >> n >> a >> m;
	int n1=work1(a,n);
	work2(n1,m);
	return 0;
}