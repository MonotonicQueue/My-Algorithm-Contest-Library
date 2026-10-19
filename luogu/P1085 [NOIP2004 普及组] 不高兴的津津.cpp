#include<bits/stdc++.h>
using namespace std;
struct pppp
{
	int a,b;
}c[20];
int cmp(pppp a,pppp b)
{
	return a.a>b.a;
}
int main(){
	int a[20],b[20];
	for(int i=1;i<=7;i++)
	{
		cin>>a[i]>>b[i];
		c[i].a=a[i]+b[i];
		c[i].b=i;
	}
	sort(c+1,c+8,cmp);
	cout<<c[1].b;
	return 0;
}