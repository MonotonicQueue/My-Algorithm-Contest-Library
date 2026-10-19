#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,len,maxn;
char tr[5000];
string t;
char pd(int l,int r)
{
	bool b=0,i=0;
	for(int j=l;j<=r;j++)
	{
		if(t[j]=='1')
			i=1;
		if(t[j]=='0')
			b=1;
		if(i==1&&b==1)
			return 'F';
	}
	if(i==1&&b==0)
		return 'I';
	if(b==1&&i==0)
		return 'B';
}
void maketree(int l,int r,int f)
{
	if(f>maxn)
		return;
	if(l>r)
		return;
	tr[f]=pd(l,r);
	int mid=(l+r)/2;
	maketree(l,mid,2*f);
	maketree(mid+1,r,2*f+1);
}
void couttree(int f)
{
	if(f>maxn)
		return;
	couttree(2*f);
	couttree(2*f+1);
	cout<<tr[f];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>t;
	maxn=pow(2,n+1)-1;
	t=' '+t;
	len=t.size()-1;
	maketree(1,len,1);
	couttree(1);
	return 0;
}