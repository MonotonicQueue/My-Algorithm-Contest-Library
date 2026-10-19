#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p1,p2,p3;
	string a;
	cin>>p1>>p2>>p3>>a;
	int len=a.size()-1;
	for(int i=0;i<=len;i++)
	{
		if(a[i]=='-'&&i==0)
			cout<<"-";
		else if(a[i]!='-')
			cout<<a[i];
		else
		{
			if((a[i-1]>=a[i+1])||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='a'&&a[i+1]<='z')^a[i-1]=='-'^a[i+1]=='-')
				cout<<a[i];
			else if(a[i-1]==a[i+1]-1)
				continue;
			else
			{
				if(p1==1)
				{
					if(p3==1)
					{
						for(int j=a[i-1]+1;j<a[i+1];j++)
						{
							for(int k=1;k<=p2;k++)
							{
									cout<<char(j);
							}
						}
					}
					else
					{
						for(int j=a[i+1]-1;j>=a[i-1]+1;j--)
						{
							for(int k=1;k<=p2;k++)
							{
									cout<<char(j);
							}
						}
					}
				}
				else if(p1==2)
				{
					if(p3==1)
					{
						for(int j=a[i-1]+1;j<a[i+1];j++)
						{
							for(int k=1;k<=p2;k++)
							{
								if(j>='a'&&j<='b')
									cout<<char(j-'a'+'A');
								else
									cout<<char(j);
							}
						}
					}
					else
					{
						for(int j=a[i+1]-1;j>=a[i-1]+1;j--)
						{
							for(int k=1;k<=p2;k++)
							{
								if(j>='a'&&j<='z')
									cout<<char(j-'a'+'A');
								else
									cout<<char(j);
							}
						}
					}
				}
				else if(p1==3)
				{
					if(p3==1)
					{
						for(int j=a[i-1]+1;j<a[i+1];j++)
						{
							for(int k=1;k<=p2;k++)
							{
								cout<<"*";
							}
						}
					}
					else
					{
						for(int j=a[i+1]-1;j>=a[i-1]+1;j--)
						{
							for(int k=1;k<=p2;k++)
							{
								cout<<"*";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}