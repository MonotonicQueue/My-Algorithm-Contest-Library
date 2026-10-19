#include<bits/stdc++.h>
using namespace std;
int n,ans,num[10]={6,2,5,5,4,5,6,3,7,6};
int hc(int b)
{
	if(b==0)
		return 6;
	int m=0,a=b;
	while(a)
	{
		m+=num[a%10];
		a/=10;
	}
	return m;
}
int main() 
{
	cin>>n;
	for(int i=0;i<=1111;i++)
		for(int j=0;j<=1111;j++)
			{
				if(hc(i)+hc(j)+hc(i+j)+4==n)
					ans++;
			}
	cout<<ans;
	return 0;
}