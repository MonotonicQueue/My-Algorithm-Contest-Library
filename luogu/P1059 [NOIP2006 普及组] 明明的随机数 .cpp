#include <bits/stdc++.h>
using namespace std;
int a[1100];
bool num[1100];
int main()
{
	int n,ans=0,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		if(!num[m])
		{
			num[m]=1;
			a[ans++]=m;
		}
	}
	sort(a,a+ans);
	cout<<ans<<"\n";
	for(int i=0;i<ans;i++)
		if(a[i]>0)
			cout<<a[i]<<" ";
	return 0;
}