#include<bits/stdc++.h>
using namespace std;
int ans;
void pd(int a)
{
	while(a)
	{
		if(a%10==2)
			ans++;
		a/=10;
	}
}
int main()
{
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
		pd(i);
	printf("%d",ans);
    return 0;
}