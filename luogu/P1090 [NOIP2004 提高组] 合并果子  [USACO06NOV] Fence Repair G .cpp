#include<bits/stdc++.h>
using namespace std;
int n,a[11000];
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		a[i+1]+=a[i];
		ans+=a[i+1];
		for(int j=i+1;j<=n-1;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
			else
				break;
		}
	}
	cout<<ans;
	return 0;
}