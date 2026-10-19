#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	int n = read() , ans = read();
	for(int i=2;i<=n;i++){
		int a = read();
		if(a < 0) a = -a;
		ans = gcd(ans,a);
	}
	cout << ans;
	return 0;
}