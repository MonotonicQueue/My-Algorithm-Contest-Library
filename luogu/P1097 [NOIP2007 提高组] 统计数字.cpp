#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int sum=a[1],ans=1;
	printf("%d ",a[1]);
	for(int i=2;i<=n;i++)
	{
		if(sum!=a[i])
		{
			sum=a[i];
			printf("%d\n%d ",ans,a[i]);
			ans=1;
		}
		else
			ans++;
	}
	printf("%d",ans);
    return 0;
}