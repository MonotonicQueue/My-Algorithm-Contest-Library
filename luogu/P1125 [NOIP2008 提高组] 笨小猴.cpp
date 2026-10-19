#include<bits/stdc++.h>
using namespace std;
int b[30],c=0,d=0,e;
int f(int a)
{
	if(a==1||a==0)
		return 0;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int i=1;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		b[a[i]-'a'+1]++;
	}
	sort(b+1,b+27);
	c=b[26];
	while(!b[i]) i++;
	d=b[i];
	e=c-d;
	if(f(e))
		cout<<"Lucky Word"<<endl<<e;
	else
		cout<<"No Answer\n0";
}