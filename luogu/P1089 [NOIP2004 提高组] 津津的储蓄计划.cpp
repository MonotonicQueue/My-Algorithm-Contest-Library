#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[12],n,b=0;
	double c=0;
	for(int i=1;i<=12;i++)
		cin>>a[i];
	for(int i=1;i<=12;i++)
	{
		b+=300;
		b-=a[i];
		if(b>=100)
		{
			c+=b/100;
			b%=100;
		}
		if(b<0)
		{
			cout<<-i;
			return 0;
		}
	}
	cout<<b+1.2*100*c;
    return 0;
}