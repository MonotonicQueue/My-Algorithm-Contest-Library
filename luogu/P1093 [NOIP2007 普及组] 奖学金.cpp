#include <bits/stdc++.h>
using namespace std;
int n;
struct stu
{
	int a,b,c,d,e;
}s[310];
int cmp(stu a,stu b)
{
	if(a.d!=b.d)
		return a.d>b.d;
	if(a.a!=b.a)
		return a.a>b.a;
	return a.e<b.e;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c;
		s[i].d=s[i].a+s[i].b+s[i].c;
		s[i].e=i;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=5;i++)
		cout<<s[i].e<<" "<<s[i].d<<endl;
	return 0;
}