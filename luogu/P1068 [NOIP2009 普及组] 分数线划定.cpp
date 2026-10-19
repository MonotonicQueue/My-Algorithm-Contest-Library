#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int k,s;
}a[5100];
int cmp(node a,node b)
{
	if(a.s!=b.s)
		return a.s>b.s;
	return a.k<b.k;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].k>>a[i].s;
	sort(a+1,a+1+n,cmp);
	m=floor(m*1.5);
	while(a[m].s==a[m+1].s)
		m++;
	cout<<a[m].s<<" "<<m;
	for(int i=1;i<=m;i++)
		cout<<"\n"<<a[i].k<<" "<<a[i].s;
	return 0;
}