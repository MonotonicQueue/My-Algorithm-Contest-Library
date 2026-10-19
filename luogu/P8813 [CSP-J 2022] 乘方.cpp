#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}//快读 
ll a,b;
ll ans = 1;
int main(){
	a = read(); b = read();
	if(a == 1){
		cout << 1;
		return 0;
	}
	for(int i=1;i<=b;i++){
		ans *= a;
		if(ans > 1000000000){
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
}