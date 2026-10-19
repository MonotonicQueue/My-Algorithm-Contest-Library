#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l=1,k,ans[100],a=1,b;
int main()
{
	int n,m;
	cin>>n>>m;
	while(l*2<=m){l*=2;k++;}
	for(int i=k;i>=0;i--)
	{
		if(m>=l)
		{
			m-=l;
			ans[i]++;
		}
		l/=2;
	}
	for(int i=0;i<=k;i++)
	{
		b+=a*ans[i];
		a*=n;
	}
	cout<<b;
    return 0;
}