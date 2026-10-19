#include<iostream>
using namespace std;
int a[10001],b[10001],g[10001],k[10001],n,i,j,d,x,y;
int main()
{
	cin>>n;
	for(d=1;d<=n;d++)
		cin>>a[d]>>b[d]>>g[d]>>k[d];
	cin>>x>>y;
	for(d=n;d>=1;d--)
		if(x>=a[d]&&x<=g[d]+a[d]&&y>=b[d]&&y<=k[d]+b[d])
		{
			cout<<d;
			return 0;
		}
	cout<<"-1";
	return 0;
}