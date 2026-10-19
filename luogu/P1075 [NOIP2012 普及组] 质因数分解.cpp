#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b[10100],c,j=2;
	cin>>a;
	for(int i=2;i*i<a;i++)
	{
		if(a%i==0)
		{
			cout<<a/i;
			break;
		}
	}
    return 0;
}