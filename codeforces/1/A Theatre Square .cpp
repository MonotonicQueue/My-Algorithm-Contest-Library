#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,n,m;
	cin >>n>>m>>a;
	if(n%a!=0) n=n/a+1;
	else n/=a;
	if(m%a!=0) m=m/a+1;
	else m/=a;
	cout<<m*n;
	return 0;
}