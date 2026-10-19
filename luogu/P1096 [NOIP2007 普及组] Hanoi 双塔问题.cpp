#include<bits/stdc++.h>
using namespace std;
int a[9999];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a[1]=2;
	int len=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len;j++) a[j]*=2;
		for(int j=1;j<=len;j++)
			if(a[j]>=10){
				a[j+1]+=a[j]/10;
				a[j]%=10;
				if(j==len) len++;
			}
	}
	for(int i=len;i>=2;i--) cout << a[i];
	cout << a[1]-2;
	return 0;
}