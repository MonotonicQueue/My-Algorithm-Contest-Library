#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[20],q=0,p=0;
	string b;
	cin>>b;
	for(int i=0;i<b.size();i++)
	if(b[i]!='-')
	a[q++]=b[i]-'0';
	for(int i=0;i<9;i++)
	p+=a[i]*(i+1);
	p%=11;
	if(p==a[9]||(p==10&&b[12]=='X'))
	cout<<"Right";
	else
	{
		for(int i=0;i<b.size()-1;i++)
		cout<<b[i];
		if(p!=10)
		cout<<p;
		else
		cout<<"X";
	}
	return 0;
}