#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}//快读 
const int N = 510;
int n,k;
struct node{
	ll x, y;
}a[N];
ll f(node x,node y){
	return y.x-x.x+y.y-x.y;
}
bool cmp(node x,node y){
	if(x.x == y.x) return x.y < y.y;
	return x.x <y.x;
}
ll dp[N][N],ans=1;
int main(){
	//freopen("point.in","r",stdin);
	//freopen("point.out","w",stdout);
	n = read(); k = read();
	for(int i=1;i<=n;i++)
		a[i].x = read(),a[i].y = read();
	sort(a+1,a+1+n,cmp);
	dp[1][0] = 1;
	for(int i=2;i<=n;i++){
		dp[i][0] = 1;
		for(int l=0;l<=k;l++)
		for(int j=1;j<i;j++){
			if(a[i].y < a[j].y) continue;
			ll d = f(a[j],a[i])-1;
			if(l+d>k) continue;
			dp[i][l+d] = max(dp[i][l+d],dp[j][l]+d+1);
			ans = max(ans,dp[i][l+d]+k-l-d);
		}
	}
	cout << ans;
	return 0;
}