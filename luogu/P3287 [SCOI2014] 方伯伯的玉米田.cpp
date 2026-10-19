#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
const int N = 1e4+10;
const int M = 5510;
int n,k,a[N],f[510][M],ans;
int lowbit(int x){
	return x & -x;
}
void change(int x,int y,int d){
	for(int i=x;i<=k+1;i+=lowbit(i))
		for(int j=y;j<=5500;j+=lowbit(j))
			f[i][j] = max(f[i][j],d);
}
int query(int x,int y){
	int res = 0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			res = max(f[i][j],res);
	return res;
}
signed main(){
	n = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++)
		for(int j=k;j>=0;j--){
			int d = query(j+1,a[i]+j)+1;
			ans = max(ans,d);
			change(j+1,a[i]+j,d);
		}
	cout << ans;
	return 0;
}