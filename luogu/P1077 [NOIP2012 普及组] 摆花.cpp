#include<bits/stdc++.h>
using namespace std;
const int MAX = 110;
const int mod = 1e6+7;
int a[MAX],f[MAX];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	f[0] = 1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			for(int k=1;k<=min(a[i],j);k++)
				f[j] = (f[j]+f[j-k])%mod;
	cout<<f[m]%mod;
	return 0;
} 