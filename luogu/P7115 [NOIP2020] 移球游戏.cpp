#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 55;
const int M = 410;
int n,m;
int a[N][M],top[N],p[N];
vector<pii> ans;
void move(int x,int y){
	ans.emplace_back(x,y);
//	cout << x << " " << y << "\n";
	assert(top[x] >= 1);
	a[y][++top[y]] = a[x][top[x]];
	a[x][top[x]--] = 0;
}
bool flag[N];
void solve(int l,int r){
	if(l == r) return ;
	int mid = (l+r) >> 1;
	for(int i=l;i<=r;i++) flag[i] = 0;
	for(int I=l;I<=mid;I++) for(int J=mid+1;J<=r;J++){
		if(flag[I] || flag[J]) continue;
		int i = p[I],j = p[J],q = p[n+1];
		int sum = 0;
		for(int k=1;k<=m;k++) sum += a[i][k] <= mid;
		for(int k=1;k<=m;k++) sum += a[j][k] <= mid;
		if(sum >= m){
			sum = 0;
			for(int k=1;k<=m;k++) sum += a[i][k] <= mid;
			for(int k=1;k<=m-sum;k++) move(j,q);
			for(int k=m;k;k--)
				if(a[i][k] <= mid) move(i,q);
				else move(i,j);
			for(int k=1;k<=sum;k++) move(q,i);
			for(int k=1;k<=m-sum;k++) move(j,i);
			while(top[q]) move(q,j);
			for(int k=1;k<=m-sum;k++) move(i,q);
			for(int k=m;k;k--)
				if(a[j][k] <= mid&&top[i]<m) move(j,i);
				else move(j,q);
			swap(p[J],p[n+1]);
			flag[I] = true;
		}else{
			sum = 0;
			for(int k=1;k<=m;k++) sum += a[j][k] > mid;
			for(int k=1;k<=m-sum;k++) move(i,q);
			for(int k=m;k;k--)
				if(a[j][k] > mid) move(j,q);
				else move(j,i);
			for(int k=1;k<=sum;k++) move(q,j);
			for(int k=1;k<=m-sum;k++) move(i,j);
			while(top[q]) move(q,i);
			for(int k=1;k<=m-sum;k++) move(j,q);
			for(int k=m;k;k--)
				if(a[i][k] > mid&&top[j]<m) move(i,j);
				else move(i,q);
			swap(p[I],p[n+1]);
			flag[J] = true;
		}
	}
	solve(l,mid); solve(mid+1,r);
}
int main(){
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=n+1;i++) p[i] = i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) a[i][j] = read();
		top[i] = m;
	}
	solve(1,n);
	cout << ans.size() << "\n";
	for(auto it : ans) cout << it.fi << " " << it.se << "\n";
	return 0;
}