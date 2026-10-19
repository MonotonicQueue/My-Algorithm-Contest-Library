#include<bits/stdc++.h>
using namespace std;
int ans,w,n;
int main()
{
	cin>>w>>n;
	int P[n+5];
	for(int i=1;i<=n;i++)
		cin>>P[i];
	sort(P+1,P+1+n);
	for(int i=1,j=n;i<j;)
	{
		if(P[i]+P[j]<=w)
			ans++,i++,j--;
		else
			j--;
	}
	cout<<n-ans;
	return 0;
}