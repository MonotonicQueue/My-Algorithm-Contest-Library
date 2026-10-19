#include<bits/stdc++.h>
using namespace std;
int v[35],w[35],n,m,dp[31000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=m;i++)
		for(int j=n;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]*v[i]);
	printf("%d",dp[n]);
	return 0;
}