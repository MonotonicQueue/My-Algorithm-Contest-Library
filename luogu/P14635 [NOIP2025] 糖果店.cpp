#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1e5+10;
int n;
ll m; 
struct node{
	ll x,y;
}a[N];
ll sum[N];
bool cmp(node x,node y){
	return x.x < y.x;
}
int main(){
	// freopen("candy.in","r",stdin);
	// freopen("candy.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		a[i].x = read();
		a[i].y = read();
	}
	sort(a+1,a+1+n,cmp);
	ll mn = a[1].x+a[1].y,ans = 0;
	for(int i=1;i<=n;i++){
		mn = min(mn,a[i].x+a[i].y);
	}
	ans = m/mn*2;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i].x;
		if(sum[i] > m) break;
		ll now = i,r = m-sum[i];
		now += r/mn*2;
		ans = max(ans,now);
	}
	cout << ans;
	return 0;
}
