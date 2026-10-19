#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,top,ans=0,now_i,now_j,now_top=1;
struct node
{
	ll i,j,q;
}t[450];
bool cmp(node a,node b)
{
	return a.q>b.q;
}
ll running(ll i,ll j)
{
	return abs(now_i-i)+abs(now_j-j);
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>t[++top].q;
			t[top].i=i;
			t[top].j=j;
		}
	sort(t+1,t+1+top,cmp);
	now_j=t[1].j;
	while(k&&now_top<=top)
	{
		int run=running(t[now_top].i,t[now_top].j)+1;
		if(run+t[now_top].i<=k)
		{
			k-=run;
			now_i=t[now_top].i;
			now_j=t[now_top].j;
			ans+=t[now_top].q;
			now_top++;
		}
		else
			break;
	}
	cout<<ans;
    return 0;
}
