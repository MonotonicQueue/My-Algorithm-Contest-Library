#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){r = -1; ch = getchar();}
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 5e5+10;
int n,k,L,R;
int a[N],sum[N];
int s[N][25];
void st_pre(){
	int t = log(n)/log(2)+1;
	for(int i=1;i<=n;i++) s[i][0] = i;
	for(int i=1;i<t;i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			int x = s[j][i-1],y = s[j+(1<<(i-1))][i-1];
			s[j][i] = sum[x] > sum[y] ? x : y;
		}
}
int st_query(int l,int r){
	int k = log(r-l+1)/log(2);
	int x = s[l][k],y = s[r-(1<<k)+1][k];
	return sum[x] > sum[y] ? x : y;
}
struct node{
	int p,l,r,t;
	node(){}
	node(int p,int l,int r): p(p),l(l),r(r),t(st_query(l,r)){}
};
bool operator<(node x,node y){
	return sum[x.t]-sum[x.p-1] < sum[y.t]-sum[y.p-1];
}
priority_queue<node>q;
int main(){
	n = read(); k = read();
	L = read(); R = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	st_pre();
	for(int i=1;i+L-1<=n;i++)
		q.push(node(i,i+L-1,min(i+R-1,n)));
	ll ans = 0;
	while(k--){
		node x = q.top(); q.pop();
		ans += sum[x.t]-sum[x.p-1];
		if(x.t != x.l) q.push(node(x.p,x.l,x.t-1));
		if(x.t != x.r) q.push(node(x.p,x.t+1,x.r));
	}
	cout << ans;
	return 0;
}