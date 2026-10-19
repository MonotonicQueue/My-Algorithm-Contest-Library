#include<bits/stdc++.h>
using namespace std;
int t[110],f[110],g[110];
int main(){
	int n,k,ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> t[i];
	for(int i=1;i<=n;i++) f[i] = 1,g[i] = 1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(t[i] > t[j])
				f[i] = max(f[i],f[j]+1);
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			if(t[i] > t[j])
				g[i] = max(g[i],g[j]+1);
	for(int i=1;i<=n;i++)
		ans = max(ans,f[i]+g[i]-1);
	cout << n-ans;
	return 0;
}