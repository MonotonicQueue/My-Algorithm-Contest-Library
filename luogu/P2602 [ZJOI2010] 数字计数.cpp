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
const int N = 15;
ll ten[N],f[N];
ll cnta[N],cntb[N];
int num[N];
void work(ll x,ll *cnt){
	int len = 0;
	while(x){
		num[++len] = x%10;
		x /= 10;
	}
	for(int i=len;i>=1;i--){
		for(int j=0;j<=9;j++) cnt[j] += f[i-1]*num[i];
		for(int j=0;j<num[i];j++) cnt[j] += ten[i-1];
		ll n = 0;
		for(int j=i-1;j>=1;j--)	n = n*10+num[j];
		cnt[num[i]] += n+1;
		cnt[0] -= ten[i-1]; 
	}
}
int main(){
	ten[0] = 1;
	for(int i=1;i<=14;i++){
		f[i] = i*ten[i-1];
		ten[i] = 10*ten[i-1];
	}
	ll a = read(),b = read();
	work(a-1,cnta); work(b,cntb);
	for(int i=0;i<=9;i++) cout << cntb[i]-cnta[i] << " ";
	return 0;
}